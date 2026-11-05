
/*
  COMSC-210 Data Structures
  Lab 33: Toll Plaza
  Milestone 5
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

const int PAY_CHANCE = 46;
const int JOIN_CHANCE = 39;
const int SWITCH_CHANCE = 15;
const int EMPTY_JOIN_CHANCE = 50;

// Display the cars in all four lanes
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

    // Create an array of four deques
    deque<Car> lanes[NUM_LANES];

    // Add two cars to each lane
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < INITIAL_CARS; j++) {
            Car newCar;
            lanes[i].push_back(newCar);
        }
    }

    // Display the initial queues
    cout << "Initial queue:\n";

    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << ":\n";

        for (Car &car : lanes[i]) {
            cout << "    ";
            car.print();
        }
    }

    // Run the simulation for 20 time periods
    for (int timePeriod = 1;
         timePeriod <= SIMULATION_TIME;
         timePeriod++) {

        cout << "\nTime: " << timePeriod << endl;

        // Perform an operation in every lane
        for (int i = 0; i < NUM_LANES; i++) {

            cout << "Lane: " << i + 1 << " ";

            // Empty lane: 50% join, 50% no arrival
            if (lanes[i].empty()) {
                int chance = rand() % 100 + 1;

                if (chance <= EMPTY_JOIN_CHANCE) {
                    Car newCar;
                    lanes[i].push_back(newCar);

                    cout << "Joined: ";
                    lanes[i].back().print();
                } else {
                    cout << "No car arrived\n";
                }

                continue;
            }

            // Random number between 1 and 100
            int chance = rand() % 100 + 1;

            if (chance <= PAY_CHANCE) {
                // 46% chance: car pays and leaves
                cout << "Paid: ";
                lanes[i].front().print();

                lanes[i].pop_front();

            } else if (chance <= PAY_CHANCE + JOIN_CHANCE) {
                // 39% chance: new car joins
                Car newCar;
                lanes[i].push_back(newCar);

                cout << "Joined: ";
                lanes[i].back().print();

            } else if (chance <= PAY_CHANCE + JOIN_CHANCE + SWITCH_CHANCE) {
                // 15% chance: last car switches lanes

                // Select a different destination lane
                int offset = rand() % (NUM_LANES - 1) + 1;
                int newLane = (i + offset) % NUM_LANES;

                // Get the car at the back of the lane
                Car switchingCar = lanes[i].back();

                cout << "Switched: ";
                switchingCar.print();

                // Remove it from the original lane
                lanes[i].pop_back();

                // Add it to the new lane
                lanes[newLane].push_back(switchingCar);
            }
        }

        // Display queues after all lane operations
        displayPlaza(lanes);
    }

    return 0;
}
