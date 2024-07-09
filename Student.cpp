#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(int id, string name) {
    this->id = id;
    this->name = name;
}

Student::~Student() {}

int Student::getID() const {
    return id;
}

string Student::getName() const {
    return name;
}

void Student::showStudent() const {
    cout << "ID: " << id << "\nName: " << name << endl;
}

void Student::setID(int id) {
    this->id = id;
}

void Student::setName(const string& name) {
    this->name = name;
}