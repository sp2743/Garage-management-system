#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>  
using namespace std;
struct DueDate {
    int day;
    int month;
    int year;
};

class Car {
private:
    string make, car_model, reg_no, color;
    DueDate due_date; 
    int year;

public:
    Car() {
        make = car_model = reg_no = color = " ";
        year = 0;
        due_date.day = due_date.month = due_date.year = 0;
    }

    void init() {
        cout << "\nEnter Make: "; cin >> make;
        cout << "Enter Car Model: "; cin >> car_model;
        cout << "Enter Color of the Car: "; cin >> color;
        cout << "Enter the Registration Number: "; cin >> reg_no;
        cout << "Enter Year of Manufacture: "; cin >> year;

        cout << "\nEnter Due Date:\n";
        cout << "Day: "; cin >> due_date.day;
        cout << "Month: "; cin >> due_date.month;
        cout << "Year: "; cin >> due_date.year;
    }

    string getMake() const {
        return make;
    }

    string getCarModel() const {
        return car_model;
    }

    string getReg() const {
        return reg_no;
    }

    string getColor() const {
        return color;
    }

    DueDate getDueDate() const {
        return due_date;
    }

    int getYear() const {
        return year;
    }

    void setMake(string m) {
        make = m;
    }

    void setCarModel(string m) {
        car_model = m;
    }

    void setReg(string m) {
        reg_no = m;
    }

    void setColor(string m) {
        color = m;
    }

    void setDueDate(DueDate d) {
        due_date = d;
    }

    void setYear(int i) {
        year = i;
    }

    string toCSVString() const {
        stringstream ss;
        ss << make << "," << car_model << "," << color << "," << reg_no << "," << year
           << "," << due_date.day << "/" << due_date.month << "/" << due_date.year;
        return ss.str();
    }
};
