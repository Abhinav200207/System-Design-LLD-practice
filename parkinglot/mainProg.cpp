#include <bits/stdc++.h>
using namespace std;

#include "ParkingSlot.hpp"
#include "ParkingFloor.hpp"
#include "ParkingLot.hpp"
#include "Vehicle.hpp"
#include "Ticket.hpp"

int main()
{
    string nameOfParkingLot = "Pintosss Parking Lot";

    unordered_map<ParkingSlotType, unordered_map<string, ParkingSlot *>> allSlots;
    unordered_map<string, ParkingSlot *> compactSlot;
    compactSlot["C1"] = new ParkingSlot("C1", ParkingSlotType::Compact);
    compactSlot["C2"] = new ParkingSlot("C2", ParkingSlotType::Compact);
    compactSlot["C3"] = new ParkingSlot("C3", ParkingSlotType::Compact);
    allSlots[ParkingSlotType::Compact] = compactSlot;

    unordered_map<string, ParkingSlot *> largeSlot;
    largeSlot["L1"] = new ParkingSlot("L1", ParkingSlotType::Large);
    largeSlot["L2"] = new ParkingSlot("L2", ParkingSlotType::Large);
    largeSlot["L3"] = new ParkingSlot("L3", ParkingSlotType::Large);
    allSlots[ParkingSlotType::Large] = largeSlot;

    ParkingFloor *parkingFloor = new ParkingFloor("1", allSlots);
    vector<ParkingFloor *> parkingFloors;
    parkingFloors.push_back(parkingFloor);
    ParkingLot *parkingLot = ParkingLot::getInstance(nameOfParkingLot, parkingFloors);

    Vehicle *vehicle = new Vehicle(VehicleCategory::Hatchback, "KA-01-MA-9999");

    Ticket *ticket = (Ticket *)parkingLot->assignTicket(vehicle, 1);
    cout << " ticket number >> " << ticket->getTicketNumber() << endl;
    // persist the ticket to db here

    this_thread::sleep_for(chrono::seconds(10));
    double price = parkingLot->scanAndPay(ticket, 5);
    cout << "price is >>" << price << endl;

    return 0;
}
