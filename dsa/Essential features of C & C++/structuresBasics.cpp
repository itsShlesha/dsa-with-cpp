#include <iostream>
using namespace std;

struct Rectangle{
    int length;    // 4 bytes
    int breadth;   // 4 bytes
    char x;        // 1 byte
    // Padding will be added by the compiler
};

int main(){

    struct Rectangle r1 = {10,5};
    // length = 10
    // breadth = 5
    // x is NOT initialized → contains garbage value

    printf("%d\n", sizeof(r1));
    // Prints total memory occupied by the structure (including padding)

    r1.length = 15;   // Updating length
    r1.breadth = 7;   // Updating breadth

    cout << r1.length << endl;   // Prints 15
    cout << r1.breadth << endl;  // Prints 7

    return 0;
}
