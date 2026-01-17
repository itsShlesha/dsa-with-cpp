#include <iostream>
using namespace std;

/* -------- ARRAY AS PARAMETER -------- */
void fun(int* a, int n){
    // a is NOT an array here
    // a is a POINTER to the first element of the array

    cout << sizeof(a) / sizeof(int) << endl;
    // ❌ WRONG LOGIC (but intentional learning moment)
    // sizeof(a) → size of pointer 
    // sizeof(int) → 4 bytes
    // Output → 1

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    a[0] = 15;
    // Modifies the ORIGINAL array
    // Because a points to caller's memory
}

/* -------- RETURNING ARRAY FROM FUNCTION -------- */
int* function(int size){
    int *p = new int[size];
    // Heap allocation
    // p is on stack, array is on heap

    for(int i = 0; i < size; i++){
        p[i] = i + 1;
    }

    return p;
    // Returning address of heap memory → SAFE
}

int main(){

    int a[] = {2,4,6,8,10};
    int n = 5;

    fun(a, n);
    cout << endl;

    cout << sizeof(a) / sizeof(int) << endl;
    // ✅ Correct here
    // sizeof(a) = 5 * sizeof(int)
    // Output = 5

    for(int x : a){
        cout << x << " ";
    }
    cout << endl;

    int* ptr, size = 5;
    ptr = function(size);

    for(int i = 0; i < size; i++){
        cout << ptr[i] << " ";
    }

    return 0;
}
