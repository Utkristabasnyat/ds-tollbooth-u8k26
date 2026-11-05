
/*
  COMSC-210 Data Structures
  Lab 32: Toll Booth Simulation
  Milestone 1
*/

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int INITIAL_CARS = 2;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Create a deque to hold Car objects
    deque<Car> tollLane;

    // Add two cars to the toll booth lane
    for (int i = 0; i < INITIAL_CARS; i++) {
        Car newCar;
        tollLane.push_back(newCar);
    }

    // Display the initial queue
    cout << "Initial queue:\n";

    for (Car &car : tollLane) {
        cout << "    ";
        car.print();
    }

    // Access the first car in line
    if (!tollLane.empty()) {
        cout << "\nFirst car in line:\n    ";
        tollLane.front().print();
    }

    // Display the number of cars waiting
    cout << "\nCars waiting: "
         << tollLane.size() << endl;

    return 0;
}
