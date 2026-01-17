#include <iostream>
using namespace std;

/* ---------------- CALL BY VALUE ---------------- */
void swapbyvalue(int x, int y){
    // x and y are COPIES of the actual arguments

    int temp = x;
    x = y;
    y = temp;

    cout << "Inside function:: x= " << x << " and y= " << y << endl;
    // Swapped ONLY inside this function
}

/* ---------------- CALL BY POINTER ---------------- */
void swapbypointer(int *x, int *y){
    // x and y store ADDRESSES of caller's variables

    int temp;
    temp = *x;   // value at address x
    *x = *y;     // modify caller's variable
    *y = temp;

    cout << "Inside function:: x= " << *x << " and y= " << *y << endl;
    // Actual variables are swapped
}

/* ---------------- CALL BY REFERENCE ---------------- */
void swapbyreference(int &x, int &y){
    // x and y are ALIASES to caller's variables

    int temp = x;
    x = y;
    y = temp;

    cout << "Inside function:: x= " << x << " and y= " << y << endl;
    // Actual variables are swapped
}

int main(){

    int num1 = 10, num2 = 20;

    cout << "Call by value" << endl;
    swapbyvalue(num1, num2);
    cout << "Outside function:: x= " << num1 << " and y= " << num2 << endl;
    // ❌ NOT swapped

    cout << "Call by pointer" << endl;
    swapbypointer(&num1, &num2);
    cout << "Outside function:: x= " << num1 << " and y= " << num2 << endl;
    // ✅ Swapped

    cout << "Call by reference" << endl;
    swapbyreference(num1, num2);
    cout << "Outside function:: x= " << num1 << " and y= " << num2 << endl;
    // ✅ Swapped

    return 0;
}
