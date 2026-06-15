#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:
Insert an element at the bottom of a stack
without using any extra data structure.

Example:

Top
4
1
7

Insert: 9

Result:

Top
4
1
7
9

APPROACH:
1. Pop all elements recursively until the stack becomes empty.
2. Insert the new element into the empty stack.
3. While recursion unwinds, push all removed elements back.

WHY IT WORKS:
- Recursion temporarily stores stack elements in the call stack.
- Once the stack becomes empty, the new element naturally becomes
  the bottom-most element.
- Restoring all removed elements preserves the original order.

TIME COMPLEXITY:
O(N)

SPACE COMPLEXITY:
O(N)   // Recursive call stack
*/

void solve(stack<int>&s, int x){
    //base case
    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    solve(s, x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int>&myStack, int x){
    solve(myStack, x);
}

int main(){
    stack<int> s;
    s.push(7);
    s.push(1);
    s.push(4);

    pushAtBottom(s, 9);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

/*
MISTAKES TO AVOID:
1. Passing stack by value.
   - Changes occur on a copy instead of the original stack.

2. Forgetting the base case:
   if(s.empty())
   - Without it, recursion never stops.

3. Pushing x before reaching the empty stack.
   - x must be inserted only when the stack is empty.

4. Forgetting to push popped elements back during backtracking.
   - The original stack contents would be lost.

5. Confusing top insertion with bottom insertion.
   - s.push(x) directly inserts at the top, not the bottom.

GOLDEN INTERVIEW TIPS:
1. Whenever a stack problem asks to modify something
   below the top element, recursion is often the key.

2. The standard recursive stack pattern is:
   Pop
   Recursive Call
   Push Back

3. Think of recursion as a hidden auxiliary stack.

4. Many stack interview questions are built on this idea:
   - Insert at bottom
   - Reverse stack
   - Sort stack
   - Delete middle element

5. If you can solve "Insert at Bottom",
   you can usually build solutions for
   "Reverse Stack" and "Sort Stack" easily.
*/