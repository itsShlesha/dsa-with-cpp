#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:
Given a string of digits (2–9), return all possible letter combinations
that the number could represent based on a phone keypad mapping.

Example:
Input: "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

--------------------------------------------------------
APPROACH (BACKTRACKING):

At each digit:
- Get its corresponding letters from mapping
- Try each letter → recurse for next digit
- Undo the choice (backtrack)

This is a classic "multiple choices per step" problem.

--------------------------------------------------------
WHY THIS APPROACH?

Each digit has multiple possible letters.
We need ALL combinations → brute force all possibilities.

Backtracking helps:
- Explore all paths
- Avoid storing unnecessary states
- Build combinations incrementally

--->>>FULL RECURSION TREE (for "23"):
digits = "23"
mapping:
2 -> abc
3 -> def

Start:
                ""
        /        |        \
      "a"       "b"       "c"
     / | \     / | \     / | \
  "ad""ae""af""bd""be""bf""cd""ce""cf"

Each level = one digit
Each branch = one letter choice

TIME COMPLEXITY: O(4^n)
Why?
- Each digit can have up to 4 letters (7,9)
- Total combinations = product of choices
Example:
n = length of digits
Worst case = 4^n combinations


SPACE COMPLEXITY:
O(n) → recursion stack depth
+ O(4^n) → output storage (not counted in recursion space)
*/

void solve(string digits, string output, int index, string mapping[], vector<string>&ans){
    //base case
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        solve(digits, output, index+1, mapping, ans);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits){
    vector<string> ans;

    if(digits.length()==0) return ans;

    string output = "";
    int index = 0;

    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, output, index, mapping, ans);
    return ans;
}

int main(){
    cout<<"Enter the digits: "<<endl;
    string digits;
    cin>>digits;
    cout<<"The letter combinations for the phone number entered are: "<<endl;
    vector<string> ans = letterCombinations(digits);

    for(auto x: ans){
        cout<<"[";
        for(auto y: x){
            cout<<y;
        }
        cout<<"] ";
    }
}

/*
MISTAKES TO AVOID:

1. Using wrong variable name
   digit[index] instead of digits[index]

2. Forgetting backtracking
   Missing output.pop_back()
   → leads to wrong answers

3. Not handling empty input
   if(digits.length() == 0) return ans;

4. Wrong mapping
   Use "" not " " for 0 and 1

5. Passing by reference incorrectly
   output should be copied OR carefully backtracked

--------------------------------------------------------

GOLDEN INTERVIEW TIPS:

1. Always say:
   "This is a backtracking problem because each step has multiple choices."

2. Clearly define:
   - What is the state? → (index, output)
   - What is the decision? → pick a letter
   - What is the base case? → index == digits.length()

3. Use the template:
   choose → explore → unchoose

4. Draw a small recursion tree (like for "23")
   → Interviewers LOVE this

5. Optimize explanation:
   Don’t say "recursion does magic"
   Say:
   "We explore all possible combinations by fixing one character at a time"

6. If stuck:
   Convert to:
   "Generate all strings of length n using given choices"

--------------------------------------------------------

ONE-LINE SUMMARY:
"At every digit, try all possible letters and recursively build all combinations."

*/