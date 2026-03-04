#include <bits/stdc++.h>
using namespace std;


/*
Problem: Remove All Occurrences of a Substring

Given:
- A string s
- A string part

Goal:
Remove all occurrences of "part" from string s
until it no longer exists.

Example:
Input:
s = "daabcbaabcbc"
part = "abc"

Process:
"daabcbaabcbc"
→ remove "abc" → "dabaabcbc"
→ remove "abc" → "dababc"
→ remove "abc" → "dab"

Output:
"dab"

Approach & Concept:

We repeatedly:
1. Find the first occurrence of substring "part".
2. Erase it from string s.
3. Continue until "part" no longer exists in s.

We use:
- string::find()
- string::erase()

Important Understanding:

s.find(part) returns:
- Starting index if found
- string::npos if not found

string::npos is a very large value.

So condition:
s.find(part) < s.length()

means:
"part" was found in the string.

Time Complexity:
Worst case: O(n²)
Because:
- find() is O(n)
- erase() shifts characters O(n)
- and this may repeat many times

Space Complexity:
O(1)
(Modification done in same string)
*/

string removeOccurrences(string s, string part){
    while(s.length() && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main(){
    cout<<"Enter string: "<<endl;
    string s, part;
    getline(cin, s);
    cout<<"Enter the occurrence needed to be removed: "<<endl;
    getline(cin, part);
    cout<<removeOccurrences(s, part);
}

/*
Key Points / Mistakes to Avoid:

>> Always store s.find(part) in a variable
   instead of calling it twice (more efficient).

>> find() returns string::npos when not found.
   Comparing with s.length() works,
   but better practice is:

   while(s.find(part) != string::npos)

>> erase(index, length)
   removes 'length' characters starting at index.

>> This solution is simple but not optimal
   for very large strings.


Better Condition (Cleaner Version):

while(s.find(part) != string::npos) {
    s.erase(s.find(part), part.length());
}

Pattern Recognized: Repeated Search + Erase

Common in:
- String cleanup problems
- Simulation-based string problems
*/