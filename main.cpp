
/*
  COMSC-210 Data Structures
  Lab 33: Toll Plaza
  Milestone 4
*/

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int NUM_LANES = 4;
const int INITIAL_CARS = 2;
const int SIMULATION_TIME = 20;
const int PAY_CHANCE = 50;

// Display all four toll booth queues
void displayPlaza(deque<Car> lanes[]) {
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << " Queue:";

        if (lanes[i].empty()) {
            cout << " empty\n";
        } else {
            cout << endl;

            for (Car &car : lanes[i]) {
                cout << "    ";
                car.print();
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Create four lanes
    deque<Car> lanes[NUM_LANES];

    // Add two cars to each lane
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < INITIAL_CARS; j++) {
            Car newCar;
            lanes[i].push_back(newCar);
        }
    }

    // Print the initial queues
    cout << "Initial queue:\n";
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << ":\n";

        for (Car &car : lanes[i]) {
            cout << "    ";
            car.print();
        }
    }

    // Simulate 20 time periods
    for (int timePeriod = 1;
         timePeriod <= SIMULATION_TIME;
         timePeriod++) {

        cout << "\nTime: " << timePeriod << endl;

        // Process each lane
        for (int i = 0; i < NUM_LANES; i++) {
            int chance = rand() % 100 + 1;

            cout << "Lane: " << i + 1 << " ";

            if (chance <= PAY_CHANCE && !lanes[i].empty()) {
                // First car pays and leaves
                cout << "Paid: ";
                lanes[i].front().print();
                lanes[i].pop_front();
            } else {
                // A new car joins the lane
                Car newCar;
                lanes[i].push_back(newCar);

                cout << "Joined: ";
                lanes[i].back().print();
            }
        }

        // Print all queues after operations
        displayPlaza(lanes);
    }

    return 0;
}
