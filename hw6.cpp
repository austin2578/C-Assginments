#include <iostream>

using namespace std;

const double PI = 3.1415; // Define PI as a constant

// Define an abstract base class "Shape"
class Shape {
public:
    Shape() {} // Constructor
    ~Shape() {} // Destructor
    virtual double calcArea() = 0; // Pure virtual function for calculating area
};

// Define a class "Triangle" that inherits from "Shape"
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    // Constructor for Triangle
    Triangle(double b, double h) : base(b), height(h) {}

    // Implementation of the virtual function "calcArea" for Triangle
    virtual double calcArea(){
        return (base * height) / 2;
    }
};

// Define a class "Circle" that inherits from "Shape"
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor for Circle
    Circle(double r) : radius(r) {}

    // Implementation of the virtual function "calcArea" for Circle
    virtual double calcArea(){
        return PI * radius * radius;
    }
};

// Define a class "Rectangle" that inherits from "Shape"
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // Constructor for Rectangle
    Rectangle(double l, double w) : length(l), width(w) {}

    // Implementation of the virtual function "calcArea" for Rectangle
    virtual double calcArea(){
        return length * width;
    }
};

// Main function
int main() {
    char choice;
    do {
        system("cls"); // Clear the screen

        cout << "What shape do you want:" << endl;
        cout << "C) Circle" << endl;
        cout << "R) Rectangle" << endl;
        cout << "T) Triangle?" << endl;
        cout << "Enter C, R, or T: ";
        cin >> choice;

        Shape* shape = nullptr;

        // Create the selected shape based on user input
        switch (toupper(choice)) {
            case 'C': {
                double radius;
                cout << "Enter radius: ";
                cin >> radius;
                shape = new Circle(radius);
                break;
            }
            case 'R': {
                double length, width;
                cout << "Enter length: ";
                cin >> length;
                cout << "Enter width: ";
                cin >> width;
                shape = new Rectangle(length, width);
                break;
            }
            case 'T': {
                double base, height;
                cout << "Enter base: ";
                cin >> base;
                cout << "Enter height: ";
                cin >> height;
                shape = new Triangle(base, height);
                break;
            }
            default:
                cout << "Invalid entry... must be C, R, or T." << endl;
                break;
        }

        // Calculate and display the area of the selected shape
        if (shape) {
            double area = shape->calcArea();
            cout << "Area of ";
            switch (toupper(choice)) {
                case 'C':
                    cout << "circle: ";
                    break;
                case 'R':
                    cout << "rectangle: ";
                    break;
                case 'T':
                    cout << "triangle: ";
                    break;
            }
            cout << area << endl;

            delete shape; // Delete the dynamically allocated object
        }

        cout << "Do you want to continue (y/n)? ";
        cin >> choice;
    } while (toupper(choice) == 'Y');

    return 0;
}
/*OUTPUT
What shape do you want:
C) Circle
R) Rectangle
T) Triangle?
Enter C, R, or T: c
Enter radius: 4
Area of circle: 50.264
Do you want to continue (y/n)? Y

What shape do you want:
C) Circle
R) Rectangle
T) Triangle?
Enter C, R, or T: r
Enter length: 6
Enter width: 3
Area of rectangle: 18
Do you want to continue (y/n)? y

What shape do you want:
C) Circle
R) Rectangle
T) Triangle?
Enter C, R, or T: t
Enter base: 8
Enter height: 9
Area of triangle: 36
Do you want to continue (y/n)? y

What shape do you want:
C) Circle
R) Rectangle
T) Triangle?
Enter C, R, or T: k
Invalid entry... must be C, R, or T.
Do you want to continue (y/n)? n
*/