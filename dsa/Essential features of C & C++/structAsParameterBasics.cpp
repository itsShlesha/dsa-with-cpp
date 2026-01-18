#include <iostream>
using namespace std;

// Defining a structure named Rectangle
// It groups related data members together
struct Rectangle {
    int l;  // length of the rectangle
    int b;  // breadth of the rectangle
};

// Function demonstrating CALL BY VALUE
// A COPY of the structure 'r' is passed
void callbyvalue(struct Rectangle r) {
    r.l++;  // modifies only the local copy, not the original
    cout << "Length: " << r.l << " Breadth: " << r.b << endl;
}

// Function demonstrating CALL BY ADDRESS
// Address of the structure is passed using a pointer
void callbyaddress(struct Rectangle *r) {
    r->l++; // modifies the original structure using pointer dereferencing
    cout << "Length: " << r->l << " Breadth: " << r->b << endl;
}

// Function that creates a Rectangle in HEAP memory
// and returns its address
struct Rectangle* fun() {
    struct Rectangle *p;

    // Dynamic memory allocation using 'new'
    // Memory is allocated in heap
    p = new Rectangle;

    // Assigning values using arrow operator
    p->l = 15;
    p->b = 7;

    // Returning address of heap-allocated structure
    return p;
}

int main() {

    // Creating a Rectangle structure variable in STACK memory
    struct Rectangle r = {10, 5};

    // Initial values
    cout << "Length: " << r.l << " Breadth: " << r.b << endl;

    // Call by value: original structure remains unchanged
    callbyvalue(r);
    cout << "Length: " << r.l << " Breadth: " << r.b << endl;

    // Call by address: original structure gets modified
    callbyaddress(&r);
    cout << "Length: " << r.l << " Breadth: " << r.b << endl;

    cout << endl;

    // Pointer receiving address of heap-allocated structure
    struct Rectangle *ptr = fun();

    // Accessing structure members using pointer
    cout << "Length: " << ptr->l << " Breadth: " << ptr->b << endl;

    return 0;
}
