#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
PROBLEM: Celebrity Problem
===========================================================

Problem Statement:
Given an N x N matrix M where:
- M[i][j] = 1 means person i knows person j.
- M[i][j] = 0 means person i does not know person j.

A celebrity is someone who:
1. Knows nobody.
2. Is known by everyone else.

Return the index of the celebrity if one exists,
otherwise return -1.

-----------------------------------------------------------
APPROACH (Stack Elimination)
-----------------------------------------------------------

Step 1:
Push all people (0 to n-1) into a stack.

Step 2:
Repeatedly compare the top two people.

Suppose they are A and B.

Case 1:
If A knows B,
A cannot be a celebrity.
Keep B.

Case 2:
If A does NOT know B,
B cannot be a celebrity.
Keep A.

Continue until only one person remains.

This person is only a POTENTIAL celebrity.

Step 3:
Verify the candidate.

Condition 1:
Entire row should contain only 0s.
(Celebrity knows nobody.)

Condition 2:
Entire column except diagonal should contain 1s.
(Everyone knows the celebrity.)

If both conditions are satisfied,
return candidate.
Else return -1.

-----------------------------------------------------------
WHY THIS APPROACH WORKS
-----------------------------------------------------------

Every comparison removes exactly one non-celeb.

Reason:
If A knows B,
A can never be celebrity.

If A doesn't know B,
B can never be celebrity.

Thus after N-1 eliminations,
only one possible celebrity remains.

Verification guarantees correctness.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

Stack elimination : O(N)

Row verification  : O(N)

Column verification : O(N)

Overall : O(N)

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(N)
(Stack stores all people.)
*/

bool knows(vector<vector<int>>& M, int a, int b){
    if(M[a][b] == 1) return true;
    return false;
}

int celebrity(vector<vector<int>>& M, int n){
    stack<int> s;
    //step 1: push all elements onto the stack
    for(int i=0; i<n; i++){
        s.push(i);
    }

    //step 2: loop and eliminate till potential celebrity found
    while(s.size() != 1){
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();

        if (knows(M,a,b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int candidate = s.top();

    //step 3: verify if the potential celebrity is actually one or not
    int zeroCount = 0;
    for(int i=0; i<n; i++){
        if(M[candidate][i] == 0){
            zeroCount++;
        }
    }

    if(zeroCount != n) return -1;

    int oneCount = 0;
    for(int i=0; i<n; i++){
        if(M[i][candidate] == 1){
            oneCount++;
        }
    }

    if(oneCount != n-1) return -1;

    return candidate;
}

int main() {

    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    int n = M.size();

    int ans = celebrity(M, n);

    if (ans == -1)
        cout << "No Celebrity Found";
    else
        cout << "Celebrity is Person " << ans;

    return 0;
}

/*
===========================================================
IMPORTANT NOTES / INTERVIEW TIPS
===========================================================

Mistakes to Avoid
-----------------
1. Forgetting to verify the final candidate.
   Elimination only gives a possible celebrity.

2. While checking the row,
   every value should be 0.

3. While checking the column,
   count should be exactly (n-1)
   because celebrity doesn't know themselves.

4. Do not compare everyone with everyone.
   That becomes O(N²).

5. Carefully pop two elements before comparison.

-----------------------------------------------------------
INTERVIEW INSIGHT
-----------------------------------------------------------

This is an elimination technique.

Each comparison removes one impossible candidate,
reducing the search space from N to 1.

This is a common interview optimization over
the brute-force O(N²) approach.

-----------------------------------------------------------
PATTERN
-----------------------------------------------------------

✓ Stack
✓ Candidate Elimination
✓ Matrix
✓ Verification
✓ Simulation

-----------------------------------------------------------
GOLDEN TIP
-----------------------------------------------------------

Whenever a problem asks for finding ONE special
candidate satisfying some property among many,
think of eliminating impossible candidates first,
then verifying the last remaining one.

Examples:
• Celebrity Problem
• Majority Element (Moore's Voting)
• Tournament Winner
• Candidate Elimination Problems

-----------------------------------------------------------
ONE-LINE SUMMARY
-----------------------------------------------------------

Use pairwise elimination to find one possible celebrity,
then verify their row and column in O(N).
*/