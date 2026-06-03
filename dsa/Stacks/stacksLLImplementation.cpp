#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    Node* top;

public:
    Stack(){
        top = NULL;
    }

    void push(int data){
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
    }

    int pop(){
        if(top == NULL){
            return -1;
        }

        Node* temp = top;
        int ans = temp->data;

        top = top->next;
        delete temp;

        return ans;
    }

    int peek(){
        if(top == NULL){
            return -1;
        }

        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }
};

int main(){

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.peek() << endl;     // 30

    cout << st.pop() << endl;      // 30
    cout << st.pop() << endl;      // 20

    cout << st.peek() << endl;     // 10

    if(st.isEmpty()){
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "Stack is Not Empty" << endl;
    }

    return 0;
}