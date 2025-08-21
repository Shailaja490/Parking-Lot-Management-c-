#include <iostream>
#include <string>

using namespace std;

// Node for Linked List
struct CarNode {
    string car_number;
    CarNode* next;
    CarNode(string num) : car_number(num), next(nullptr) {}
};

class ParkingLot {
    CarNode* head;
    int max_slots;
    int current_slots;

public:
    ParkingLot(int slots) : head(nullptr), max_slots(slots), current_slots(0) {}

    void parkCar(string car_number) {
        if(current_slots >= max_slots) {
            cout << "Parking Lot Full! Cannot park car " << car_number << endl;
            return;
        }
        CarNode* newCar = new CarNode(car_number);
        newCar->next = head;
        head = newCar;
        current_slots++;
        cout << "Car " << car_number << " parked successfully." << endl;
    }

    void removeCar(string car_number) {
        CarNode* temp = head;
        CarNode* prev = nullptr;
        while(temp) {
            if(temp->car_number == car_number) {
                if(prev) prev->next = temp->next;
                else head = temp->next;
                delete temp;
                current_slots--;
                cout << "Car " << car_number << " removed from parking." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Car " << car_number << " not found in parking." << endl;
    }

    void showCars() {
        cout << "\nCurrent Parked Cars:\n";
        CarNode* temp = head;
        int count = 0;
        while(temp) {
            cout << "- " << temp->car_number << endl;
            temp = temp->next;
            ++count;
        }
        if(count == 0) cout << "No cars parked currently!" << endl;
        cout << endl;
    }
};

int main() {
    ParkingLot parking(3); // Example: 3 slots max
    parking.parkCar("KA01AB1234");
    parking.parkCar("KA02XY4567");
    parking.parkCar("KA03CD7890");
    parking.parkCar("KA04ZZ0001"); // Should say full

    parking.showCars();

    parking.removeCar("KA02XY4567");
    parking.showCars();

    parking.parkCar("KA05PL5555"); // Should succeed now

    parking.showCars();
    return 0;
}
