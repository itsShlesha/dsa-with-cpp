#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:
Given a stack of N elements, delete the middle element
without using any extra data structure.

Example:
Stack (top -> bottom): 30 20 10

After deleting middle element:
30 10

APPROACH:
1. Use recursion to reach the middle element.
2. Keep removing elements from the top while counting recursion depth.
3. When count == N/2, remove the middle element.
4. While recursion unwinds, push all previously removed elements back.

WHY IT WORKS:
- Recursion acts as the temporary storage.
- We remove elements one by one until the middle is reached.
- The middle element is discarded.
- Remaining elements are restored in their original order.

TIME COMPLEXITY:
O(N)

SPACE COMPLEXITY:
O(N)  // Recursive call stack
*/

void solve(stack<int>&inputStack, int count, int N){
    if(count == N/2){
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();

    //recursive call
    solve(inputStack, count+1, N);

    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
    int count = 0;
    solve(inputStack, count, N);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    deleteMiddle(s, s.size());
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

/*
MISTAKES TO AVOID:
1. Passing stack by value instead of reference.
   - Changes will happen on a copy and the original stack remains unchanged.

2. Forgetting the base condition:
   - if(count == N/2)
   - This is where the middle element must be removed.

3. Pushing the middle element back during backtracking.
   - Only non-middle elements should be restored.

4. Incorrect middle calculation for even-sized stacks.
   - Verify which middle element the problem expects.

5. Printing the stack incorrectly.
   - top() only returns the top element.
   - Use pop() while traversing to actually view elements.

GOLDEN INTERVIEW TIPS:
1. Whenever a problem says "without extra data structure",
   think about using recursion because the call stack can
   act as hidden storage.

2. For stack recursion problems, the pattern is:
   - Pop
   - Recursive Call
   - Push Back (Backtracking)

3. If an element needs to be removed from somewhere other
   than the top of the stack, recursion is often a strong hint.

4. Always ask:
   "What information must survive after recursion?"
   Those are the elements you push back while unwinding.

5. A common interview follow-up is:
   "Can you do this iteratively?"
   Be ready to explain why recursion naturally fits this problem.
*/