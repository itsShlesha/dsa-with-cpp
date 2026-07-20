#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- APPROACH ----------------------------------

Problem:
Given a queue of even length, interleave its first half with the
second half.

CONSTRAINT: Only use a stack in the auxiliary space

Example:
Input : [11,12,13,14,15,16]
Output: [11,14,12,15,13,16]

Algorithm:
1. Push the first half of the queue into a stack.
2. Pop the stack back into the queue.
   -> First half gets reversed.
3. Rotate the queue so that the reversed first half moves to the back.
4. Push the first half (original order restored) into the stack.
5. Alternately:
      - Pop one element from the stack.
      - Take one element from the queue.
   This interleaves both halves.

Dry Run:

Initial Queue:
[11,12,13,14,15,16]

After Step 1:
Stack = [13,12,11]
Queue = [14,15,16]

After Step 2:
Queue = [14,15,16,13,12,11]

After Step 3:
Queue = [13,12,11,14,15,16]

After Step 4:
Stack = [11,12,13]
Queue = [14,15,16]

Step 5:
11 14
12 15
13 16

Final Queue:
[11,14,12,15,13,16]

Time Complexity: O(N)
Space Complexity: O(N)

OPTIMAL:
queue<int> interleave(queue<int> q){
    queue<int> firstHalf;

    int n = q.size();

    // Store the first half in another queue
    for(int i = 0; i < n/2; i++){
        firstHalf.push(q.front());
        q.pop();
    }

    // Interleave the two halves
    while(!firstHalf.empty()){
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }

    return q;
}
*/

queue<int> interleave(queue<int> q){
    stack<int> s;
    int firstHalfLength = q.size() / 2;

    // Step 1: Push first half into stack
    for(int i = 0; i < firstHalfLength; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // Step 2: Append stack elements back into queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move first half to the back
    for(int i = 0; i < firstHalfLength; i++){
        q.push(q.front());
        q.pop();
    }

    // Step 4: Push first half into stack again
    for(int i = 0; i < firstHalfLength; i++){
        s.push(q.front());
        q.pop();
    }

    // Step 5: Interleave both halves
    while(!s.empty()){
        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();
    }

    return q;
}

int main(){

    queue<int> q;

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);

    queue<int> ans = interleave(q);

    cout << "Interleaved Queue: ";

    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }

    return 0;
}

/*
--------------------------- INTERVIEW NOTES ----------------------------------

Why does this work?
- The stack temporarily reverses the first half.
- After a rotation, pushing the first half into the stack again
  restores its original order.
- Alternating between the stack and queue naturally interleaves
  the two halves.

Common Mistakes:
1. Applying this algorithm to an odd-sized queue.
2. Forgetting the rotation step after pushing stack elements back.
3. Using q.size() inside loops after modifying the queue.
4. Pushing/popping in the wrong order during the final interleaving.

Key Insight:
The stack is only used as temporary storage to rearrange the first
half so that alternating elements from both halves becomes easy.

Pattern:
Queue + Stack
(Interleave First Half with Second Half of a Queue)
*/