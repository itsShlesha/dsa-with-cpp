#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
PROBLEM: Implement N Stacks in an Array
===========================================================

Problem Statement:
Design N stacks using only one array of size S.

Operations:
1. push(x, m) -> Push element x into m-th stack.
2. pop(m) -> Pop from m-th stack.

Both operations should work in O(1).

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------

Three arrays are maintained.

1. arr[]
Stores the actual stack elements.

2. top[]
Stores the index of the top element of every stack.

top[i] = top of (i+1)th stack.

3. next[]
Acts as both:

• Link between elements of the same stack.
• Free list of available indices.

Initially:

next = [1,2,3,4,...,-1]

freespot = 0

-----------------------------------------------------------
PUSH OPERATION
-----------------------------------------------------------

Step 1:
Take the first free index.

Step 2:
Move freespot to the next available location.

Step 3:
Insert the new element.

Step 4:
Link the new node with the previous top.

Step 5:
Update top of that stack.

-----------------------------------------------------------
POP OPERATION
-----------------------------------------------------------

Step 1:
Take the top index.

Step 2:
Move top to the next element.

Step 3:
Return the removed index to the free list.

Step 4:
Update freespot.

-----------------------------------------------------------
WHY THIS APPROACH WORKS
-----------------------------------------------------------

Instead of dividing the array into fixed portions,
every stack grows dynamically.

Whenever a cell becomes free,
it is immediately available for any stack.

Thus no space is wasted.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

Push : O(1)

Pop : O(1)

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(S + N)

arr[]  -> S

next[] -> S

top[]  -> N
*/

class Nstack{
    int *arr;
    int *top;
    int *next;

    int n,s;

    int freespot;

public:
    Nstack(int N, int S){
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //top initialise
        for(int i=0; i<n; i++){
            top[i] = -1;
        }

        //next initialise
        for(int i=0; i<S; i++){
            next[i] = i+1;
        }

        //update last index value to -1
        next[s-1] = -1;

        //initialise freespot
        freespot = 0;
    }

    bool push(int x, int m){
        if(freespot == -1) return false;

        int index = freespot;

        freespot = next[index];

        arr[index] = x;

        next[index] = top[m-1];

        top[m-1] = index;

        return true;
    }

    bool pop(int m){
        if(top[m-1]==-1) return false;

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return true;
    }
};

int main() {

    Nstack st(3, 6);   // 3 stacks in an array of size 6

    st.push(10, 1);
    st.push(20, 1);

    st.push(30, 2);
    st.push(40, 2);

    st.push(50, 3);

    cout << "Pop from Stack 1: ";
    cout << (st.pop(1) ? "Success" : "Failed") << endl;

    cout << "Pop from Stack 2: ";
    cout << (st.pop(2) ? "Success" : "Failed") << endl;

    cout << "Pop from Stack 3: ";
    cout << (st.pop(3) ? "Success" : "Failed") << endl;

    return 0;
}

/*
===========================================================
IMPORTANT NOTES / INTERVIEW TIPS
===========================================================

Mistakes to Avoid
-----------------
1. Forgetting to allocate memory for next[].

2. Using top[m] instead of top[m-1].

3. Forgetting to update freespot after push.

4. Forgetting to return the removed index back
   to the free list during pop.

5. Returning false when stack is empty or
   array becomes full.

-----------------------------------------------------------
INTERVIEW INSIGHT
-----------------------------------------------------------

The trick is that next[] performs two jobs:

• Stack linkage
• Free-space management

This allows all stacks to share the same array
efficiently.

-----------------------------------------------------------
PATTERN
-----------------------------------------------------------

✓ Stack
✓ Array
✓ Linked List Simulation
✓ Space Optimization

-----------------------------------------------------------
GOLDEN TIP
-----------------------------------------------------------

Whenever multiple dynamic structures need to share
a fixed-size array, maintain a free-list to recycle
unused positions.

-----------------------------------------------------------
ONE-LINE SUMMARY
-----------------------------------------------------------

Use top[] for stack heads, next[] for both links and
free-space management, and freespot to track the next
available index.
*/