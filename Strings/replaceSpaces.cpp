#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
---------
Given a string, replace every space character ' ' with the string "@40".
The input may contain spaces anywhere (beginning, middle, or end).
Return the modified string.

Example:
Input  : "hello world"
Output : "hello@40world"

Input  : "a b c"
Output : "a@40b@40c"

APPROACH:
----------
1. Create an empty string called `result`.
2. Traverse the input string character by character.
3. For each character:
      - If it is a space (' '), append "@40" to result.
      - Otherwise, append the character itself.
4. Return the final result string.

WHY THIS APPROACH WORKS:
-------------------------
- We scan the string exactly once.
- Whenever we encounter a space, we replace it with three characters.
- Since one character is being replaced by multiple characters,
  we build a new string instead of modifying in-place.
- This guarantees correct replacement without overwriting issues.

TIME COMPLEXITY:
-----------------
O(n)
We traverse the string once, where n is the length of the string.

SPACE COMPLEXITY:
------------------
O(n)
We create a new string that may be larger than the original string
(in the worst case, if all characters are spaces).
*/

string replaceSpaces(string s){
    string result;
    for(int i = 0; i<s.length(); i++){
        if(s[i]==' ') result+="@40";
        else result+=s[i];
    }
    return result;
}

int main(){
    string input;
    getline(cin,input);
    cout<<replaceSpaces(input);
}

/*
MISTAKES I MADE EARLIER (TO AVOID NEXT TIME):
-----------------------------------------------
1. Tried using std::replace() to replace a character with a string.
   - std::replace only replaces a character with another character,
     not with a string.

2. Overcomplicated the logic using two pointers (i and j),
   even though this problem only required simple linear traversal.

3. Added unnecessary boundary checks like:
       if(i > s.length()) break;
   which were redundant due to the loop condition.

4. Forgot that when replacing one character with multiple characters,
   building a new string is usually the simplest and safest approach.
*/