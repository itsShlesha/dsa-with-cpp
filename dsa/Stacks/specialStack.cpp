#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
Problem: Design a Special Stack
------------------------------------------------------------

The stack should support all standard operations along with
getMin() in O(1) time and O(1) extra space.

Approach:
Instead of maintaining another stack for minimum elements,
we encode values whenever a new minimum is inserted.

Encoding Formula:
encoded = 2*newMin - oldMin

Whenever the top element is smaller than the current minimum,
it means it is an encoded value.

During pop():
oldMin = currentMin
previousMin = 2*currentMin - encodedValue

This restores the previous minimum without using extra memory.

Time Complexity:
Push  : O(1)
Pop   : O(1)
Top   : O(1)
getMin: O(1)

Space Complexity:
O(1) extra space
(Only one stack is used.)
*/

class specialStack{
    stack<int> s;
    int min;

public:

    void push(int data){
        if(s.empty()){
            s.push(data);
            min = data;
        }
        else{
            if(data < min){
                int val = 2*data - min;
                s.push(val);
                min = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop(){

        if(s.empty())
            return -1;

        int curr = s.top();
        s.pop();

        if(curr > min){
            return curr;
        }
        else{
            int prevMin = min;
            min = 2*min - curr;
            return prevMin;
        }
    }

    int top(){

        if(s.empty())
            return -1;

        int curr = s.top();

        if(curr < min)
            return min;

        return curr;
    }

    bool isEmpty(){
        return s.empty();
    }

    int getMin(){

        if(s.empty())
            return -1;

        return min;
    }
};

int main(){

    specialStack st;

    st.push(5);
    cout << "Min: " << st.getMin() << endl;

    st.push(3);
    cout << "Min: " << st.getMin() << endl;

    st.push(7);
    cout << "Min: " << st.getMin() << endl;

    st.push(2);
    cout << "Min: " << st.getMin() << endl;

    cout << "\nTop: " << st.top() << endl;

    cout << "\nPopped: " << st.pop() << endl;
    cout << "Current Min: " << st.getMin() << endl;

    cout << "\nPopped: " << st.pop() << endl;
    cout << "Current Min: " << st.getMin() << endl;

    cout << "\nPopped: " << st.pop() << endl;
    cout << "Current Min: " << st.getMin() << endl;

    cout << "\nPopped: " << st.pop() << endl;

    if(st.isEmpty())
        cout << "Stack is Empty" << endl;

    return 0;
}

/*
------------------------------------------------------------
Mistakes to Avoid
------------------------------------------------------------

1. After pushing an encoded value, always update:
   min = data;

2. During pop(), return the current minimum first,
   then restore the previous minimum.

3. top() should return min whenever the stored value
   is encoded (storedValue < min).

4. Encoding is performed only when:
   data < min
   (Not <=)

5. Handle empty stack before every operation.

------------------------------------------------------------
Interview Tip ⭐
------------------------------------------------------------

The encoding technique works because:

encoded = 2*newMin - oldMin

Since newMin < oldMin,
encoded is always smaller than newMin.

Therefore,
storedValue < currentMin

becomes a flag indicating that the value is encoded,
allowing us to recover the previous minimum using:

previousMin = 2*currentMin - encodedValue

This is a very common interview question because it achieves
O(1) time and O(1) extra space without using an auxiliary stack.
*/