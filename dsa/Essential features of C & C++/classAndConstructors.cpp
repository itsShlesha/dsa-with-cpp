#include <iostream>
using namespace std;

// Class definition for Rectangle
class Rectangle {
private:
    int l;  // length (data member is private for data hiding)
    int b;  // breadth

public:
    // Default constructor
    // Called when no arguments are passed
    Rectangle() {
        l = 0;
        b = 0;
    }

    // Parameterized constructor
    // 'this->' is used to differentiate
    // between data members and parameters
    Rectangle(int l, int b) {
        this->l = l;
        this->b = b;
    }

    // Function to calculate area
    int area() {
        return l * b;
    }

    // Function to calculate perimeter
    int perimeter() {
        return 2 * (l + b);
    }

    // Setter function for length
    void setLength(int l) {
        this->l = l;
    }

    // Setter function for breadth
    void setBreadth(int b) {
        this->b = b;
    }

    // Getter function for length
    int getLength() {
        return l;
    }

    // Getter function for breadth
    int getBreadth() {
        return b;
    }

    // Destructor
    // Automatically called when object goes out of scope
    ~Rectangle() {
        cout << "Destructor called" << endl;
    }
};

int main() {

    // Creating object using parameterized constructor
    Rectangle r(10, 5);

    // Calling member functions
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;

    return 0;
}
