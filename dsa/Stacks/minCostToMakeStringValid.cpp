#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:
Given a string consisting only of opening '{'
and closing '}' braces, determine the minimum
number of reversals needed to make the expression valid.

A reversal means:
'{' -> '}'
or
'}' -> '{'

Examples:

"}{"      -> 2 reversals
"}}{{"    -> 2 reversals
"}{{}}{{{"-> 3 reversals

APPROACH:

STEP 1:
Check length.

If length is odd, balancing is impossible.

Reason:
Every valid expression requires braces in pairs.

------------------------------------------------

STEP 2:
Remove already balanced parts.

Traverse the string:

1. Push every '{'.
2. For every '}':
   - If top contains '{',
     remove the pair.
   - Otherwise push '}'.

After traversal, only invalid braces remain.

------------------------------------------------

STEP 3:
Count remaining braces.

Possible leftover form:

}}}}....{{{{

Let:

openCount   = number of '{'
closedCount = number of '}'

------------------------------------------------

STEP 4:
Compute reversals.

For consecutive opens:

{{  -> one reversal needed

Reversals:
(openCount + 1) / 2

Similarly for closes:

}}
-> one reversal needed

Reversals:
(closedCount + 1) / 2

Total:

((openCount + 1) / 2)
+
((closedCount + 1) / 2)

WHY IT WORKS:

After removing all valid pairs,
only unmatched braces remain.

The remaining braces can only appear
in the form:

}}...{{

Two unmatched opens require one reversal.

Example:

{{ -> {}

Two unmatched closes require one reversal.

Example:

}} -> {}

Hence the formula correctly computes
the minimum reversals required.

TIME COMPLEXITY:
O(N)

Each character is pushed/popped at most once.

SPACE COMPLEXITY:
O(N)

Stack may contain all characters
in the worst case.
*/

int findMinCost(string& str){

    if(str.length() % 2 == 1){
        return -1;
    }

    stack<char> s;

    for(int i = 0; i < str.length(); i++){

        char ch = str[i];

        if(ch == '{'){
            s.push(ch);
        }
        else{

            if(!s.empty() && s.top() == '{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }

    int openCount = 0;
    int closedCount = 0;

    while(!s.empty()){

        if(s.top() == '{'){
            openCount++;
        }
        else{
            closedCount++;
        }

        s.pop();
    }

    int ans = ((openCount + 1) / 2)
            + ((closedCount + 1) / 2);

    return ans;
}

int main(){

    string str = "}{{}}{{{";

    cout << findMinCost(str);

    return 0;
}

/*
MISTAKES TO AVOID:

1. Using <= in traversal.

Wrong:
for(int i = 0; i <= str.length(); i++)

Correct:
for(int i = 0; i < str.length(); i++)

Otherwise out-of-bounds access occurs.

------------------------------------------------

2. Mixing parentheses and braces.

Wrong:
s.top() == '('

Correct:
s.top() == '{'

This is one of the most common interview bugs.

------------------------------------------------

3. Forgetting odd-length check.

Example:

"}}{"

Length = 3

Impossible to balance regardless of reversals.

Always handle this first.

------------------------------------------------

4. Trying to directly count reversals
during traversal.

Much harder and error-prone.

First remove valid pairs,
then count invalid braces.

------------------------------------------------

5. Misunderstanding the formula.

(openCount + 1)/2

is NOT arbitrary.

It effectively computes:

ceil(openCount / 2)

without using floating-point operations.

------------------------------------------------

GOLDEN INTERVIEW TIPS:

1. Whenever a problem asks to:
   - Remove matching pairs
   - Validate brackets
   - Process nested structures

Think STACK first.

2. Separate the problem into:
   - Remove valid part
   - Process invalid remainder

This pattern appears frequently.

3. Learn these three classic stack problems together:

   a) Valid Parentheses
   b) Redundant Brackets
   c) Minimum Cost to Make String Valid

All use the same matching-pair intuition.

4. If a bracket problem involves
   "minimum operations",
   first ask:
   "Can I eliminate already valid pairs?"

That usually simplifies the problem drastically.

5. Interviewers love asking:
   "Why does (count + 1)/2 work?"

Be ready to explain that it computes
the ceiling of count/2 using integer arithmetic.
*/