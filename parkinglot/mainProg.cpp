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

    // Creating slots for floor 1
    unordered_map<ParkingSlotType, unordered_map<string, ParkingSlot *>> allSlots1;
    unordered_map<string, ParkingSlot *> compactSlot1;
    compactSlot1["C1"] = new ParkingSlot("C1", ParkingSlotType::Compact);
    compactSlot1["C2"] = new ParkingSlot("C2", ParkingSlotType::Compact);
    compactSlot1["C3"] = new ParkingSlot("C3", ParkingSlotType::Compact);
    allSlots1[ParkingSlotType::Compact] = compactSlot1;

    unordered_map<string, ParkingSlot *> largeSlot1;
    largeSlot1["L1"] = new ParkingSlot("L1", ParkingSlotType::Large);
    largeSlot1["L2"] = new ParkingSlot("L2", ParkingSlotType::Large);
    largeSlot1["L3"] = new ParkingSlot("L3", ParkingSlotType::Large);
    allSlots1[ParkingSlotType::Large] = largeSlot1;

    ParkingFloor *parkingFloor1 = new ParkingFloor("1", allSlots1); // <----- Created floor 1

    // Creating slots for floor 2
    unordered_map<ParkingSlotType, unordered_map<string, ParkingSlot *>> allSlots2;
    unordered_map<string, ParkingSlot *> compactSlot2;
    compactSlot2["C4"] = new ParkingSlot("C4", ParkingSlotType::Compact);
    compactSlot2["C5"] = new ParkingSlot("C5", ParkingSlotType::Compact);
    compactSlot2["C6"] = new ParkingSlot("C6", ParkingSlotType::Compact);
    allSlots2[ParkingSlotType::Compact] = compactSlot2;

    unordered_map<string, ParkingSlot *> largeSlot2;
    largeSlot2["L4"] = new ParkingSlot("L4", ParkingSlotType::Large);
    largeSlot2["L5"] = new ParkingSlot("L5", ParkingSlotType::Large);
    largeSlot2["L6"] = new ParkingSlot("L6", ParkingSlotType::Large);
    allSlots2[ParkingSlotType::Large] = largeSlot2;

    ParkingFloor *parkingFloor2 = new ParkingFloor("2", allSlots2); // <----- Created floor 2

    // Creating slots for floor 3
    unordered_map<ParkingSlotType, unordered_map<string, ParkingSlot *>> allSlots3;
    unordered_map<string, ParkingSlot *> compactSlot3;
    compactSlot3["C7"] = new ParkingSlot("C7", ParkingSlotType::Compact);
    compactSlot3["C8"] = new ParkingSlot("C8", ParkingSlotType::Compact);
    compactSlot3["C9"] = new ParkingSlot("C9", ParkingSlotType::Compact);
    allSlots3[ParkingSlotType::Compact] = compactSlot3;

    unordered_map<string, ParkingSlot *> largeSlot3;
    largeSlot3["L7"] = new ParkingSlot("L7", ParkingSlotType::Large);
    largeSlot3["L8"] = new ParkingSlot("L8", ParkingSlotType::Large);
    largeSlot3["L9"] = new ParkingSlot("L9", ParkingSlotType::Large);
    allSlots3[ParkingSlotType::Large] = largeSlot3;

    ParkingFloor *parkingFloor3 = new ParkingFloor("3", allSlots3); // <----- Created floor 3

    vector<ParkingFloor *> parkingFloors;
    parkingFloors.push_back(parkingFloor1);
    parkingFloors.push_back(parkingFloor2); // <----- Added floor 2 to the parking lot
    parkingFloors.push_back(parkingFloor3); // <----- Added floor 3 to the parking lot

    ParkingLot *parkingLot = ParkingLot::getInstance(nameOfParkingLot, parkingFloors);

    Vehicle *vehicle = new Vehicle(VehicleCategory::Hatchback, "KA-01-MA-9999");

    Ticket *ticket = (Ticket *)parkingLot->assignTicket(vehicle, 1);
    cout << "Ticket number >> " << ticket->getTicketNumber() << endl;

    double price = parkingLot->scanAndPay(ticket, 5);
    cout << "Price is >> " << price << endl;

    cout << endl;
    cout << endl;

    Vehicle *vehicle1 = new Vehicle(VehicleCategory::Hatchback, "KA-01-MA-9053");

    Ticket *ticket1 = (Ticket *)parkingLot->assignTicket(vehicle1, 3);
    cout << "Ticket number >> " << ticket1->getTicketNumber() << endl;

    double price1 = parkingLot->scanAndPay(ticket1, 50);
    cout << "Price is >> " << price1 << endl;

    return 0;
}
