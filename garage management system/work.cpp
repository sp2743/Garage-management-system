#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "parts.h"
#include "Cars.h"
#include "Garage.h"
#include <iomanip>  
using namespace std;


int main() {
    Garage g;
    int q;

    do {
        cout << "\nInput option\n"
             << "1 - Add car in garage\n"
             << "2 - Remove car from garage\n"
             << "3 - Display parked cars\n"
             << "4 - Find car\n"
             << "5 - Check if garage is full\n"
             << "6 - Show earliest due date\n"
             << "7 - Manage Parts\n"  
             << "8 - Exit" << endl;  
        cin >> q;
        cin.ignore(); 

        switch (q) {
            case 1: {
                Car c;
                c.init();
                g.Push(c);
                g.writeCarsToCSV("car_details.csv");
                break;
            }
            case 2: {
                cout << "Input reg_no of car to be removed\n";
                string c;
                cin >> c;
                g.Remove(c);
                g.writeCarsToCSV("car_details.csv");
                break;
            }
            case 3: {
                g.display();
                break;
            }
            case 4: {
                cout << "Input reg_no of car to be found\n";
                string c;
                cin >> c;
                g.Find(c);
                if(g.Find(c))
                cout<<"";
                else
                cout<<"Not Found";
                break;
            }
            case 5: {
                if (g.IsFull()) {
                    cout << "\nGarage is full\n";
                } else {
                    cout << "\nGarage is not full\n";
                }
                break;
            }
            case 6: {
                g.showEarliestDueDate();
                break;
            }
            case 7: {
                g.manageParts();
                g.writePartsToCSV("parts_details.csv");
                break;
            }
            case 8: {
                break;
            }
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (q != 8);

    return 0;
}
