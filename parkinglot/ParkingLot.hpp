#include <bits/stdc++.h>
using namespace std;

#include "ParkingSlot.hpp"
#include "ParkingFloor.hpp"
#include "Vehicle.hpp"
#include "Ticket.hpp"

class ParkingLot
{
private:
    string nameOfParkingLot;
    vector<ParkingFloor *> parkingFloors;
    static ParkingLot *parkingLot;

    ParkingLot(const string &nameOfParkingLot, const vector<ParkingFloor *> &parkingFloors)
        : nameOfParkingLot(nameOfParkingLot), parkingFloors(parkingFloors) {}

public:
    static ParkingLot *getInstance(const string &nameOfParkingLot, const vector<ParkingFloor *> &parkingFloors)
    {
        if (parkingLot == NULL)
        {
            parkingLot = new ParkingLot(nameOfParkingLot, parkingFloors);
        }
        return parkingLot;
    }

    const string &getNameOfParkingLot() const { return nameOfParkingLot; }
    void setNameOfParkingLot(const string &nameOfParkingLot) { this->nameOfParkingLot = nameOfParkingLot; }

    const vector<ParkingFloor *> &getParkingFloors() const { return parkingFloors; }
    void setParkingFloors(const vector<ParkingFloor *> &parkingFloors) { this->parkingFloors = parkingFloors; }

    void addFloors(const string &name, const unordered_map<ParkingSlotType, unordered_map<string, ParkingSlot *>> &parkSlots)
    {
        ParkingFloor *parkingFloor = new ParkingFloor(name, parkSlots);
        parkingFloors.push_back(parkingFloor);
    }

    Ticket *assignTicket(Vehicle *vehicle, int inTime)
    {
        ParkingSlot *parkingSlot = getParkingSlotForVehicleAndPark(vehicle);
        if (parkingSlot == NULL)
            return new Ticket(); // Return an empty Ticket if no slot is available
        Ticket *parkingTicket = createTicketForSlot(parkingSlot, vehicle, inTime);
        // Persist ticket to database
        return parkingTicket;
    }

    double scanAndPay(Ticket *ticket, int currTime)
    {
        long duration = currTime - ticket->getStartTime();
        ticket->getParkingSlot()->removeVehicle();
        ParkingSlotType type = ticket->getParkingSlot()->getParkingSlotType();
        double price = ParkingSlotTypeHelper::getPriceForParking(type, duration);
        // Persist record to database
        return price;
    }

private:
    Ticket *createTicketForSlot(ParkingSlot *parkingSlot, Vehicle *vehicle, int inTime)
    {
        return Ticket::createTicket(vehicle, parkingSlot, inTime);
    }

    ParkingSlot *getParkingSlotForVehicleAndPark(Vehicle *vehicle)
    {
        ParkingSlot *parkingSlot = NULL;
        for (auto floor : parkingFloors)
        {
            parkingSlot = floor->getRelevantSlotForVehicleAndPark(vehicle);
            if (parkingSlot != NULL)
                break;
        }
        return parkingSlot;
    }
};

// Initialize static member
ParkingLot *ParkingLot::parkingLot = NULL;
