#include <iostream>
using namespace std;

struct Rectangle{
    int l;   // length
    int b;   // breadth
};

int main(){

    int a = 10;          // Normal integer variable (stored on stack)
    int *p;              // Pointer to int (also stored on stack)

    p = &a;              // p now stores address of variable 'a'

    cout << "just the variable " << a << endl;
    // Prints value of 'a'

    printf("using pointer %d %d\n", p, &a);
    // ❌ LOGICAL ISSUE:
    // p and &a are ADDRESSES
    // %d is for int, not addresses
    // This is undefined behavior (should use %p)

    cout << "derefrencing " << *p << endl;
    // Dereferencing pointer
    // Prints value stored at address p → 10

    // ---------------- ARRAY WITH POINTER ----------------

    int arr[5] = {2,4,6,8,10};   // Array stored on stack
    int* p2 = arr;              // arr decays to pointer to first element

    for(int i = 0; i < 5; i++){
        cout << p2[i] << endl;  // Accessing array using pointer notation
    }

    // ---------------- HEAP MEMORY ----------------

    int* p3 = (int *)malloc(5 * sizeof(int));
    // Allocates memory for 5 integers in HEAP
    // malloc returns void* → typecast needed in C++

    // Alternative (C++ way):
    // int* p3 = new int[5];

    p3[0] = 10;
    p3[1] = 15;
    p3[2] = 3;
    p3[3] = 4;
    p3[4] = 110;

    for(int i = 0; i < 5; i++){
        cout << p3[i] << endl;  // Printing heap array values
    }

    // delete[] p3;   // ❌ DO NOT use delete for malloc memory
    free(p3);         // ✅ Correct way to free malloc memory

    // ---------------- POINTER SIZES ----------------

    int* ptr;
    char* charptr;
    float* fptr;
    double* dptr;
    struct Rectangle *rtpr;

    cout << "Integer pointer size: " << sizeof(ptr) << endl;
    cout << "Character pointer size: " << sizeof(charptr) << endl;
    cout << "Float pointer size: " << sizeof(fptr) << endl;
    cout << "Double pointer size: " << sizeof(dptr) << endl;
    cout << "Structure pointer size: " << sizeof(rtpr) << endl;

    return 0;
}
