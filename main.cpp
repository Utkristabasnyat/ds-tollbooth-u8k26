
/*
  COMSC-210 Data Structures
  Lab 32: Toll Booth Simulation
  Milestone 2
*/

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int INITIAL_CARS = 2;

// Display all cars currently waiting in line
void displayQueue(deque<Car> &tollLane) {
    cout << "Queue:\n";

    if (tollLane.empty()) {
        cout << "    Empty\n";
        return;
    }

    for (Car &car : tollLane) {
        cout << "    ";
        car.print();
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Create the toll booth lane
    deque<Car> tollLane;

    // Start with two cars
    for (int i = 0; i < INITIAL_CARS; i++) {
        Car newCar;
        tollLane.push_back(newCar);
    }

    cout << "Initial queue:\n";
    for (Car &car : tollLane) {
        cout << "    ";
        car.print();
    }

    int timePeriod = 0;

    // Keep running until the line is empty
    while (!tollLane.empty()) {
        timePeriod++;

        // Random number from 1 to 100
        int chance = rand() % 100 + 1;

        cout << "\nTime: " << timePeriod << " Operation: ";

        if (chance <= 55) {
            // 55% probability: first car pays and leaves
            cout << "Car paid: ";
            tollLane.front().print();
            tollLane.pop_front();
        } else {
            // 45% probability: a new car joins
            Car newCar;
            tollLane.push_back(newCar);

            cout << "Joined lane: ";
            tollLane.back().print();
        }

        // Display the queue after every time period
        displayQueue(tollLane);
    }

    return 0;
}
