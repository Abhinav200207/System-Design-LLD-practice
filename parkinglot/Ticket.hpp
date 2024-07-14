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
        Ticket *ticket;
        ticket->parkingSlot = parkingSlot;
        ticket->startTime = inTime;
        ticket->vehicle = vehicle;
        ticket->ticketNumber = vehicle->getVehicleNumber() + to_string(inTime);
        return ticket;
    }
    string getTicketNumber()
    {
        return ticketNumber;
    }
    int getStartTime()
    {
        return startTime;
    }
    ParkingSlot *getParkingSlot()
    {
        return parkingSlot;
    }
    Vehicle *getVehicle()
    {
        return vehicle;
    }
};

#endif
