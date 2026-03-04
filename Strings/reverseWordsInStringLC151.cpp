#include <bits/stdc++.h>
using namespace std;

/*
Problem: Reverse Words in a String

Given:
- A string s
- It may contain leading, trailing, or multiple spaces

Goal:
Return a string where:
- Words appear in reverse order
- Only single spaces separate words
- No leading or trailing spaces

Example:
Input:  "  the sky   is blue  "
Output: "blue is sky the"

Approach & Concept:
This is a String Manipulation + Two Pointer problem.

Main Idea:
1. Reverse the entire string.
2. Traverse the reversed string.
3. Extract each word.
4. Reverse that word again to restore its correct order.
5. Add it to result with single spacing.

Why this works:
When we reverse the entire string,
the order of words gets reversed,
but each individual word also becomes reversed.

So we reverse each word again
to fix their internal order.

Time Complexity:
O(n)

Space Complexity:
O(n)
(We build a separate result string)
*/


string reverseWords(string s){
    reverse(s.begin(), s.end());
    string result;
    int i = 0; int n = s.length();
    while(i<n){
        while(i<n && s[i]==' '){i++; continue;}
        int j = i;
        while(j<n && s[j]!=' '){j++;}

        if(i>=n) break;

        string str = s.substr(i,j-i);
        reverse(str.begin(), str.end());

        if(!result.empty()){result+=' ';}
        result+=str;
        i=j;
    }
    return result;
}

int main(){
    string s;
    getline(cin, s);
    cout<<reverseWords(s);
}

/*
Key Points / Mistakes to Avoid:

>> Always use getline() when spaces matter.

>> Reverse whole string first.
   Then fix individual words.

>> Skip spaces before extracting a word.
   This removes leading/multiple spaces automatically.

>> Only add space when result is not empty.
   This prevents trailing space.

>> i = j is important.
   Otherwise infinite loop.

>> This solution is NOT in-place.
   It uses extra space for result.

Pattern Recognized:

This is a classic:
"Reverse Entire String + Reverse Each Word"

Very common in interviews.

Template thinking:
1. Reverse whole
2. Iterate
3. Extract word
4. Reverse word
5. Append carefully
*/