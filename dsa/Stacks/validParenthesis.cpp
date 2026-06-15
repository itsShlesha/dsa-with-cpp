#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:
Given a string containing brackets '()', '{}', and '[]',
determine whether the parentheses are valid.

A valid expression must:
1. Have matching opening and closing brackets.
2. Follow the correct nesting order.

Example:
"{[]}"  -> true
"{([)}" -> false

APPROACH:
1. Traverse the string.
2. Push every opening bracket onto the stack.
3. For every closing bracket:
   - Check if stack is empty.
   - Verify that the top contains the corresponding opening bracket.
   - If matched, pop it.
   - Otherwise return false.
4. After traversal, the stack should be empty.

WHY IT WORKS:
- The most recently opened bracket must be closed first.
- A stack naturally follows this LIFO behavior.
- Any mismatch or leftover opening bracket makes
  the expression invalid.

TIME COMPLEXITY:
O(N)

SPACE COMPLEXITY:
O(N)
*/

bool validParenthesis(string &expression){
    stack<char> s;

    for(int i = 0; i < expression.length(); i++){
        char ch = expression[i];

        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top = s.top();

                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '[')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    return s.empty();
}

int main(){
    string expression = "{([])}";
    bool ans = validParenthesis(expression);
    cout<<(ans?"true":"false");
}

/*
MISTAKES TO AVOID:
1. Running matching logic for opening brackets.
   - Only closing brackets should trigger comparison.

2. Accessing s.top() when stack is empty.
   - Always check !s.empty() first.

3. Forgetting to verify stack is empty at the end.
   - Leftover opening brackets mean invalid expression.

4. Matching wrong bracket pairs.
   - '(' with ')'
   - '{' with '}'
   - '[' with ']'

5. Returning true immediately after finding one match.
   - Entire string must be processed.

GOLDEN INTERVIEW TIPS:
1. Whenever you see:
   - Balanced Parentheses
   - Matching Brackets
   - Nested Structures
   Think: STACK.

2. The stack stores "unresolved" opening brackets.

3. Ask yourself:
   "What is the latest bracket that still needs closing?"
   That is exactly what stack.top() represents.

4. Most bracket problems reduce to:
   Push opening brackets.
   Match and pop on closing brackets.

5. This pattern appears frequently in:
   - Expression evaluation
   - HTML/XML tag matching
   - Compiler parsing
   - Monotonic stack problems
*/