#ifndef ParkingFloor_HPP
#define ParkingFloor_HPP

#include <bits/stdc++.h>
using namespace std;

#include "ParkingSlot.hpp"
#include "Vehicle.hpp"
#include "ParkingSlotType.hpp"
#include "VehicleCategory.hpp"

class ParkingFloor
{
public:
    string name;
    unordered_map<ParkingSlotType, unordered_map<string, ParkingSlot *>> parkingSlots;

    ParkingFloor(const string &name, const unordered_map<ParkingSlotType, unordered_map<string, ParkingSlot *>> &parkingSlots)
        : name(name), parkingSlots(parkingSlots) {}

    ParkingSlot *getRelevantSlotForVehicleAndPark(Vehicle *vehicle)
    {
        VehicleCategory vehicleCategory = vehicle->getVehicleCategory();
        ParkingSlotType parkingSlotType = pickCorrectSlot(vehicleCategory);
        auto relevantParkingSlot = parkingSlots[parkingSlotType];
        ParkingSlot *slot = NULL;

        for (auto m : relevantParkingSlot)
        {
            if (m.second->isAvailableSlot())
            {
                slot = m.second;
                slot->addVehicle(vehicle);
                break;
            }
        }

        return slot;
    }

private:
    ParkingSlotType pickCorrectSlot(VehicleCategory vehicleCategory)
    {
        if (vehicleCategory == VehicleCategory::TwoWheeler)
            return ParkingSlotType::TwoWheeler;
        else if (vehicleCategory == VehicleCategory::Hatchback || vehicleCategory == VehicleCategory::Sedan)
            return ParkingSlotType::Compact;
        else if (vehicleCategory == VehicleCategory::SUV)
            return ParkingSlotType::Medium;
        else if (vehicleCategory == VehicleCategory::Bus)
            return ParkingSlotType::Large;

        return ParkingSlotType::None; // Or handle an invalid case appropriately
    }
};

#endif
