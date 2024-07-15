#include <bits/stdc++.h>
using namespace std;

// Forward declaration
class ElevatorManager;

// Elevator Class
class Elevator
{
public:
    int current_floor;
    bool moving_up;
    bool doors_open;
    vector<int> destination_floors;

    Elevator() : current_floor(0), moving_up(true), doors_open(false) {}

    void move_to_floor(int floor)
    {
        current_floor = floor;
        open_doors();
        close_doors();
    }

    void open_doors()
    {
        doors_open = true;
        cout << "Doors opened at floor " << current_floor << endl;
    }

    void close_doors()
    {
        doors_open = false;
        cout << "Doors closed at floor " << current_floor << endl;
    }

    void add_destination(int floor)
    {
        if (find(destination_floors.begin(), destination_floors.end(), floor) == destination_floors.end())
        {
            destination_floors.push_back(floor);
        }
    }

    bool update()
    {
        if (!destination_floors.empty())
        {
            int next_floor = destination_floors.front();
            destination_floors.erase(destination_floors.begin());
            cout << "Currently at floor: " << next_floor << endl;
            move_to_floor(next_floor);
            return true;
        }
        return false;
    }
};

// ExternalPanel Class
class ExternalPanel
{
public:
    int floor;
    ElevatorManager *manager;

    ExternalPanel(int floor, ElevatorManager *manager) : floor(floor), manager(manager) {}

    void request_elevator_up();
    void request_elevator_down();
};

// InternalPanel Class
class InternalPanel
{
public:
    Elevator *elevator;

    InternalPanel(Elevator *elevator) : elevator(elevator) {}

    void select_floor(int floor)
    {
        elevator->add_destination(floor);
    }
};

// ElevatorManager Class
class ElevatorManager
{
public:
    Elevator elevator;
    vector<ExternalPanel> external_panels;
    InternalPanel internal_panel;

    ElevatorManager(int num_floors) : internal_panel(&elevator)
    {
        for (int i = 0; i < num_floors; ++i)
        {
            external_panels.emplace_back(i, this);
        }
    }

    void process_external_request(int floor, bool going_up)
    {
        elevator.add_destination(floor);
    }

    void process_internal_request(int floor)
    {
        elevator.add_destination(floor);
    }

    void run()
    {
        while (true)
        {
            int flag = elevator.update();
            if (flag == false)
                break;
            // Add a delay or condition to break the loop as necessary
        }
    }
};

// ExternalPanel member functions
void ExternalPanel::request_elevator_up()
{
    manager->process_external_request(floor, true);
}

void ExternalPanel::request_elevator_down()
{
    manager->process_external_request(floor, false);
}

// Main function to test the implementation
int main()
{
    ElevatorManager manager(10); // Assuming a 10-floor building

    // Simulating some requests
    manager.external_panels[0].request_elevator_up();
    manager.external_panels[5].request_elevator_down();
    manager.internal_panel.select_floor(8);

    // Running the elevator system
    manager.run();

    return 0;
}
