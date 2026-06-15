#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:
Sort a stack using recursion without using any
extra data structure.

Example:

Top
3
-7
9
-2
5

After sorting:

Top
9
5
3
-2
-7

APPROACH:
1. Remove the top element recursively until the stack becomes empty.
2. Recursively sort the remaining stack.
3. Insert the removed element into its correct position
   using a helper function (sortedInsert).
4. Repeat while recursion unwinds.

WHY IT WORKS:
- The recursive call sorts a smaller stack.
- sortedInsert places the current element into the
  correct position of the already sorted stack.
- Eventually all elements are inserted in sorted order.

TIME COMPLEXITY:
O(N²)

SPACE COMPLEXITY:
O(N)   // Recursive call stack
*/

void sortedInsert(stack<int>& s, int num){
    if(s.empty() || s.top() < num){
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    sortedInsert(s, num);

    s.push(n);
}

void sortStack(stack<int>& s){
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    sortStack(s);

    sortedInsert(s, num);
}

int main(){
    stack<int> s;

    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sortStack(s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

/*
MISTAKES TO AVOID:
1. Restoring the wrong element after recursion.
   - Use s.push(n), not s.push(num).

2. Passing stack by value.
   - Always use stack<int>& for in-place modifications.

3. Forgetting the insertion condition:
   if(s.empty() || s.top() < num)

4. Mixing ascending and descending order logic.
   - Changing < to > changes the final ordering.

5. Forgetting that sortedInsert itself is recursive.
   - Both functions work together.

GOLDEN INTERVIEW TIPS:
1. Sort Stack is an extension of Insert At Bottom.

2. The standard recursion pattern is:
   Remove element
   Solve smaller problem
   Insert element back correctly

3. Whenever a problem says:
   "Sort without extra data structures"
   think recursion.

4. The helper function should answer:
   "How do I insert one element into an already
   sorted stack?"

5. Many recursive interview problems follow:
   Break problem into a smaller version,
   solve it recursively,
   then rebuild the answer during backtracking.
*/