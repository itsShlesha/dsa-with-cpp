#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- APPROACH ----------------------------------

Problem:
Implement K queues in a single array of size N such that all queues
can dynamically share the available space.

Data Structures Used:
1. arr[]   -> Stores queue elements.
2. front[] -> Stores front index of each queue.
3. rear[]  -> Stores rear index of each queue.
4. next[]  -> Acts as:
              - Linked list pointer for queue elements.
              - Free list for unused indices.
5. freespot -> Points to the first available free index.

Enqueue:
1. Take the current free index.
2. Update freespot.
3. Link the new element to the queue.
4. Update rear.
5. Store the element.

Dequeue:
1. Remove the front element.
2. Move front to the next node.
3. If queue becomes empty, reset rear.
4. Return the removed index back to the free list.

Time Complexity:
enqueue() : O(1)
dequeue() : O(1)

Space Complexity:
O(N + K)
*/

class kQueue{
    private:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

    public:
    kQueue(int n, int k){
        this -> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[k];
        
        for(int i = 0; i<k; i++){
            front[i] = -1; 
            rear[i] = -1;
        }

        next = new int[n];

        for(int i = 0; i<n-1; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;

        arr = new int[n];

        freespot = 0;
    }

    void enqueue(int data, int qn){
        //overflow
        if(freespot == -1){
            cout<<"No empty space is available"<<endl;
            return;
        }

        //find first free index
        int index = freespot;

        //update freespot
        freespot = next[index];

        //check whether first element
        if(front[qn-1] == -1){
            front[qn-1] = index;
        }else{
            //link new element to prev element
            next[rear[qn-1]] = index;
        }

        //update next
        next[index] = -1;

        //update rear
        rear[qn-1] = index;

        //push element
        arr[index] = data;
    }

    int dequeue(int qn){
        //underflow check
        if(front[qn-1] == -1){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }

        //find index to pop
        int index = front[qn-1];

        //move front forward
        front[qn-1] = next[index];

        // if queue becomes empty, rear should also become -1
        if(front[qn-1] == -1){
        rear[qn-1] = -1;

        //freeslot management
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
}
};

int main(){

    kQueue q(10, 3);

    // Queue 1
    q.enqueue(10, 1);
    q.enqueue(20, 1);
    q.enqueue(30, 1);

    // Queue 2
    q.enqueue(40, 2);
    q.enqueue(50, 2);

    // Queue 3
    q.enqueue(60, 3);
    q.enqueue(70, 3);

    cout << "Queue 1 Dequeue: " << q.dequeue(1) << endl;
    cout << "Queue 1 Dequeue: " << q.dequeue(1) << endl;

    cout << "Queue 2 Dequeue: " << q.dequeue(2) << endl;

    cout << "Queue 3 Dequeue: " << q.dequeue(3) << endl;
    cout << "Queue 3 Dequeue: " << q.dequeue(3) << endl;

    return 0;
}

/*
--------------------------- INTERVIEW NOTES ----------------------------------

Why does this work?
- Instead of reserving fixed space for each queue, every queue uses
  the common array dynamically.
- The next[] array serves two purposes:
    1. Links elements within a queue.
    2. Maintains the list of free indices.
- freespot always points to the next available location.

Common Mistakes:
1. Forgetting to update rear when a queue becomes empty.
2. Not updating freespot after insertion/removal.
3. Confusing queue number (1-based) with array index (0-based).
4. Forgetting to initialize next[] as a free list.

Key Insight:
The same next[] array behaves like a linked list for occupied cells
and a free list for unused cells, allowing all K queues to share
memory efficiently.

Pattern:
Multiple Queues in a Single Array
(Free List + Linked List Simulation)
*/