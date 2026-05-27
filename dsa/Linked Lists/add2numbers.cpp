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
Given two linked lists where each node contains
a single digit of a number, add the two numbers
and return the resulting linked list.

Digits are stored in forward order.

Example:
List 1: 1 -> 2 -> 3
List 2: 4 -> 5 -> 6

Number formed:
123 + 456 = 579

Output:
5 -> 7 -> 9

--------------------------------------------------

APPROACH:
1. Reverse both linked lists.
2. Add corresponding digits like normal addition.
3. Maintain carry while adding.
4. Store resulting digits in a new linked list.
5. Reverse the final answer list.

WHY IT WORKS:
Reversing converts the lists into least significant
digit first format, making addition easy exactly
like elementary school addition.

TIME COMPLEXITY:
O(N + M)

SPACE COMPLEXITY:
O(max(N, M))
*/

Node* reverseLinkedList(Node* head){

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){

        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

void insertAtTail(Node* &head, Node* &tail, int val){

    Node* temp = new Node(val);

    // first node
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

Node* add(Node* first, Node* second){

    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first != NULL || second != NULL || carry != 0){

        int val1 = 0;

        if(first != NULL){
            val1 = first->data;
        }

        int val2 = 0;

        if(second != NULL){
            val2 = second->data;
        }

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;

        // move pointers
        if(first != NULL){
            first = first->next;
        }

        if(second != NULL){
            second = second->next;
        }
    }

    return ansHead;
}

Node* addTwoLists(Node* first, Node* second){

    // step 1: reverse both lists
    first = reverseLinkedList(first);
    second = reverseLinkedList(second);

    // step 2: add lists
    Node* answer = add(first, second);

    // step 3: reverse final answer
    answer = reverseLinkedList(answer);

    return answer;
}

void print(Node* head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main(){

    // first linked list
    Node* node1 = new Node(1);
    Node* first = node1;
    Node* tail1 = node1;

    insertAtTail(first, tail1, 2);
    insertAtTail(first, tail1, 3);

    cout << "First Linked List: ";
    print(first);

    // second linked list
    Node* node2 = new Node(4);
    Node* second = node2;
    Node* tail2 = node2;

    insertAtTail(second, tail2, 5);
    insertAtTail(second, tail2, 6);

    cout << "Second Linked List: ";
    print(second);

    // add lists
    Node* result = addTwoLists(first, second);

    cout << "Resultant Linked List: ";
    print(result);

    return 0;
}

/*
MISTAKES TO AVOID:

1. Returning wrong pointer after reversing
   -> Always return prev.

2. Forgetting carry in loop condition
   -> Final carry node may get skipped.

3. Not handling unequal length lists.

4. Forgetting to move first/second pointers
   -> Infinite loop.

5. Passing head and tail by value instead of reference
   -> Insertions will not update original pointers.

6. Forgetting to reverse final answer.

--------------------------------------------------

GOLDEN INTERVIEW TIPS:

1. This problem is a direct application of:
   - linked list reversal
   - elementary addition with carry

2. Whenever addition starts from the end,
   reversing the list is often useful.

3. Dry run carry carefully:
   Example:
   9 + 9 = 18

4. Keep helper functions modular:
   - reverse
   - insert
   - add

5. Interviewers love clean pointer handling
   and proper edge case coverage.

6. Important edge cases:
   - Different length lists
   - Carry at the end
   - One empty list
   - All digits = 9
*/