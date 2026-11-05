
/*
  COMSC-210 Data Structures
  Lab 33: Toll Plaza
  Milestone 3
*/

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int NUM_LANES = 4;
const int INITIAL_CARS = 2;

// Display the cars in each toll booth lane
void displayPlaza(deque<Car> lanes[]) {
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << ":\n";

        if (lanes[i].empty()) {
            cout << "    Empty\n";
        } else {
            for (Car &car : lanes[i]) {
                cout << "    ";
                car.print();
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Create four toll booth lanes
    deque<Car> lanes[NUM_LANES];

    // Add two cars to each lane
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < INITIAL_CARS; j++) {
            Car newCar;
            lanes[i].push_back(newCar);
        }
    }

    // Display the initial traffic
    cout << "Initial queue:\n";
    displayPlaza(lanes);

    return 0;
}
