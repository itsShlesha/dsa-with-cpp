#include <bits/stdc++.h>
using namespace std;

/*
Problem: Permutation in String

Given:
- String s1
- String s2

Goal:
Return true if s2 contains a permutation of s1.

Meaning:
Some substring of s2 must be an anagram of s1.

Example:
s1 = "ab"
s2 = "eidbaooo"

"ba" exists inside s2 → return true

Approach & Concept:
This is a Sliding Window + Frequency Count problem.

Core Idea:
Two strings are anagrams if:
Their character frequency arrays are identical.

Steps:
1. Build frequency array for s1.
2. Create a sliding window of size = length(s1) on s2.
3. For each window:
   - Compare frequency arrays.
   - If equal → return true.
4. Slide window by:
   - Adding new character
   - Removing old character


Time Complexity:
O(26 * n) ≈ O(n)
Because:
- For each slide, we compare 26 elements.

Space Complexity:
O(1)
(Only 26-length arrays used)
*/

bool checkEqual(int a[26], int b[26]){
    for(int i = 0; i<26; i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2){
    if(s1.length() > s2.length()) return false;

    int count1[26] = {0};
    for(int i=0; i<s1.length(); i++){
        count1[s1[i]-'a']++;
    }

    int k = s1.length();
    int count2[26] = {0};

    //building first window
    for(int i=0; i<k; i++){
        count2[s2[i]-'a']++;
    }

    if(checkEqual(count1,count2)) return true;

    //slide window
    for(int i=k; i<s2.length(); i++){
        count2[s2[i]-'a']++;
        count2[s2[i-k]-'a']--;
        if(checkEqual(count1,count2)) return true;
    }

    return false;
}

int main(){
    cout<<"Enter string1: "<<endl;
    string s1, s2;
    getline(cin, s1);
    cout<<"Enter string 2: "<<endl;
    getline(cin, s2);
    cout<<"Does string 2 contain permutation of string 1? "<<(checkInclusion(s1,s2)?"true":"false")<<endl;
}

/*
Key Points / Mistakes to Avoid:

>> Assumes lowercase letters only.
   (s[i] - 'a' works only for 'a' to 'z').

>> Window size must always remain equal to s1.length().

>> Sliding window means:
   - Add one element
   - Remove one element
   - Maintain window size constant

>> checkEqual runs 26 comparisons only,
   so it’s constant time.

>> Always handle base case:
   if(s1.length() > s2.length()) return false;


Pattern Recognized: Fixed Size Sliding Window

Template Thinking:
1. Build frequency for pattern
2. Build first window
3. Compare
4. Slide window:
   - Add new
   - Remove old
   - Compare again

This same pattern applies to:
- Anagrams in a string
- Permutation detection
- Fixed window substring problems
*/