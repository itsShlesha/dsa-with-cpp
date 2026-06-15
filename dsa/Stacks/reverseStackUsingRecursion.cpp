#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:
Reverse a stack using recursion without using
any extra data structure.

Example:

Top
9
4
1
7

After reversing:

Top
7
1
4
9

APPROACH:
1. Remove the top element recursively until the stack becomes empty.
2. Reverse the remaining stack.
3. Insert the removed element at the bottom of the stack.
4. Repeat this process while recursion unwinds.

WHY IT WORKS:
- Recursion removes all elements one by one.
- While returning from recursive calls, each element is inserted
  at the bottom of the already reversed smaller stack.
- This gradually reverses the entire stack.

TIME COMPLEXITY:
O(N²)

Explanation:
- Reverse is called N times.
- insertAtBottom takes O(N) in the worst case.

SPACE COMPLEXITY:
O(N)   // Recursive call stack
*/

void insertAtBottom(stack<int>& s, int num){
    if(s.empty()){
        s.push(num);
        return;
    }

    int top = s.top();
    s.pop();

    insertAtBottom(s, num);

    s.push(top);
}

void reverseStack(stack<int>& s){
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, num);
}

int main(){
    stack<int> s;

    s.push(7);
    s.push(1);
    s.push(4);
    s.push(9);

    reverseStack(s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

/*
MISTAKES TO AVOID:
1. Passing stack by value in insertAtBottom().
   - Changes occur on a copy, not the original stack.

2. Forgetting the base case:
   if(s.empty()) return;
   - Leads to infinite recursion.

3. Not restoring popped elements during backtracking.
   - Causes loss of stack elements.

4. Trying to reverse by only popping elements.
   - Elements must be inserted at the bottom while unwinding.

5. Using reverse as a function name.
   - Can conflict with std::reverse from STL.

GOLDEN INTERVIEW TIPS:
1. Reverse Stack is built directly on the
   "Insert At Bottom" problem.

2. Learn these recursive stack patterns:
   - Insert at Bottom
   - Reverse Stack
   - Sort Stack
   - Delete Middle Element

3. A common interview strategy:
   First solve Insert At Bottom,
   then use it as a helper for Reverse Stack.

4. Whenever an operation is needed below the top
   of a stack, recursion is often the intended solution.

5. Think of recursion as a temporary storage area
   that replaces the need for an auxiliary stack.
*/