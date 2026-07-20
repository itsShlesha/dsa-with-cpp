#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- APPROACH ----------------------------------

Problem:
Implement a Queue (FIFO) using two Stacks (LIFO).

Algorithm:
1. Push operation:
   - Always push new elements into stack s1.
2. Pop/Front operation:
   - If s2 is empty:
       Move all elements from s1 to s2.
   - Pop/peek from s2.
3. The transfer reverses the order, making the oldest element
   appear on top of s2, preserving FIFO behavior.

Example:

push(10), push(20), push(30)

s1 = [10,20,30]
s2 = []

front():
Transfer:
s2 = [30,20,10]

Top of s2 = 10 (Front)

pop():
Removes 10

Front becomes 20.

Time Complexity:
push()  -> O(1)
pop()   -> Amortized O(1)
front() -> Amortized O(1)
empty() -> O(1)

Space Complexity: O(N)
*/

class Queue{
    stack<int> s1, s2;

public:

    // Insert element into queue
    void push(int x){
        s1.push(x);
    }

    // Remove front element
    void pop(){

        if(empty()){
            cout << "Queue Underflow\n";
            return;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    // Return front element
    int front(){

        if(empty()){
            cout << "Queue is Empty\n";
            return -1;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // Check if queue is empty
    bool empty(){
        return s1.empty() && s2.empty();
    }

    // Return size
    int size(){
        return s1.size() + s2.size();
    }
};

int main(){

    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;

    q.pop();

    cout << "Front after pop: " << q.front() << endl;

    cout << "Size: " << q.size() << endl;

    return 0;
}

/*
--------------------------- INTERVIEW NOTES ----------------------------------

Why does this work?
- s1 stores newly inserted elements.
- s2 stores elements in queue order.
- Elements are transferred only when s2 becomes empty.
- Every element moves from s1 to s2 at most once,
  giving amortized O(1) complexity.

Common Mistakes:
1. Transferring elements on every pop().
2. Forgetting to check if both stacks are empty.
3. Calling top() on an empty stack.
4. Returning from s1 instead of s2 after transfer.

Key Insight:
Use one stack for insertion and another for deletion.
Lazy transfer ensures each element is moved only once.

Pattern:
Stack Simulation
(Implement Queue using Two Stacks)
*/