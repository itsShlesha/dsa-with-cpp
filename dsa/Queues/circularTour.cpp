#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- APPROACH ----------------------------------

Problem:
Given N petrol pumps, each having petrol and the distance to the next
pump, find the first petrol pump from which a truck can complete the
entire circular tour. Return -1 if impossible.

Algorithm:
1. Maintain:
   - balance = current fuel remaining.
   - deficit = total fuel shortage encountered.
   - start = current candidate starting pump.
2. Traverse all petrol pumps.
3. At each pump:
      balance += petrol - distance
4. If balance becomes negative:
      - Current start cannot complete the tour.
      - Add balance to deficit.
      - Move start to the next pump.
      - Reset balance to 0.
5. After traversal:
      If deficit + balance >= 0,
      the candidate start is valid.
      Otherwise, no solution exists.

Example:
Petrol  = [4,6,7,4]
Distance= [6,5,3,5]

Start = 0
Pump0 -> balance = -2
Move start to 1

Continue...
Final answer = 1

Time Complexity: O(N)
Space Complexity: O(1)
*/

struct petrolPump{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n){
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for(int i = 0; i < n; i++){
        balance += (p[i].petrol - p[i].distance);

        if(balance < 0){
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if(deficit + balance >= 0){
        return start;
    }

    return -1;
}

int main(){

    petrolPump p[] = {
        {4, 6},
        {6, 5},
        {7, 3},
        {4, 5}
    };

    int n = sizeof(p) / sizeof(p[0]);

    int ans = tour(p, n);

    if(ans == -1)
        cout << "No possible tour exists.";
    else
        cout << "Start from petrol pump index: " << ans;

    return 0;
}

/*
--------------------------- INTERVIEW NOTES ----------------------------------

Why does this work?
- If we cannot reach pump (i+1) starting from 'start',
  then no pump between 'start' and 'i' can be a valid start.
- Therefore, we safely move the starting point to i+1.
- The final fuel check (deficit + balance) determines whether the
  total petrol is sufficient for the entire journey.

Common Mistakes:
1. Returning inside the traversal loop.
2. Forgetting to accumulate the deficit.
3. Resetting balance without updating the start index.
4. Not checking the final condition after processing all pumps.

Key Insight:
A failed journey eliminates every station visited so far as a possible
starting point, allowing a single-pass greedy solution.

Pattern:
Greedy + Running Balance
(Circular Tour / Gas Station Problem)
*/