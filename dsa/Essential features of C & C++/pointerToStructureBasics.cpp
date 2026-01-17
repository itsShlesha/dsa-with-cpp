#include <iostream>
using namespace std;

struct square{
    int side;     // Member of structure
};

int main(){

    square s = {10};
    // Structure variable created on STACK
    // s.side = 10

    cout << s.side << endl;
    // Accessing structure member using dot operator

    square *ptr = &s;
    // Pointer to structure
    // ptr stores address of s

    cout << ptr->side << endl;
    // Accessing structure member using arrow operator (->)
    // ptr->side is same as (*ptr).side

    square* p;
    p = (struct square*)(malloc(sizeof(square)));
    // Heap memory allocation (C-style)
    // malloc returns void* → typecast needed in C++

    // Alternative (C++ style):
    // p = new square;

    p->side = 15;
    // Assigning value to structure member in heap

    cout << p->side << endl;
    // Printing heap structure member

    return 0;
}
