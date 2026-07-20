#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- APPROACH ----------------------------------

Problem:
Implement a Deque (Double Ended Queue) using a Doubly Linked List.

A deque allows insertion and deletion from both the front and rear.

Data Structures Used:
1. front -> Points to the first node.
2. rear  -> Points to the last node.
3. Each node contains:
      - data
      - prev pointer
      - next pointer

Operations:
1. pushFront()
2. pushRear()
3. popFront()
4. popRear()
5. getFront()
6. getRear()

Since each node has links in both directions, all operations can be
performed by updating a constant number of pointers.

Time Complexity:
pushFront() : O(1)
pushRear()  : O(1)
popFront()  : O(1)
popRear()   : O(1)
getFront()  : O(1)
getRear()   : O(1)

Space Complexity:
O(N)
*/

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class Deque{
    Node* front;
    Node* rear;

public:
    Deque(){
        front = rear = NULL;
    }

    // Insert at Front
    void pushFront(int data){

        Node* newNode = new Node(data);

        if(front == NULL){
            front = rear = newNode;
            return;
        }

        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }

    // Insert at Rear
    void pushRear(int data){

        Node* newNode = new Node(data);

        if(front == NULL){
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }

    // Delete from Front
    void popFront(){

        if(front == NULL){
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = front;

        if(front == rear){
            front = rear = NULL;
        }
        else{
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
    }

    // Delete from Rear
    void popRear(){

        if(rear == NULL){
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = rear;

        if(front == rear){
            front = rear = NULL;
        }
        else{
            rear = rear->prev;
            rear->next = NULL;
        }

        delete temp;
    }

    // Get Front
    int getFront(){

        if(front == NULL){
            cout << "Deque is Empty\n";
            return -1;
        }

        return front->data;
    }

    // Get Rear
    int getRear(){

        if(rear == NULL){
            cout << "Deque is Empty\n";
            return -1;
        }

        return rear->data;
    }

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

    Deque dq;

    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushFront(5);
    dq.pushFront(2);

    cout << "Deque: ";
    dq.display();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear : " << dq.getRear() << endl;

    dq.popFront();
    dq.popRear();

    cout << "\nAfter Pops:\n";
    dq.display();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear : " << dq.getRear() << endl;

    return 0;
}

/*
--------------------------- INTERVIEW NOTES ----------------------------------

Why does this work?
- The front pointer gives direct access to the first node.
- The rear pointer gives direct access to the last node.
- A doubly linked list allows movement in both directions, making
  insertion and deletion at either end efficient.

Common Mistakes:
1. Forgetting to update both next and prev pointers.
2. Not resetting front and rear to NULL when the deque becomes empty.
3. Accessing front->prev or rear->next after removing the last node.
4. Forgetting to delete removed nodes, causing memory leaks.

Key Insight:
Unlike a singly linked list, a doubly linked list supports O(1)
operations at both ends because each node maintains links to both
its previous and next nodes.

Pattern:
Doubly Linked List
(Double Ended Queue / Deque)
*/