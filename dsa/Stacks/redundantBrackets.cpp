#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:
Given an arithmetic expression containing brackets,
check whether any pair of brackets is redundant.

Redundant brackets are brackets that do not contribute
to the evaluation of the expression.

Examples:
((a+b))  -> True
(a+b)    -> False
(a+(b))  -> True

APPROACH:
Use a stack to keep track of opening brackets and operators.

1. Traverse the expression.
2. Push '(' and all operators (+,-,*,/) onto the stack.
3. When ')' is encountered:
   - Traverse backwards in the stack until '(' is found.
   - Check whether at least one operator exists inside.
4. If no operator exists inside the bracket pair,
   those brackets are redundant.
5. Otherwise continue processing.

WHY IT WORKS:
A meaningful bracket pair must contain at least one operator.

Examples:

(a+b)
Inside brackets -> '+'
Not redundant.

(a)
Inside brackets -> only operand
No operator present.
Redundant.

((a+b))
Outer bracket contains no operator directly inside it.
Therefore outer brackets are redundant.

The stack allows us to efficiently inspect the contents
of every bracket pair exactly once.

TIME COMPLEXITY:
O(N)

Each character is pushed and popped at most once.

SPACE COMPLEXITY:
O(N)

In the worst case, the stack stores all brackets/operators.
*/

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' ||
           ch == '*' || ch == '/') {
            st.push(ch);
        }
        else if(ch == ')') {

            bool isRedundant = true;

            while(!st.empty() && st.top() != '(') {

                char top = st.top();

                if(top == '+' || top == '-' ||
                   top == '*' || top == '/') {
                    isRedundant = false;
                }

                st.pop();
            }

            if(isRedundant)
                return true;

            st.pop();
        }
    }

    return false;
}

int main() {

    string str = "((a+b))";

    if(findRedundantBrackets(str))
        cout << "Redundant Brackets Present";
    else
        cout << "No Redundant Brackets";

    return 0;
}

/*
MISTAKES TO AVOID:

1. Using:
   while(st.top() == '(')

   Correct:
   while(st.top() != '(')

   We must process everything INSIDE the brackets,
   not stop immediately at '('.

2. Initializing:

   bool isRedundant = false;

   Correct:
   bool isRedundant = true;

   Assume redundancy initially.
   If an operator is found, mark it as non-redundant.

3. Forgetting to remove '(' after processing.

   After reaching '(':
   st.pop();

4. Pushing operands into the stack.

   Not required.
   We only care about:
   - Opening brackets
   - Operators

5. Not checking stack emptiness before accessing top().

   In production code, always ensure the stack is non-empty.

GOLDEN INTERVIEW TIPS:

1. Whenever a problem involves:
   - Matching brackets
   - Expression evaluation
   - Nearest element patterns

   Think STACK immediately.

2. Ask:
   "What information actually matters?"

   Here operands do not matter.
   Only operators and brackets matter.

3. Redundant-bracket problems usually rely on detecting
   whether useful work (an operator) exists inside a pair
   of brackets.

4. A good optimization habit:
   Store only the information needed.
   Ignoring operands simplifies both logic and memory usage.

5. Interviewers often ask:
   "Why not store operands?"

   Best answer:
   Redundancy depends only on the presence of operators,
   not on the values/variables themselves.
*/