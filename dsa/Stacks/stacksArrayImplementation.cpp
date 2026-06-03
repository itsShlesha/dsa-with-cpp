#include <bits/stdc++.h>
using namespace std;

class Stack{
    //properties
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        this->size = size;
        arr = new int(size);
        top = -1;
    }

    //behavior
    void push(int element){
        if(size-top > 1){
            top++;
            arr[top] = element;
        }else{
            cout<<"Stack Overflow!"<<endl;
        }
    }

    int pop(){
        int popped = -1;
        if(top >= 0){
            popped = arr[top];
            top--;
        }else{
            cout<<"Stack Underflow!"<<endl;
        }
        return popped;
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    cout<<st.peek()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.peek()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.peek()<<endl;
    cout<<st.pop()<<endl;
    cout<<(st.isEmpty()?"Stack Empty":"Stack Not Empty")<<endl;
}