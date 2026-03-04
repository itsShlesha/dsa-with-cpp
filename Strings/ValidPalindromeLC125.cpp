#include <bits/stdc++.h>
using namespace std;
/*
Problem: Valid Palindrome (LeetCode 125)

Given:
- A string s
- It may contain letters, digits, spaces, and special characters

Goal:
Return true if the string is a palindrome,
considering only alphanumeric characters
and ignoring cases.

Meaning:
- Ignore spaces
- Ignore punctuation
- Compare case-insensitively

Approach & Concept:
This is a Two Pointer problem.

We use:
- start pointer from beginning
- end pointer from last index

At every step:
1. Skip non-alphanumeric characters.
2. Compare lowercase versions of characters.
3. If mismatch → return false.
4. Move both pointers inward.

Why this works:
We only care about meaningful characters.
Everything else is ignored.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/


bool isPalindrome(string s){
    int start = 0;
    int end = s.length() - 1;
    while(start<end){
        if(!isalnum(s[start])){start++; continue;}
        if(!isalnum(s[end])){end--; continue;}
        if(tolower(s[start])!=tolower(s[end])) return false;
        start++; end--;
    }
    return true;
}

int main(){
    string str;
    getline(cin,str);
    cout<<(isPalindrome(str)?"true":"false");
}

/*
Key Points / Mistakes to Avoid:

>> Always use getline() for problems involving spaces.

>> isalnum() checks if character is a letter or digit.

>> tolower() ensures case-insensitive comparison.

>> Order of checks matters:
   - First skip invalid characters
   - Then compare

>> Continue is important after skipping,
   otherwise you may compare invalid characters.

>> Loop condition must be start < end.
   No need to check equality when they meet.

>> This is a classic Two Pointer template
   for string filtering + comparison.

>> Think in terms of:
   - Skip
   - Compare
   - Move
*/