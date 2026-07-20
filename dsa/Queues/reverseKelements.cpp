#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- APPROACH ----------------------------------

Problem:
Reverse the first K elements of a queue while keeping the remaining
elements in the same relative order.

Algorithm:
1. Remove the first K elements from the queue and push them into a stack.
2. Pop all elements from the stack back into the queue.
   -> Their order gets reversed because of the stack's LIFO nature.
3. The remaining (n-K) elements are now at the front.
   Rotate them to the back one by one to restore their original order.

Example:
Queue = [1,2,3,4,5], K = 3

After stack insertion:
Stack = [3,2,1]
Queue = [4,5]

After pushing back:
Queue = [4,5,3,2,1]

Rotate first (5-3)=2 elements:
[5,3,2,1,4]
[3,2,1,4,5]

Final Answer:
[3,2,1,4,5]

Time Complexity: O(N)
Space Complexity: O(K)
*/

queue<int> modifyQueue(queue<int> q, int k){
    stack<int> s;

    for(int i = 0; i < k; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }

    int t = q.size() - k;

    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

int main(){

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    queue<int> ans = modifyQueue(q, k);

    cout << "Modified Queue: ";

    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }

    return 0;
}

/*
--------------------------- INTERVIEW NOTES ----------------------------------

Why does this work?
- Stack reverses the first K elements automatically.
- Rotating the remaining (N-K) elements restores their original order
  after the reversed part.

Common Mistakes:
1. Forgetting to rotate the remaining (N-K) elements.
2. Using q.size() inside the rotation loop after modifying the queue.
3. Not handling edge cases like:
   - K = 0
   - K = N
   - Empty queue
4. Passing the queue by reference when the original queue should remain
   unchanged.

Key Insight:
Queue preserves order, Stack reverses order.
Combining both lets us reverse only a prefix of the queue in linear time.

Pattern:
Queue + Stack Hybrid
(Reverse first K elements of a Queue)
*/