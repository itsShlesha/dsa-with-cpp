#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Reverse a Queue (Using Recursion)

Approach:
1. Remove the front element from the queue.
2. Recursively reverse the remaining queue.
3. Push the removed element back after the recursive call.
4. Since every element is inserted after all elements behind it,
   the queue gets reversed.

Why it works:
- Recursion removes elements until the queue becomes empty.
- While recursion unwinds, elements are inserted back in reverse order.
- The recursion stack acts as the temporary storage.

Time Complexity: O(n)
Space Complexity: O(n)  // Recursive call stack
-------------------------------------------------------
*/

/* iterative*/
/*queue<int> reversal(queue<int>&q){
    stack<int> s;

    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    return q;
}*/

/*recursive*/
void reversal(queue<int>&q){
    if(q.empty()) return;

    int front = q.front();
    q.pop();

    reversal(q);

    q.push(front);
}

int main(){

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while(!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
    }

    cout << "\nReversed Queue: ";

    reversal(q);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

/*
-------------------------------------------------------
Mistakes to Avoid:
1. Don't forget the base case (empty queue).
2. Pop the front element BEFORE making the recursive call.
3. Push the saved element AFTER recursion returns.
4. Queue is passed by reference so changes persist.
5. Returning the queue is optional since it is modified in place.

⭐ Interview Tip:
- Iterative solution uses an explicit stack.
- Recursive solution uses the call stack as the auxiliary stack.
- Interviewers often ask both approaches and may ask which data
  structure recursion is implicitly using.
-------------------------------------------------------
*/