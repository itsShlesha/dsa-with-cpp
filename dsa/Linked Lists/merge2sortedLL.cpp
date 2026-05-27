#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this->data;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }

        cout << "Memory is free for node with data "
             << value << endl;
    }
};

/*
PROBLEM STATEMENT:
Given two sorted linked lists, merge them into
a single sorted linked list and return the head.

Example:
List 1: 1 -> 3 -> 5
List 2: 2 -> 4 -> 6

Output:
1 -> 2 -> 3 -> 4 -> 5 -> 6

--------------------------------------------------

APPROACH:
We merge the lists in-place without creating extra nodes.

1. Compare heads of both lists.
2. Smaller head becomes the final head.
3. Traverse first list using curr1 and next1.
4. Traverse second list using curr2.
5. Insert curr2 node between curr1 and next1
   whenever its value lies in that range.
6. If first list ends, attach remaining second list.

WHY IT WORKS:
Since both lists are already sorted:
- curr1 and next1 always maintain sorted order.
- Any curr2 inserted between them keeps the list sorted.
- Every node is processed exactly once.

TIME COMPLEXITY:
O(N + M)

SPACE COMPLEXITY:
O(1)
*/

void insertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

Node* solve(Node* first, Node* second){

    // if only one node in first list
    if(first->next == NULL){
        first->next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1->next;

    Node* curr2 = second;
    Node* next2 = NULL;

    while(next1 != NULL && curr2 != NULL){

        // curr2 lies between curr1 and next1
        if((curr2->data >= curr1->data) &&
           (curr2->data <= next1->data)){

            // store next node
            next2 = curr2->next;

            // insert node
            curr1->next = curr2;
            curr2->next = next1;

            // update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{

            // move in first list
            curr1 = next1;
            next1 = next1->next;

            // first list ended
            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}

Node* mergeSortedLinkedLists(Node* first, Node* second){

    if(first == NULL)
        return second;

    if(second == NULL)
        return first;

    // choose smaller head
    if(first->data <= second->data){
        return solve(first, second);
    }
    else{
        return solve(second, first);
    }
}

int main(){

    // first sorted linked list
    Node* node1 = new Node(1);
    Node* first = node1;
    Node* tail1 = node1;

    insertAtTail(tail1, 3);
    insertAtTail(tail1, 5);
    insertAtTail(tail1, 7);

    cout << "First Linked List: ";
    print(first);

    // second sorted linked list
    Node* node2 = new Node(2);
    Node* second = node2;
    Node* tail2 = node2;

    insertAtTail(tail2, 4);
    insertAtTail(tail2, 6);
    insertAtTail(tail2, 8);

    cout << "Second Linked List: ";
    print(second);

    // merge both lists
    Node* mergedHead = mergeSortedLinkedLists(first, second);

    cout << "Merged Linked List: ";
    print(mergedHead);

    return 0;
}


/*
MISTAKES TO AVOID:

1. Forgetting to store next2 before insertion
   -> You may lose the remaining second list.

2. Not handling single-node first list
   -> first->next can become NULL and crash.

3. Forgetting to return the merged head.

4. Updating pointers in wrong order
   -> Can create cycles in linked list.

5. Using extra nodes unnecessarily
   -> This problem can be solved in-place.

--------------------------------------------------

GOLDEN INTERVIEW TIPS:

1. Always draw pointer movement on paper.
   Linked list bugs usually happen due to
   incorrect pointer updates.

2. While merging:
   - curr1 = current node
   - next1 = next node
   This pattern is very common.

3. In-place linked list questions are loved
   in interviews because they test pointer clarity.

4. Speak pointer updates step-by-step while coding.
   Interviewers care more about reasoning than speed.

5. Edge cases to always check:
   - Empty lists
   - Single-node lists
   - All nodes of one list smaller than the other
*/