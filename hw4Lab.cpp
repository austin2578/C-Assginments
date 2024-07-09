#include <iostream>
#include <string>

using namespace std;

class Tool {
private:
    int ID;
    string name;
    string description;
    double price;

public:
    // Default constructor
    Tool() : ID(0), name(""), description(""), price(0.0) {}

    // Setter functions
    void setID(int id) {
        ID = id;
    }

    void setName(const string toolName) {
        name = toolName;
    }

    void setDescription(const string toolDescription) {
        description = toolDescription;
    }

    void setPrice(double toolPrice) {
        price = toolPrice;
    }

    // Getter function for price
    double getPrice() const {
        return price;
    }

    // Display tool details
    void displayTool() const {
        cout << "Tool ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    Tool tool;

    // Ask the user to enter values
    int id;
    string name, description;
    double price;

    cout << "Enter Tool ID: ";
    cin >> id;
    cin.ignore(); // Clear the newline character from the buffer

    cout << "Enter Tool Name: ";
    getline(cin, name);

    cout << "Enter Tool Description: ";
    getline(cin, description);

    cout << "Enter Tool Price: ";
    cin >> price;

    // Set the values using setter functions
    tool.setID(id);
    tool.setName(name);
    tool.setDescription(description);
    tool.setPrice(price);

    // Display tool details
    cout << "\nTool Details:\n";
    tool.displayTool();

    // Display the tool's price using getPrice() function
    cout << "\nTool Price: $" << tool.getPrice() << endl;

    return 0;
}

/*
OUTPUT

Enter Tool ID: 12345
Enter Tool Name: Screwdriver
Enter Tool Description: Stanley heavy-duty phillips screwdriver
Enter Tool Price: 14.99

Tool Details:
Tool ID: 12345
Name: Screwdriver
Description: Stanley heavy-duty phillips screwdriver
Price: $14.99

Tool Price: $14.99*/