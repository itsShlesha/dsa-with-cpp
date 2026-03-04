#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
---------
Given a string containing only lowercase letters (a–z),
find and return the character that appears the maximum number of times.

Example:
Input  : "aabccc"
Output : 'c'
Because:
a → 2 times
b → 1 time
c → 3 times (maximum)

APPROACH USED:
--------------
1. Create a frequency array of size 26.
   Each index represents a lowercase character:
   index 0 → 'a'
   index 1 → 'b'
   ...
   index 25 → 'z'

2. Traverse the string once.
   For each character:
       index = s[i] - 'a'
       Increment arr[index]

3. Traverse the frequency array (size 26)
   Find the index with the maximum count.

4. Convert that index back to character:
       char result = 'a' + index

WHY THIS WORKS:
---------------
- Since the string contains only lowercase letters,
  there are only 26 possible characters.
- Instead of comparing characters repeatedly,
  we count their frequencies in one pass.
- After counting, we simply find the maximum frequency.

This avoids nested loops and keeps the solution efficient.

Time Complexity = O(n)
(26 is constant, so it does not affect overall complexity)
Space Complexity = O(1)
(Constant space because 26 is fixed and does not depend on input size)
*/

char maxOccurringChar(string s){
    int arr[26] = {0};
    for(int i=0; i<s.length(); i++){
        int number =0;
        if(s[i]>='a' && s[i]<='z'){number = s[i]-'a';}
        else{number = s[i]-'A';}
        arr[number]++;
    }
    int maxi = -1, ans=0;
    for(int i=0; i<26; i++){
        if(maxi<arr[i]){
            ans = i; maxi = arr[i];
        }
    }

    char finalAns = 'a' + ans;
    return finalAns;
}

int main(){
    string input;
    cin>>input;
    cout<<maxOccurringChar(input);
}

/*
COMMON MISTAKES TO AVOID:
--------------------------
1. Handling uppercase letters when the problem guarantees lowercase.
   (Unnecessary logic adds confusion.)

2. Forgetting that:
       index = s[i] - 'a'
   works only when characters are lowercase.

3. Not thinking about tie cases.
   If two characters have same frequency,
   this code returns the lexicographically smaller one.
*/