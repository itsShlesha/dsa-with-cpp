#include <bits/stdc++.h>
using namespace std;

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    CircularQueue(){
        size = 1000;
        arr = new int[size];
        front = rear = -1;
    }

    // Insert an element
    bool enqueue(int val){

        // Queue is full
        if((front == 0 && rear == size-1) ||
           (rear == (front-1)%(size-1))){
            cout << "Queue is Full" << endl;
            return false;
        }

        // First element
        else if(front == -1){
            front = rear = 0;
        }

        // Circular nature
        else if(rear == size-1 && front != 0){
            rear = 0;
        }

        // Normal insertion
        else{
            rear++;
        }

        arr[rear] = val;
        return true;
    }

    // Delete an element
    int dequeue(){

        // Queue is empty
        if(front == -1){
            cout << "Queue is Empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        // Single element present
        if(front == rear){
            front = rear = -1;
        }

        // Wrap front
        else if(front == size-1){
            front = 0;
        }

        // Normal increment
        else{
            front++;
        }

        return ans;
    }

    // Return front element
    int getFront(){
        if(front == -1)
            return -1;

        return arr[front];
    }

    // Check if queue is empty
    bool isEmpty(){
        return front == -1;
    }
};

int main(){

    CircularQueue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Front element: " << q.getFront() << endl;

    // Dequeue
    cout << "Deleted: " << q.dequeue() << endl;
    cout << "Deleted: " << q.dequeue() << endl;

    cout << "Front element: " << q.getFront() << endl;

    // More insertions
    q.enqueue(50);
    q.enqueue(60);

    cout << "\nRemoving all elements:\n";

    while(!q.isEmpty()){
        cout << q.dequeue() << " ";
    }

    cout << endl;

    return 0;
}

/*
-------------------------- Circular Queue --------------------------

Why Circular Queue?
- In a normal queue, deleted spaces cannot be reused.
- Circular Queue wraps around and utilizes the entire array.

Cases in enqueue():
1. Queue Full
2. First insertion
3. Rear reaches end -> wrap to 0
4. Normal insertion

Cases in dequeue():
1. Queue Empty
2. Single element
3. Front reaches end -> wrap to 0
4. Normal deletion

Time Complexity:
enqueue()  -> O(1)
dequeue()  -> O(1)
getFront() -> O(1)
isEmpty()  -> O(1)

Space Complexity:
O(n)

Full Condition:
(front == 0 && rear == size-1)
OR
rear == (front-1)%(size-1)

Empty Condition:
front == -1

------------------------------------------------------------
*/