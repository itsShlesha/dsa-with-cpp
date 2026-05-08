#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
Given an nxn matrix containing:
1 -> open path
0 -> blocked path

Find ALL possible paths from:
START = (0,0)
END   = (n-1,n-1)

Allowed moves:
D -> Down
R -> Right
L -> Left
U -> Up

MAIN IDEA:
Use RECURSION + BACKTRACKING

At every cell:
1. Mark current cell visited
2. Try all 4 directions
3. If move is safe:
      move there recursively
4. After recursion:
      undo move (BACKTRACK)
5. Unmark visited before returning

WHY VISITED ARRAY?
Without visited array,
rat may move in circles forever.

Example:
(0,0) -> (0,1) -> (0,0) -> ...

visited prevents revisiting cells
in the SAME PATH.

TIME COMPLEXITY:
Worst Case:
O(4^(n*n))

because from each cell
up to 4 directions are possible.

SPACE COMPLEXITY:
O(n*n)
visited array + recursion stack

*/


bool isSafe(vector<vector<int>>&m, int n, int newx, int newy, vector<vector<int>>&visited){
    if( newx >= 0 && newx < n &&
        newy >= 0 && newy < n &&
        visited[newx][newy] == 0 &&
        m[newx][newy] == 1){
            return true;
    }
    return false;
}

void solve(vector<vector<int>>&m, int n, int x, int y, vector<vector<int>>&visited, string path, vector<string>&ans){
    //base case
    if( x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    //directions possible to explore: DOWN(D), RIGHT(R), LEFT(L), UP(U);

    //DOWN
    int newx = x+1;
    int newy = y;
    if(isSafe(m, n, newx, newy, visited)){
        path.push_back('D');
        solve(m, n, newx, newy, visited, path, ans);
        path.pop_back();
    }

    //RIGHT
    newx = x;
    newy = y+1;
    if(isSafe(m,n,newx,newy,visited)){
        path.push_back('R');
        solve(m,n,newx,newy,visited,path,ans);
        path.pop_back();
    }

    //LEFT
    newx = x;
    newy = y-1;
    if(isSafe(m,n,newx,newy,visited)){
        path.push_back('L');
        solve(m,n,newx,newy,visited,path,ans);
        path.pop_back();
    }

    //UP
    newx = x-1;
    newy = y;
    if(isSafe(m,n,newx,newy,visited)){
        path.push_back('U');
        solve(m,n,newx,newy,visited,path,ans);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>>&m, int n){
    vector<string> ans;

    if(m[0][0] == 0) return ans;

    string path = "";
    int srcx = 0; 
    int srcy = 0;

    vector<vector<int>> visited = m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }

    solve(m,n,srcx,srcy,visited,path, ans);
    return ans;
}

int main(){
    cout<<"Enter 'n' for nxn matrix: "<<endl;
    int n; cin>>n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    vector<string> pathvector = findPath(arr, n);
    
    for(auto x:pathvector){
        for(auto y:x){
            cout<<x<<endl;
        }
    }
}

/*
------>>>MISTAKES TO AVOID

1. FORGETTING TO BACKTRACK
MOST COMMON ERROR.

If you mark:
visited[x][y] = 1;

you MUST later do:
visited[x][y] = 0;

Otherwise:
other valid paths cannot use that cell.

2. NOT CHECKING VISITED ARRAY
Without visited check,
recursion may go in infinite loop.

Example:
A -> B -> A -> B -> ...

Always check:
visited[newx][newy] == 0

3. MODIFYING ORIGINAL MATRIX
Some students directly change maze values.

Example:
m[x][y] = 0;

This can destroy original data.

Better:
use separate visited matrix.

4. WRONG BASE CASE
Correct:
if(x == n-1 && y == n-1)

Do NOT stop early.

5. FORGETTING BOUNDARY CHECK
Always ensure:

newx >= 0
newx < n
newy >= 0
newy < n

Otherwise:
runtime error / segmentation fault.

6. NOT POPPING PATH CHARACTER
After recursion:

path.pop_back();

must be done.

Otherwise:
path string becomes incorrect.

7. PASSING VISITED BY VALUE
Bad:
vector<vector<int>> visited

This copies entire matrix every call.

Better:
vector<vector<int>>& visited

(pass by reference)

---->>>INTERVIEW TIPS

1. ALWAYS SAY:
"This is a classic backtracking problem."

Interviewers LIKE hearing:
- recursion
- backtracking
- state space exploration

2. EXPLAIN BACKTRACKING CLEARLY
Tell interviewer:

"After exploring one path,
I undo changes so other paths
can reuse the cell."

That is the CORE idea.

3. TALK ABOUT DIRECTION ARRAYS
Optimized version uses:

dx[] = {1,0,0,-1}
dy[] = {0,1,-1,0}

and direction string:
"DRLU"

This avoids repeated code.

4. EXPLAIN WHY VISITED IS NEEDED
Important conceptual point.

Without visited:
infinite recursion possible.

5. IF ASKED OPTIMIZATION
You can say:

- use direction arrays
- avoid string copying
- use references carefully

6. COMMON FOLLOW-UP QUESTIONS
Interviewers may ask:

- Count total paths only?
- Print shortest path?
- Can moves be diagonal?
- What if matrix is rectangular?
- BFS instead of DFS?

7. BIG INTERVIEW KEYWORD
DFS + BACKTRACKING

This problem is basically:
Depth First Search on matrix.

*/