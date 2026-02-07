#include <bits/stdc++.h>
using namespace std;

// fun1 prints the number first and then calls itself
// so printing happens while going deeper into recursion
void fun1(int n){
    // every time fun1 is called, a new stack frame is created
    // with its own value of n
    if(n > 0){
        cout << n;      // print first
        fun1(n - 1);    // recursive call
    }
    // when n becomes 0, function just returns
    // and stack starts getting cleared
}

// fun2 calls itself first and prints later
// so printing happens while returning from recursion
void fun2(int n){
    // each recursive call is pushed onto the stack
    if(n > 0){
        fun2(n - 1);    // recursive call first
        cout << n;     // print after returning
    }
    // values are printed when stack frames are popping
}

int main(){

    int x = 3;

    /*
    fun1(3) execution:

    call stack:
    fun1(3)
    fun1(2)
    fun1(1)
    fun1(0)  // base case

    printing happens while going down the stack
    output: 321
    */
    fun1(x);

    cout << "\n";

    /*
    fun2(3) execution:

    call stack:
    fun2(3)
    fun2(2)
    fun2(1)
    fun2(0)  // base case

    printing happens while stack is getting cleared
    output: 123
    */
    fun2(x);

    return 0;
}
