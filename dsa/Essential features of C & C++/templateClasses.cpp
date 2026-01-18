#include <iostream>
using namespace std;

// Class template for performing arithmetic operations
// 'T' is a generic data type (can be int, float, double, etc.)
template <class T>
class Arithmetic {
private:
    T a;  // first operand
    T b;  // second operand

public:
    // Parameterized constructor
    // Initializes data members using 'this' pointer
    Arithmetic(T a, T b) {
        this->a = a;
        this->b = b;
    }

    // Function to add two values
    T add() {
        T c;
        c = a + b;
        return c;
    }

    // Function to subtract two values
    T sub() {
        T c;
        c = a - b;
        return c;
    }
};

int main() {

    // Creating object of template class with int data type
    Arithmetic<int> arr(10, 5);

    // Creating object of template class with float data type
    Arithmetic<float> f(15.0f, 20.0f);

    // Performing operations for int object
    int sum = arr.add();
    int diff = arr.sub();

    // Performing operations for float object
    float sumf = f.add();
    float fdiff = f.sub();

    // Output results
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    cout << "Sum: " << sumf << endl;
    cout << "Difference: " << fdiff << endl;

    return 0;
}
