#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct Car {
    string carNumber;
    string ownerName;
};

vector<Car> parkingLot;
const int MAX_SLOTS = 10; // Total parking slots

void loadParkingData() {
    ifstream file("parking.txt");
    Car car;
    while (file >> car.carNumber >> car.ownerName) {
        parkingLot.push_back(car);
    }
    file.close();
}

void saveParkingData() {
    ofstream file("parking.txt");
    for (const auto &car : parkingLot) {
        file << car.carNumber << " " << car.ownerName << endl;
    }
    file.close();
}

void parkCar() {
    if (parkingLot.size() >= MAX_SLOTS) {
        cout << " Parking Full! No slots available.\n";
        return;
    }

    Car car;
    cout << "Enter Car Number (e.g., DL01AB1234): ";
    cin >> car.carNumber;
    cout << "Enter Owner Name: ";
    cin.ignore();
    getline(cin, car.ownerName);

    parkingLot.push_back(car);
    saveParkingData();
    cout << " Car parked successfully!\n";
}

void removeCar() {
    string carNumber;
    cout << "Enter Car Number to remove: ";
    cin >> carNumber;

    bool found = false;
    for (auto it = parkingLot.begin(); it != parkingLot.end(); ++it) {
        if (it->carNumber == carNumber) {
            parkingLot.erase(it);
            saveParkingData();
            cout << " Car removed successfully!\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << " Car not found in parking.\n";
    }
}

void viewParkingLot() {
    cout << "\nParked Cars (" << parkingLot.size() << "/" << MAX_SLOTS << " slots used):\n";
    if (parkingLot.empty()) {
        cout << " Parking is empty.\n";
    } else {
        for (const auto &car : parkingLot) {
            cout << "Car Number: " << car.carNumber << ", Owner: " << car.ownerName << endl;
        }
    }
    cout << " Available Slots: " << MAX_SLOTS - parkingLot.size() << endl;
}

int main() {
    int choice;
    loadParkingData();

    do {
        cout << "\n==============================\n";
        cout << " CAR PARKING MANAGEMENT SYSTEM\n";
        cout << "==============================\n";
        cout << "1 Park a Car\n";
        cout << "2 Remove a Car\n";
        cout << "3 View Parking Lot\n";
        cout << "4 Exit\n";
        cout << "Choose an option (1-4): ";

        if (!(cin >> choice)) {
            cout << " Invalid input! Numbers only.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: parkCar(); break;
            case 2: removeCar(); break;
            case 3: viewParkingLot(); break;
            case 4: cout << " Exiting Car Parking System...\n"; break;
            default: cout << "⚠ Invalid option. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
