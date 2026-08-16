#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEM STATEMENT:
    - Given two BSTs, merge them into a single balanced BST.
    - The resulting BST should contain all elements from both BSTs.
    - We need to do this with O(h1 + h2) auxiliary space instead of
      storing all nodes in arrays.

    APPROACH:
    - Convert both BSTs into sorted doubly linked lists using reverse
      inorder traversal.
    - In the DLL:
          right -> next node
          left  -> previous node
    - Since inorder of a BST is sorted, reverse inorder lets us build
      the DLL in sorted order by processing:
          right -> root -> left
    - Merge the two sorted DLLs using the standard two-pointer technique.
    - Count the nodes in the merged DLL.
    - Convert the sorted DLL back into a balanced BST.
    - While converting, recursively construct the left half, use the
      current head as root, move head forward, then construct the
      right half.

    WHY IT WORKS:
    - BST -> inorder gives sorted elements.
    - Converting the BST into a DLL preserves this sorted order.
    - Merging two sorted DLLs gives one sorted DLL containing every node.
    - A sorted DLL can be converted into a balanced BST by recursively
      taking the middle element as the root.
    - The important part is that we reuse the existing tree nodes instead
      of creating extra nodes or storing all values in arrays.

    TIME COMPLEXITY:
    - Convert BSTs to DLLs -> O(n + m)
    - Merge DLLs -> O(n + m)
    - Count nodes -> O(n + m)
    - DLL to BST -> O(n + m)
    - Overall -> O(n + m)

    SPACE COMPLEXITY:
    - No extra array/vector is used.
    - Recursion stack -> O(h1 + h2)
    - Overall auxiliary space -> O(h1 + h2)
*/

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void convertIntoSortedDLL(Node* root, Node* &head){
    if(root == NULL){
        return;
    }

    //reverse inorder -> right, root, left
    convertIntoSortedDLL(root->right, head);

    root->right = head;

    if(head != NULL){
        head->left = root;
    }

    head = root;

    convertIntoSortedDLL(root->left, head);
}

Node* mergeLL(Node* &head1, Node* &head2){
    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL){

        if(head1->data < head2->data){

            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }

        }
        else{

            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(Node* head){
    int cnt = 0;
    Node* temp = head;

    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }

    return cnt;
}

Node* sortedLLtoBST(Node* &head, int n){
    if(n <= 0 || head == NULL){
        return NULL;
    }

    Node* left = sortedLLtoBST(head, n/2);

    Node* root = head;

    root->left = left;

    head = head->right;

    root->right = sortedLLtoBST(head, n - n/2 - 1);

    return root;
}

Node* mergeBST(Node* root1, Node* root2){

    //step1: convert bst into sorted dll - inplace
    Node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);

    if(head1 != NULL){
        head1->left = NULL;
    }

    Node* head2 = NULL;
    convertIntoSortedDLL(root2, head2);

    if(head2 != NULL){
        head2->left = NULL;
    }

    //step2: merge sorted ll
    Node* head = mergeLL(head1, head2);

    //step3: convert sorted ll to bst
    return sortedLLtoBST(head, countNodes(head));
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){

    /*
                5                 8
               / \               / \
              3   7             2   10
             / \                   /
            1   4                 9
    */

    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(1);
    root1->left->right = new Node(4);

    Node* root2 = new Node(8);
    root2->left = new Node(2);
    root2->right = new Node(10);
    root2->right->left = new Node(9);

    Node* root = mergeBST(root1, root2);

    cout << "Inorder of merged BST: ";
    printInorder(root);

    return 0;
}

/*
    MISTAKES TO AVOID:
    - In convertIntoSortedDLL(), use reverse inorder:
          right -> root -> left
      because we are building the DLL from the back.
    - In mergeLL(), when head is NULL:
          head = head1;
          tail = head1;
      NOT:
          head = head;
    - After attaching a node, always move tail to that node.
    - Remember that right acts as the "next" pointer in the DLL.
    - In countNodes(), move temp using:
          temp = temp->right;
    - In sortedLLtoBST(), move the DLL head using:
          head = head->right;
    - sortedLLtoBST() must return root after constructing both subtrees.
    - Don't create new nodes while converting the DLL back to BST;
      reuse the existing nodes.

    GOLDEN INTERVIEW TIPS:
    - This is the SPACE-OPTIMIZED version of:
          BST -> Inorder Array -> Merge Arrays -> Balanced BST
    - Instead of storing inorder values in vectors, convert the BSTs
      into DLLs IN-PLACE.
    - Think of the entire solution as:
          BST
           ↓
        Sorted DLL
           ↓
        Merge DLLs
           ↓
        Sorted DLL
           ↓
        Balanced BST
    - The key trick is reusing the BST nodes as DLL nodes and then
      reusing those same nodes again when constructing the final BST.
    - This approach is useful when an interviewer asks you to merge
      BSTs while minimizing extra space.

    ONE-LINE SUMMARY:
    - Convert both BSTs into sorted DLLs in-place, merge the DLLs, then
      recursively convert the merged sorted DLL into a balanced BST.
*/