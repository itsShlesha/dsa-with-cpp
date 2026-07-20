#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- APPROACH ----------------------------------

Problem:
Implement a Queue using a Singly Linked List.

Data Structures Used:
1. front -> Points to the first node of the queue.
2. rear  -> Points to the last node of the queue.

Algorithm:

Enqueue:
1. Create a new node.
2. If the queue is empty:
      front = rear = new node.
3. Otherwise:
      rear->next = new node.
      rear = new node.

Dequeue:
1. Check for underflow.
2. Store the current front node.
3. Move front to front->next.
4. If the queue becomes empty, set rear = NULL.
5. Delete the removed node.

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
        this->next = NULL;
    }
};

class Queue{
    Node* front;
    Node* rear;

public:
    Queue(){
        front = rear = NULL;
    }

    // Insert element into the queue
    void enqueue(int data){

        Node* newNode = new Node(data);

        // Queue is empty
        if(front == NULL){
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Remove front element
    void dequeue(){

        if(front == NULL){
            cout << "Queue Underflow" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        // Queue became empty
        if(front == NULL){
            rear = NULL;
        }

        delete temp;
    }

    // Return front element
    int peek(){

        if(front == NULL){
            cout << "Queue is Empty" << endl;
            return -1;
        }

        return front->data;
    }

    // Check if queue is empty
    bool isEmpty(){
        return front == NULL;
    }

    void display(){

        Node* temp = front;

        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main(){

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    cout << "Front: " << q.peek() << endl;

    q.dequeue();

    cout << "After Dequeue: ";
    q.display();

    cout << "Front: " << q.peek() << endl;

    return 0;
}

/*
--------------------------- INTERVIEW NOTES ----------------------------------

Why does this work?
- front always points to the first element.
- rear always points to the last element.
- Since we already know the last node, insertion happens in O(1).
- Removing from the front is also O(1), making the queue efficient.

Common Mistakes:
1. Forgetting to update rear when the queue becomes empty.
2. Not deleting the removed node, causing memory leaks.
3. Handling only the general case and ignoring the first insertion.
4. Returning front->data without checking whether the queue is empty.

Key Insight:
Unlike an array-based queue, a linked-list implementation has no fixed
capacity and never wastes space due to shifting elements.

Pattern:
Linked List
(Queue Implementation using Linked List)
*/