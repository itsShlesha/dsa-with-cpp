#include <bits/stdc++.h>
using namespace std;

/*
Problem: Reverse Words in a String (Partial In-Place Version)

Given:
- A string s with words separated by spaces

Goal:
Reverse each individual word in the string.

NOTE:
This version does NOT reverse the order of words.
It only reverses characters inside each word.

Example:
Input:  "the sky is blue"
Output: "eht yks si eulb"

Approach & Concept:
This is a Two Pointer + In-Place Reversal problem.

Main Idea:
1. Traverse the string.
2. Skip spaces.
3. Identify a word using two pointers:
   - i = start of word
   - j = end of word
4. Reverse the word in-place using STL reverse().

Time Complexity:
O(n)

Space Complexity:
O(1)
(No extra string used)
*/

string reverseWords(string s){
    int i = 0; int n = s.length();
    while(i<n){
        while(i<n && s[i]==' ')i++;
        int j = i;
        while(j<n && s[j]!=' ')j++;
        reverse(s.begin()+i, s.begin()+j);
        i=j;
    }
    return s;
}

int main(){
    string s;
    getline(cin, s);
    cout<<reverseWords(s);
}

/*
Key Points / Mistakes to Avoid:

>> Always check boundary: i < n before accessing s[i].

>> reverse(begin, end) works in half-open interval:
   [begin, end)

>> i = j is necessary,
   otherwise infinite loop.

>> This does NOT reverse word order.
   It only reverses characters inside each word.

Important Observation:

If you want to:
Reverse the order of words (like LC151),
you must first reverse the entire string,
then reverse each word individually.

This version skips that first step.


Pattern Recognized:

"Traverse → Detect Word → Reverse Range"

Common template when:
- You need to modify words in-place
- No extra space allowed
*/