#include <bits/stdc++.h>
using namespace std;

class Deque{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    Deque(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Insert at front
    bool pushFront(int x){

        // Queue Full
        if((front == 0 && rear == size-1) ||
           (rear == (front-1)%(size-1))){
            return false;
        }

        // First element
        else if(front == -1){
            front = rear = 0;
        }

        // Wrap around
        else if(front == 0){
            front = size-1;
        }

        // Normal case
        else{
            front--;
        }

        arr[front] = x;
        return true;
    }

    // Insert at rear
    bool pushRear(int x){

        // Queue Full
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            return false;
        }

        // First element
        else if(front == -1){
            front = rear = 0;
        }

        // Wrap around
        else if(rear == size-1){
            rear = 0;
        }

        // Normal case
        else{
            rear++;
        }

        arr[rear] = x;
        return true;
    }

    // Delete from front
    int popFront(){

        if(front == -1){
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        // Single element
        if(front == rear){
            front = rear = -1;
        }

        // Wrap
        else if(front == size-1){
            front = 0;
        }

        // Normal case
        else{
            front++;
        }

        return ans;
    }

    // Delete from rear
    int popRear(){

        if(front == -1){
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        // Single element
        if(front == rear){
            front = rear = -1;
        }

        // Wrap
        else if(rear == 0){
            rear = size-1;
        }

        // Normal case
        else{
            rear--;
        }

        return ans;
    }

    // Front element
    int getFront(){

        if(front == -1){
            return -1;
        }

        return arr[front];
    }

    // Rear element
    int getRear(){

        if(front == -1){
            return -1;
        }

        return arr[rear];
    }

    // Check empty
    bool isEmpty(){
        return (front == -1);
    }
};

int main(){

    /*
    STL:
    deque<int> d;

    d.push_front(12);
    d.push_back(14);

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    cout<<d.pop_front()<<endl;
    cout<<d.front()<<endl;
    cout<<d.pop_back()<<endl;

    if(d.empty()){
    cout<<"Queue is empty"<<endl;
    }else{
    cout<<"Queue is not empty"<<endl;
    }

    */

    Deque d(5);

    // Push at rear
    d.pushRear(10);
    d.pushRear(20);

    // Push at front
    d.pushFront(5);
    d.pushFront(2);

    cout << "Front: " << d.getFront() << endl;
    cout << "Rear : " << d.getRear() << endl;

    cout << "\nPop Front: " << d.popFront() << endl;
    cout << "Pop Rear : " << d.popRear() << endl;

    cout << "\nFront: " << d.getFront() << endl;
    cout << "Rear : " << d.getRear() << endl;

    cout << "\nRemoving all elements:\n";

    while(!d.isEmpty()){
        cout << d.popFront() << " ";
    }

    cout << endl;

    if(d.isEmpty()){
        cout << "Deque is Empty" << endl;
    }
    else{
        cout << "Deque is Not Empty" << endl;
    }

    return 0;
}

/*
---------------------------- Deque ----------------------------

Deque = Double Ended Queue

Operations:
1. pushFront()  -> Insert from front
2. pushRear()   -> Insert from rear
3. popFront()   -> Delete from front
4. popRear()    -> Delete from rear
5. getFront()   -> Front element
6. getRear()    -> Rear element
7. isEmpty()    -> Checks if deque is empty

Cases in Insertion:
1. Queue Full
2. First element
3. Wrap around
4. Normal insertion

Cases in Deletion:
1. Queue Empty
2. Single element
3. Wrap around
4. Normal deletion

Time Complexity:
pushFront() : O(1)
pushRear()  : O(1)
popFront()  : O(1)
popRear()   : O(1)
getFront()  : O(1)
getRear()   : O(1)

Space Complexity:
O(n)

Applications:
• Browser history
• Undo/Redo
• Sliding Window Maximum
• LRU Cache
• Palindrome checking

---------------------------------------------------------------
*/