#ifndef Vehicle_HPP
#define Vehicle_HPP

#include <iostream>
#include <string>

#include "VehicleCategory.hpp"

class Vehicle
{
    VehicleCategory vehicleCategory;
    string vehicleNumber;

public:
    Vehicle(VehicleCategory vehicleCategory, string vehicleNumber) : vehicleNumber(vehicleNumber), vehicleCategory(vehicleCategory) {}

    VehicleCategory getVehicleCategory() { return vehicleCategory; }
    string getVehicleNumber() { return vehicleNumber; }
};

#endif