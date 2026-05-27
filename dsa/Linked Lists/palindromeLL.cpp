#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:
Given the head of a singly linked list,
check whether the linked list is a palindrome or not.

A palindrome reads the same forward and backward.

Example:
1 -> 2 -> 2 -> 1

Output:
True

--------------------------------------------------

APPROACH 1: Using Extra Array (Brute Force)

1. Traverse the linked list.
2. Store all node values inside a vector.
3. Use two pointers:
   - one from start
   - one from end
4. Compare values while moving inward.
5. If any mismatch occurs, return false.

WHY IT WORKS:
The vector stores the linked list values in order.
A palindrome should look identical from both ends.

TIME COMPLEXITY:
O(N)

SPACE COMPLEXITY:
O(N)

--------------------------------------------------

APPROACH 2: Reverse Second Half (Optimal)

1. Find the middle node using slow and fast pointers.
2. Reverse the second half of the linked list.
3. Compare:
   - first half
   - reversed second half
4. If all values match, it is a palindrome.
5. Reverse the second half again to restore
   the original linked list.

WHY IT WORKS:
For a palindrome:
- first half == reversed second half

Reversing only half the list allows comparison
without using extra space.

TIME COMPLEXITY:
O(N)

SPACE COMPLEXITY:
O(1)
*/

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
bool checkPalindrome(vector<int>& arr){
    int s = 0, e = arr.size()-1;
    while(s <= e){
        if(arr[s] != arr[e]){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}
*/

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

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
    return head;
}

bool isPalindrome(Node* head){
    /*Approach 1:
    vector<int> arr;
    Node* temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome(arr);
    */

    if(head == NULL || head->next == NULL){
        return true;
    }

    Node* middle = getMid(head);

    //reverse list after middle
    Node* temp = middle->next;
    middle->next = reverseLinkedList(temp);

    Node* head1 = head; Node* head2 = middle->next;
    while(head2 != NULL){
        if(head1->data != head2->data){
            return false;
        }else{
            head1 = head1->next;
            head2 = head2->next;
        }
    }

    //undoing the changes made to the linked list
    temp = middle->next;
    middle->next = reverseLinkedList(temp);

    return true;
}

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

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 3);
    insertAtTail(tail, 5);
    insertAtTail(tail, 4);

    cout << "Linked List: ";
    print(head);

    cout<<"Is the Linked List palindromic? "<<isPalindrome(head)<<endl;
}

/*
MISTAKES TO AVOID:

1. Wrong middle finding condition
   -> Always check:
      fast != NULL && fast->next != NULL

2. Returning wrong pointer after reversal
   -> Return prev, not head.

3. Forgetting to move pointers while comparing
   -> Can create infinite loops.

4. Not restoring the linked list
   -> Interviewers may expect the original list
      to remain unchanged.

5. Comparing entire first half with NULL checks wrong
   -> Compare only till second half ends.

6. Forgetting edge cases:
   - Empty list
   - Single-node list
   - Even length list
   - Odd length list

--------------------------------------------------

GOLDEN INTERVIEW TIPS:

1. This is one of the MOST IMPORTANT linked list problems.
   Learn both brute force and optimal approaches.

2. Slow-fast pointer technique is extremely common:
   - finding middle
   - cycle detection
   - splitting linked list

3. Always dry run odd and even length cases separately.

4. Reversing linked lists is a core pattern.
   Master pointer movement:
   prev -> curr -> next

5. In interviews:
   First explain brute force,
   then optimize to O(1) space.

6. Restoring the list after modification
   gives extra interview brownie points.
*/