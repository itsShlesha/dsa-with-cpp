#include <iostream>
using namespace std;

int add(int a, int b){
    // Function definition
    // a and b are FORMAL PARAMETERS (local to this function)

    int c = a + b;   // Local variable c (stack)
    return c;        // Value returned to caller
}

int main(){

    int num1 = 10, num2 = 15, sum;
    // num1, num2, sum are local variables of main (stack)

    sum = add(num1, num2);
    // Function call
    // num1 and num2 are ACTUAL PARAMETERS

    cout << "Sum: " << sum << endl;
    // Prints result

    return 0;
}
