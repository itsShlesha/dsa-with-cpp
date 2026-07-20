#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- APPROACH ----------------------------------

Problem:
Implement a Circular Queue using a Circular Singly Linked List.

Data Structures Used:
1. front -> Points to the first node.
2. rear  -> Points to the last node.
3. rear->next always points back to front,
   making the linked list circular.

Algorithm:

Enqueue:
1. Create a new node.
2. If the queue is empty:
      front = rear = new node.
3. Otherwise:
      rear->next = new node.
      rear = new node.
4. Make rear->next point to front.

Dequeue:
1. If queue is empty, report underflow.
2. If only one node exists:
      Delete it and set front = rear = NULL.
3. Otherwise:
      Move front forward.
      Update rear->next to the new front.
      Delete the old front node.

Peek:
Return front->data.

Time Complexity:
enqueue() : O(1)
dequeue() : O(1)
peek()    : O(1)

Space Complexity:
O(N)
*/

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class CircularQueue{
    Node* front;
    Node* rear;

public:

    CircularQueue(){
        front = rear = NULL;
    }

    // Insert at rear
    void enqueue(int data){

        Node* newNode = new Node(data);

        // First node
        if(front == NULL){
            front = rear = newNode;
            rear->next = front;
            return;
        }

        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    // Delete from front
    void dequeue(){

        if(front == NULL){
            cout << "Queue Underflow\n";
            return;
        }

        // Only one node
        if(front == rear){
            delete front;
            front = rear = NULL;
            return;
        }

        Node* temp = front;
        front = front->next;
        rear->next = front;

        delete temp;
    }

    // Return front element
    int peek(){

        if(front == NULL){
            cout << "Queue is Empty\n";
            return -1;
        }

        return front->data;
    }

    bool isEmpty(){
        return front == NULL;
    }

    void display(){

        if(front == NULL){
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;

        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != front);

        cout << endl;
    }
};

int main(){

    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Queue: ";
    q.display();

    cout << "Front: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    cout << "After Dequeue:\n";
    q.display();

    cout << "Front: " << q.peek() << endl;

    return 0;
}

/*
--------------------------- INTERVIEW NOTES ----------------------------------

Why does this work?
- Unlike a normal linked-list queue, the last node always points
  back to the first node, forming a circular structure.
- The front pointer gives direct access to the first element,
  while the rear pointer enables O(1) insertion.
- Updating rear->next after every enqueue and dequeue preserves
  the circular nature of the queue.

Common Mistakes:
1. Forgetting to set rear->next = front after enqueue().
2. Forgetting to update rear->next after dequeue().
3. Not handling the single-node case separately.
4. Traversing with while(temp != NULL), which causes an infinite
   loop in a circular linked list.

Key Insight:
The queue operations remain O(1) because both ends are directly
accessible, while the circular link eliminates NULL at the end of
the list.

Pattern:
Circular Linked List
(Circular Queue using Linked List)
*/