#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- APPROACH ----------------------------------

Problem:
Implement a Stack (LIFO) using a Queue (FIFO).

Algorithm:
1. Push the new element into the queue.
2. Rotate the previous elements behind it.
   - After inserting, move the first (size-1) elements
     from the front to the back.
3. The newly inserted element becomes the front of the queue,
   which represents the top of the stack.
4. Pop simply removes the front element.
5. Top returns the front element.

Example:

push(10) -> [10]

push(20)
Queue: [10,20]
Rotate -> [20,10]

push(30)
Queue: [20,10,30]
Rotate -> [30,20,10]

Top = 30
Pop -> removes 30

Time Complexity:
push()  -> O(N)
pop()   -> O(1)
top()   -> O(1)
empty() -> O(1)

Space Complexity: O(N)
*/

class Stack{
    queue<int> q;

public:

    // Push element onto stack
    void push(int x){
        q.push(x);

        // Rotate the previous elements
        for(int i = 0; i < q.size() - 1; i++){
            q.push(q.front());
            q.pop();
        }
    }

    // Remove top element
    void pop(){
        if(q.empty()){
            cout << "Stack Underflow\n";
            return;
        }

        q.pop();
    }

    // Return top element
    int top(){
        if(q.empty()){
            cout << "Stack is Empty\n";
            return -1;
        }

        return q.front();
    }

    // Check if stack is empty
    bool empty(){
        return q.empty();
    }

    // Return size
    int size(){
        return q.size();
    }
};

int main(){

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;

    s.pop();

    cout << "Top after pop: " << s.top() << endl;

    cout << "Size: " << s.size() << endl;

    return 0;
}

/*
--------------------------- INTERVIEW NOTES ----------------------------------

Why does this work?
- Queue is FIFO, while Stack is LIFO.
- By rotating the queue after every insertion,
  the newest element is always placed at the front.
- Therefore, queue.front() always behaves like stack.top().

Common Mistakes:
1. Forgetting to rotate after every push.
2. Rotating 'size' times instead of 'size-1' times.
3. Accessing front() on an empty queue.
4. Mixing the two-queue and one-queue approaches.

Key Insight:
Instead of making pop expensive, make push expensive.
This ensures top() and pop() both become O(1).

Pattern:
Queue Simulation
(Implement Stack using One Queue)
*/