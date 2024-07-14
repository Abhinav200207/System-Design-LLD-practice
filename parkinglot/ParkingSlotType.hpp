#ifndef ParkingSlotType_HPP
#define ParkingSlotType_HPP

#include <iostream>

enum class ParkingSlotType
{
    TwoWheeler,
    Compact,
    Medium,
    Large,
    None
};

#endif

#ifndef ParkingSlotTypeHelper_HPP
#define ParkingSlotTypeHelper_HPP

class ParkingSlotTypeHelper
{
public:
    static double getPriceForParking(ParkingSlotType type, long duration)
    {
        switch (type)
        {
        case ParkingSlotType::TwoWheeler:
            return duration * 0.05;
        case ParkingSlotType::Compact:
            return duration * 0.075;
        case ParkingSlotType::Medium:
            return duration * 0.09;
        case ParkingSlotType::Large:
            return duration * 0.10;
        default:
            return 0.0;
        }
    }
};

#endif
