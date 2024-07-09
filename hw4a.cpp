// Attached: HW_4A
// ===================================================
// Program: Transaction.cpp
// =================================================== 
// Programmer: Austin Monroe
// Class: CS-1C
// ===================================================
// Program: hw4A
//
//====================================================
//Description:
// This program will create two instances of the car class
// with the first car using data input from the user
// and the second car using data in an overloaded constructor
//=====================================================
#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int month;
    int year;

public:
    // Default constructor
    Date() : month(0), year(0) {}

    // Constructor with parameters
    Date(int m, int y) : month(m), year(y) {}

    // Destructor
    ~Date() {}

    // Set the date
    void setDate(int m, int y) {
        month = m;
        year = y;
    }

    // Display the date
    void const showDate() {
        cout << month << "/" << year << endl;
    }
};

class Car {
private:
    int id;
    string model;
    static int carCount;

public:

    //Date public declaration
    Date dateManufactured;

    // Default constructor
    Car() : id(0), model(""), dateManufactured() {
        carCount++; // Increment carCount when a car object is created
    }

    // Constructor with parameters
    Car(int carId, const string& carModel, int month, int year)
        : id(carId), model(carModel), dateManufactured(month, year) {
        carCount++; // Increment carCount when a car object is created
    }

    // Destructor
    ~Car() {}

    // Setters
    void setID(int carId) {
        id = carId;
    }

    void setModel(const string& carModel) {
        model = carModel;
    }

    // Getters
    const int getID() const {
        return id;
    }

    const string getModel() const {
        return model;
    }

    static int getCarCount() {
        return carCount;
    }

    // Display car information
    void const displayCar(){
        cout << "ID: " << id << "\nModel: " << model << "\nDate Manufactured: ";
        dateManufactured.showDate();
        cout << endl;
    }
};

// Initialize the static variable outside of the class definition
int Car::carCount = 0;

int main() {
    Car firstCar; // Calls the default constructor
    Car secondCar(12345, "Nissan", 9, 2018); // Calls the constructor with parameters

    // Prompt the user for information about the first car
    int firstCarID;
    string firstCarModel;
    int firstCarMonth;
    int firstCarYear;

    cout << "Enter information about the first car:\n";
    cout << "ID: ";
    cin >> firstCarID;
    cout << "Model: ";
    cin.ignore(); // Ignore newline character
    getline(cin, firstCarModel);
    cout << "Month manufactured: ";
    cin >> firstCarMonth;
    cout << "Year manufactured: ";
    cin >> firstCarYear;
    system("cls");

    // Set the information for the first car
    firstCar.setID(firstCarID);
    firstCar.setModel(firstCarModel);
    firstCar.dateManufactured.setDate(firstCarMonth, firstCarYear);
    cout << "First car:\n";
    firstCar.displayCar();

    // Display the second car
    cout << "Second car:\n";
    secondCar.displayCar();

    // Display the number of cars
    cout << "Total Cars: " << Car::getCarCount() << endl;

    return 0;
}

/*
OUTPUT

First car:
ID: 54321
Model: Toyota Prius
Date Manufactured: 7/0

Second car:
ID: 12345
Model: Nissan
Date Manufactured: 9/2018

Total Cars: 2*/