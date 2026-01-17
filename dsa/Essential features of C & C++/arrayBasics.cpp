#include <iostream>   
using namespace std;  

int main(){

    int n;                         
    cout << "Enter size: ";       
    cin >> n;                      

    int C[n];  
    // ⚠️ Variable Length Array (VLA)
    // This is allowed in some compilers but NOT standard C++
    // Better approach: use vectors or dynamic allocation (new)

    int A[7] = {2,4,6,8,10,12};
    // Array of size 7
    // Only 6 values provided → last element auto-initialized to 0

    A[6] = 14;  
    // Assigning value to the last index (valid: 0 to 6)

    int B[10] = {0};
    // Initializes ALL elements of array B to 0

    for(int x : B){
        // Range-based for loop
        // Iterates over each element of array B
        cout << x << endl;         // Prints each element (all 0s)
    }

    cout << sizeof(A) << endl;
    // Prints total size of array A in BYTES
    // 7 integers × 4 bytes = 28 bytes (usually)

    cout << A[8] << endl;
    // ❌ ERROR / UNDEFINED BEHAVIOR
    // Accessing index 8 in array of size 7
    // Valid indices: 0 to 6 ONLY
    // This may print garbage or crash

    printf("%d\n", A[2]);
    // Prints 3rd element of array A
    // Mixing printf (C-style) with cout (C++)
    // Works, but not recommended for consistency

    return 0;  
}
