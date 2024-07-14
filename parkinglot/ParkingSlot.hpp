#ifndef ParkingSlot_HPP
#define ParkingSlot_HPP

#include <bits/stdc++.h>
using namespace std;

#include "Vehicle.hpp"
#include "ParkingSlotType.hpp"

class ParkingSlot
{
public:
    string name;
    bool isAvailable;
    Vehicle *vehicle;
    ParkingSlotType parkingSlotType;

    ParkingSlot(const string &name, const ParkingSlotType &parkingSlotType)
        : name(name), isAvailable(true), vehicle(), parkingSlotType(parkingSlotType) {}

    void addVehicle(Vehicle *vehicle)
    {
        this->vehicle = vehicle;
        this->isAvailable = false;
    }

    void removeVehicle()
    {
        this->vehicle = NULL;
        this->isAvailable = true;
    }

    bool isAvailableSlot() const
    {
        return isAvailable;
    }

    ParkingSlotType getParkingSlotType()
    {
        return parkingSlotType;
    }
};


#endif
