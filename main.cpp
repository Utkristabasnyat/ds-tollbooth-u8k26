
/*
  COMSC-210 Data Structures
  Lab 33: Toll Plaza
  Milestone 2
*/

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int NUM_LANES = 4;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Create an array containing four toll booth lanes
    deque<Car> lanes[NUM_LANES];

    cout << "Testing four toll booth lanes\n";

    // Test adding one car to each lane
    for (int i = 0; i < NUM_LANES; i++) {
        Car newCar;
        lanes[i].push_back(newCar);

        cout << "\nLane " << i + 1 << ":\n";
        cout << "Added car: ";
        lanes[i].back().print();

        cout << "Cars waiting: "
             << lanes[i].size() << endl;
    }

    // Test accessing and removing cars
    cout << "\nTesting car departures\n";

    for (int i = 0; i < NUM_LANES; i++) {
        if (!lanes[i].empty()) {
            cout << "\nLane " << i + 1 << " car leaving: ";
            lanes[i].front().print();

            lanes[i].pop_front();
        }

        cout << "Cars remaining in Lane "
             << i + 1 << ": "
             << lanes[i].size() << endl;
    }

    return 0;
}
