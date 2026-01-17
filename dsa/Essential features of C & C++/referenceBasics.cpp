#include <iostream>
using namespace std;

int main(){

    int a = 10;        // Normal integer variable (stack)
    int &r = a;        // Reference r becomes an ALIAS of a
                       // r and a refer to the SAME memory location

    cout << a << endl << r << endl;
    // Output:
    // 10
    // 10

    r = 25;            // Modifying r actually modifies a
    cout << a << endl << r << endl;
    // Output:
    // 25
    // 25

    int b = 30;        // Another variable

    r = b;
    // ⚠️ IMPORTANT:
    // This does NOT rebind r to b
    // It assigns value of b (30) to a

    cout << a << endl << r << endl;
    // Output:
    // 30
    // 30

    return 0;
}
