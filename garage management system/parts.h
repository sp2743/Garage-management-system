#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>  
using namespace std;
struct Part {
    string name;
    int quantity;
    string supplierName;

    string toCSVString() const {
        stringstream ss;
        ss << name << "," << quantity << "," << supplierName;
        return ss.str();
    }
};