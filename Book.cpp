// Book.cpp
#include "Book.h"
using namespace std;

// Initialize static variable
int Book::bookCount = 0;

// Constructors
Book::Book(const std::string& isbn, int year, double price)
    : isbn(isbn), year(year), price(price) {
    // Increment bookCount every time a Book object is created
    bookCount++;
}

// Display function
void Book::displayBook() const {
    cout << "Here is book #" << bookCount << ":\n"
         << "ISBN: " << isbn << "\nYear: " << year << "\nPrice: " << price << endl;
}

// Static function to get the book count
int Book::getCount() {
    return bookCount;
}

// Overloaded operators
bool Book::operator>(const Book& other) const {
    return price > other.price;
}

bool Book::operator==(const Book& other) const {
    return price == other.price;
}

bool Book::operator>(double value) const {
    return price > value;
}

double Book::operator+(const Book& other) const {
    return price + other.price;
}

bool Book::operator<(int year) const {
    return this->year < year;
}

ostream& operator<<(ostream& os, const Book& book) {
    os << "ISBN: " << book.isbn << "\nYear: " << book.year << "\nPrice: " << book.price;
    return os;
}
