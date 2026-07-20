#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- APPROACH ----------------------------------

Problem:
Given a stream of characters, after each character arrives,
print the first non-repeating character seen so far.
If none exists, print '#'.

Algorithm:
1. Maintain a frequency map of every character.
2. Push every incoming character into a queue.
3. While the front character has frequency > 1,
   remove it from the queue.
4. The front of the queue (if any) is the first non-repeating
   character at this moment.
5. If the queue becomes empty, append '#'.

Example:
Input: "aabc"

'a' -> Queue=[a]      Answer="a"
'a' -> Queue=[]       Answer="a#"
'b' -> Queue=[b]      Answer="a#b"
'c' -> Queue=[b,c]    Answer="a#bb"

Final Answer = "a#bb"

Time Complexity: O(N)
Space Complexity: O(N)
*/

string FirstNonRepeating(string A){
    unordered_map<char,int> count;
    queue<char> q;
    string ans = "";

    for(int i = 0; i < A.length(); i++){
        char ch = A[i];
        count[ch]++;
        q.push(ch);

        while(!q.empty()){
            if(count[q.front()] > 1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty())
            ans.push_back('#');
    }

    return ans;
}

int main(){

    string A = "aabc";

    cout << "Input Stream: " << A << endl;
    cout << "Output: " << FirstNonRepeating(A) << endl;

    return 0;
}

/*
--------------------------- INTERVIEW NOTES ----------------------------------

Why does this work?
- The queue stores characters in the order they appear.
- The frequency map tells whether a character has become repeating.
- Removing repeated characters from the front guarantees that
  the queue's front is always the first non-repeating character.

Common Mistakes:
1. Forgetting to remove repeated characters from the queue.
2. Appending '#' before checking whether the queue is empty.
3. Trying to search the entire string after every character,
   resulting in O(N²) complexity.
4. Using only a frequency map without preserving insertion order.

Key Insight:
The queue maintains arrival order,
while the hash map tracks frequencies.
Their combination gives an O(N) solution.

Pattern:
Queue + Hash Map
(First Non-Repeating Character in a Stream)
*/