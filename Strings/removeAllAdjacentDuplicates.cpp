#include <bits/stdc++.h>
using namespace std;

/*
Problem: Remove All Adjacent Duplicates In String

Given:
- A string s

Goal:
Remove adjacent duplicate characters repeatedly
until no duplicates remain.

Example:
Input:  "abbaca"

Process:
"abbaca"
→ remove "bb" → "aaca"
→ remove "aa" → "ca"

Output:
"ca"

Approach & Concept:
This is a Stack-based problem.

Core Idea:
When we see two adjacent equal characters,
we remove them.

Instead of using an actual stack,
we use a string (result) as a stack.

Operations used:
- result.back()  → top of stack
- result.pop_back() → pop
- result += char → push

Time Complexity:
O(n)

Space Complexity:
O(n)
(In worst case, no duplicates removed)
*/

string removeDuplicates(string s){
    string result;
    for(int i=0; i<s.length(); i++){
        if(result.empty()) result+=s[i];
        else if(result.back()==s[i]) result.pop_back();
        else result+=s[i];
    }
    return result;
}

int main(){
    string s;
    getline(cin, s);
    cout<<removeDuplicates(s);
}

/*
Key Points / Mistakes to Avoid:

>> Think of result as a stack.

>> result.back() gives last character.

>> pop_back() removes last character.

>> Every character is pushed once
   and popped at most once.

>> That is why time complexity is O(n).


Pattern Recognized: "Use string as stack"

Template Thinking:
For each character:
    if stack not empty AND top == current
        pop
    else
        push

This same pattern applies to:
- Removing adjacent duplicates
- Valid parentheses
- Simplifying paths
- Backspace string compare
*/