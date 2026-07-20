#include <bits/stdc++.h>
using namespace std;

class Queue{
    int* arr;
    int front;
    int rear;
    int size;

    public:
        Queue(){
            size = 100000;
            arr = new int[size];
            front = 0;
            rear = 0;
        }

        void enqueue(int val){
            if(rear == size){
                cout<<"Queue is Full"<<endl;
            }else{
            arr[rear] = val;
            rear++;
            }
        }

        int dequeue(){
            if(front == rear){
                return -1;
            }else{
                int ans = arr[front];
                arr[front] = -1;
                front++;
                if(front == rear){
                    front = 0;
                    rear = 0;
                }
                return ans;
            }
        }

        int showfront(){
            if(front == rear){
                return -1;
            }else{
                return arr[front];
            }
        }

        bool empty(){
            if(front == rear) return true;
            return false;
        }
};

int main(){
/*
    queue<int> q;
    q.push(1);
    q.push(11);
    cout<<"Front of queue: "<<q.front()<<endl;
    q.push(3);
    cout<<"Rear of queue: "<<q.back()<<endl;

    cout<<"Size of queue: "<<q.size()<<endl;
    q.pop();
    cout<<"Size of queue: "<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
*/

    // Create our custom queue
    Queue q;

    // =======================
    // Enqueue Operation
    // =======================
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.showfront() << endl;

    // =======================
    // Dequeue Operation
    // =======================
    cout << "Deleted element: " << q.dequeue() << endl;

    cout << "Front element after dequeue: " << q.showfront() << endl;

    // =======================
    // Add more elements
    // =======================
    q.enqueue(40);
    q.enqueue(50);

    // =======================
    // Remove all elements
    // =======================
    cout << "\nRemoving all elements:\n";

    while(!q.empty()){
        cout << q.dequeue() << " ";
    }

    cout << endl;

    // =======================
    // Queue is now empty
    // =======================
    if(q.empty()){
        cout << "Queue is Empty" << endl;
    }
    else{
        cout << "Queue is Not Empty" << endl;
    }

    // Trying to dequeue from an empty queue
    cout << "Trying dequeue on empty queue: " << q.dequeue() << endl;

    // Trying to get front of an empty queue
    cout << "Front element: " << q.showfront() << endl;
}

/*
---------------------------------- Queue Implementation Using Array ----------------------------------

Operations:
1. enqueue(x)
   - Insert element at rear.
   - Increment rear.

2. dequeue()
   - Remove element from front.
   - Increment front.
   - If queue becomes empty, reset front and rear to 0.

3. showfront()
   - Returns the front element.
   - Returns -1 if queue is empty.

4. empty()
   - Returns true if front == rear.

Time Complexity:
enqueue()   -> O(1)
dequeue()   -> O(1)
showfront() -> O(1)
empty()     -> O(1)

Space Complexity:
O(n)

Limitation:
This is a simple linear queue.
After enough dequeue operations, free spaces at the beginning cannot be reused.
Example:
size = 5
enqueue: 1 2 3 4 5
dequeue all first 4 elements
rear == size, so no more insertions are possible even though array has empty spaces.
This drawback is solved by using a Circular Queue.
-----------------------------------------------------------------------------------------
*/