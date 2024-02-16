#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "parts.h"
#include "Cars.h"
#include <iomanip>  
using namespace std;
class Garage {
private:
    string name;
    int index, capacity;
    Car *cars;
    Part *parts;  
    int partsIndex;  

public:
    Garage() {
        name = "";
        index = 0; capacity = 10;
        cars = new Car[capacity];
        parts = new Part[capacity];
        partsIndex = 0;
    }

    bool IsEmpty() const {
        return index != capacity;
    }

    bool IsFull() const {
        return index == capacity;
    }

    void Push(const Car &c) {
        bool x = this->IsEmpty();
        if (x) {
            cout << "\n\nCar can be parked\n";
            cars[index] = c;
            index++;
        } else {
            cout << "\n Garage is Full: \n";
        }
    }

    bool Find(const string &reg) const {
        for (int i = 0; i < index; i++) {
            if (cars[i].getReg() == reg) {
                cout << "Found\n";
                return true;
            }
        }
        cout << "Not Found\n";
        return false;   
    }

    bool Remove(const string &reg) {
        for (int i = 0; i < index; i++) {
            if (cars[i].getReg() == reg) {
                int x = i;
                for (int j = x; j < index - 1; j++) {
                    cars[j] = cars[j + 1];
                }
            }
        }
        index--;
        return true;
    }

    void manageParts() {
        cout << "\n--- Manage Parts ---\n";
        int choice;

        do {
            cout << "1 - Add Part\n"
                 << "2 - Display Parts\n"
                 << "3 - Exit\n";
            cin >> choice;

            switch (choice) {
                case 1: {
                    Part p;
                    cout << "Enter Part Name: "; cin >> p.name;
                    cout << "Enter Quantity: "; cin >> p.quantity;
                    cout << "Enter Supplier Name: "; cin >> p.supplierName;

                    if (partsIndex < capacity) {
                        parts[partsIndex++] = p;
                        cout << "Part added successfully.\n";
                    } else {
                        cout << "Part storage is full.\n";
                    }
                    break;
                }
                case 2: {
                    if (partsIndex == 0) {
                        cout << "No parts in inventory.\n";
                    } else {
                        cout << "\n--- Parts Inventory ---\n";
                        cout << left << setw(20) << "Name" << setw(15) << "Quantity" << setw(20) << "Supplier Name" << endl;
                        for (int i = 0; i < partsIndex; ++i) {
                            cout << left << setw(20) << parts[i].name << setw(15) << parts[i].quantity << setw(20) << parts[i].supplierName << endl;
                        }
                    }
                    break;
                }
                case 3: {
                    cout << "Exiting Parts Management.\n";
                    break;
                }
                default:
                    cout << "Invalid option. Please try again.\n";
                    break;
            }
        } while (choice != 3);
    }

void writePartsToCSV(const string& filename) const {
    ofstream file(filename, ios::app);  
    if (file.is_open()) {
        if (file.tellp() == 0) {  
            file << "Name,Quantity,Supplier Name\n";
        }
        for (int i = 0; i < partsIndex; ++i) {
            file << parts[i].toCSVString() << endl;
        }
        file.close();
        cout << "\nPart details have been written to " << filename << endl;
    } else {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
    }   
}

    void display() const {
        if (index == 0) {
            cout << "No cars in the garage.\n";
            return;
        }

        cout << "\n--- Parked Cars ---\n";
        cout << left << setw(15) << "Registration" << setw(15) << "Make" << setw(15) << "Model"
             << setw(15) << "Color" << setw(10) << "Year" << setw(15) << "Due Date" << endl;
        for (int i = 0; i < index; i++) {
            DueDate due_date = cars[i].getDueDate();
            cout << left << setw(15) << cars[i].getReg() << setw(15) << cars[i].getMake()
                 << setw(15) << cars[i].getCarModel() << setw(15) << cars[i].getColor()
                 << setw(10) << cars[i].getYear() << due_date.day << "/" << due_date.month << "/" << <<due_date.year << endl;
        }
    }

    void showEarliestDueDate() const {
        if (index == 0) {
            cout << "No cars in the garage.\n";
            return;
        }

        DueDate earliestDueDate = cars[0].getDueDate();
        int earliestIndex = 0;

        for (int i = 1; i < index; i++) {
            if (cars[i].getDueDate().year < earliestDueDate.year ||
                (cars[i].getDueDate().year == earliestDueDate.year &&
                 cars[i].getDueDate().month < earliestDueDate.month) ||
                (cars[i].getDueDate().year == earliestDueDate.year &&
                 cars[i].getDueDate().month == earliestDueDate.month &&
                 cars[i].getDueDate().day < earliestDueDate.day)) {
                earliestDueDate = cars[i].getDueDate();
                earliestIndex = i;
            }
        }

        cout << "\n--- Earliest Due Date ---\n";
        cout << "Registration: " << cars[earliestIndex].getReg() << "\n"
             << "Make: " << cars[earliestIndex].getMake() << "\n"
             << "Model: " << cars[earliestIndex].getCarModel() << "\n"
             << "Color: " << cars[earliestIndex].getColor() << "\n"
             << "Year: " << cars[earliestIndex].getYear() << "\n"
             << "Due Date: " << earliestDueDate.day << "/" << earliestDueDate.month << "/" << earliestDueDate.year << "\n"
             << "--------------------------\n";
    }

 void writeCarsToCSV(const string& filename) const {
    ofstream file(filename, ios::app);  
    if (file.is_open()) {
        if (file.tellp() == 0) {  
            file << "Make,Car Model,Color,Registration Number,Year,Due Date\n";
        }
        for (int i = 0; i < index; ++i) {
            file << cars[i].toCSVString() << endl;
        }
        file.close();
        cout << "\nCar details have been written to " << filename << endl;
    } else {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
    }
}

    ~Garage() {
        delete[] cars;
        delete[] parts;
    }
};