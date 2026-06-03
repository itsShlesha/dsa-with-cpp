#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:

Implement two stacks using a single array.

Operations:
1. push1(x)  -> Push element into Stack 1.
2. push2(x)  -> Push element into Stack 2.
3. pop1()    -> Remove and return top of Stack 1.
4. pop2()    -> Remove and return top of Stack 2.

APPROACH:

Use one array and let both stacks grow towards each other.

Stack 1:
- Starts from index 0.
- top1 initially = -1.
- Grows left to right.

Stack 2:
- Starts from last index.
- top2 initially = size.
- Grows right to left.

Before every push:
Check if at least one free space exists between top1 and top2.

Condition:
top2 - top1 > 1

If true:
Insertion is possible.

WHY IT WORKS:

Both stacks share the same array space dynamically.

Unlike dividing the array into fixed halves:
- Stack 1 can use more space if Stack 2 is small.
- Stack 2 can use more space if Stack 1 is small.

Overflow occurs only when both tops become adjacent.

TIME COMPLEXITY:
push1  -> O(1)
push2  -> O(1)
pop1   -> O(1)
pop2   -> O(1)
peek1  -> O(1)
peek2  -> O(1)

SPACE COMPLEXITY:
O(N)
(N = size of shared array)
*/

class TwoStack{
    int *arr;
    int top1;
    int top2;
    int size;

public:

    TwoStack(int s){
        size = s;
        top1 = -1;
        top2 = s;

        arr = new int[s];
    }

    void push1(int element){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = element;
        }
        else{
            cout << "Stack 1 Overflow!" << endl;
        }
    }

    void push2(int element){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = element;
        }
        else{
            cout << "Stack 2 Overflow!" << endl;
        }
    }

    int pop1(){
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }

        return -1;
    }

    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }

        return -1;
    }

    int peek1(){
        if(top1 >= 0){
            return arr[top1];
        }

        return -1;
    }

    int peek2(){
        if(top2 < size){
            return arr[top2];
        }

        return -1;
    }

    bool isEmpty1(){
        return top1 == -1;
    }

    bool isEmpty2(){
        return top2 == size;
    }

    ~TwoStack(){
        delete[] arr;
    }
};

int main(){

    TwoStack st(10);

    st.push1(5);
    st.push1(10);
    st.push1(15);

    st.push2(100);
    st.push2(200);
    st.push2(300);

    cout << "Top of Stack 1: " << st.peek1() << endl;
    cout << "Top of Stack 2: " << st.peek2() << endl;

    cout << "Pop Stack 1: " << st.pop1() << endl;
    cout << "Pop Stack 2: " << st.pop2() << endl;

    cout << "Top of Stack 1: " << st.peek1() << endl;
    cout << "Top of Stack 2: " << st.peek2() << endl;

    return 0;
}

/*
MISTAKES TO AVOID:

1. Wrong array allocation.

Wrong:
arr = new int(size);

Correct:
arr = new int[size];

The first creates only one integer.
The second creates an array.

2. Incorrect overflow condition.

Use:
top2 - top1 > 1

This guarantees at least one free slot exists.

3. Initializing top2 incorrectly.

Correct:
top2 = size;

Not:
top2 = size - 1

Because Stack 2 should be empty initially.

4. Forgetting boundary checks before pop().

Stack 1:
top1 >= 0

Stack 2:
top2 < size

5. Forgetting delete[] for dynamically allocated arrays.

Use:
delete[] arr;

GOLDEN INTERVIEW TIPS:

1. Mention that both stacks utilize memory efficiently
   because unused space of one stack can be used by the other.

2. Explain the growth directions clearly:
   Stack 1 -> Left to Right
   Stack 2 -> Right to Left

3. Interviewers often ask:
   "Why is this better than dividing the array into two halves?"

   Answer:
   Fixed partition wastes space.
   Two-stack approach uses the entire array dynamically.

4. Remember the core condition:

   top2 - top1 > 1

   This single condition prevents overflow.

5. If asked for optimization,
   this is already the optimal array-based solution:
   O(1) operations and O(N) total storage.
*/