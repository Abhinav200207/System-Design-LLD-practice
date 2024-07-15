#ifndef Ticket_HPP
#define Ticket_HPP

#include <bits/stdc++.h>
using namespace std;

#include "Vehicle.hpp"
#include "ParkingSlot.hpp"

class Ticket
{
    string ticketNumber;
    int startTime;
    Vehicle *vehicle;
    ParkingSlot *parkingSlot;

public:
    static Ticket *createTicket(Vehicle *vehicle, ParkingSlot *parkingSlot, int inTime)
    {
        Ticket *ticket = new Ticket(); // Correctly create a new Ticket object
        ticket->parkingSlot = parkingSlot;
        ticket->startTime = inTime;
        ticket->vehicle = vehicle;
        ticket->ticketNumber = vehicle->getVehicleNumber() + to_string(inTime);
        return ticket;
    }

    string getTicketNumber() const
    {
        return ticketNumber;
    }

    int getStartTime() const
    {
        return startTime;
    }

    ParkingSlot *getParkingSlot() const
    {
        return parkingSlot;
    }

    Vehicle *getVehicle() const
    {
        return vehicle;
    }
};

#endif
