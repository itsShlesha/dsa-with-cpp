#include <bits/stdc++.h>
using namespace std;

/*
*********************************************
    INORDER PREDECESSOR & SUCCESSOR IN BST
*********************************************

Problem Statement:
Given the root of a Binary Search Tree and a key,
find the inorder predecessor and inorder successor
of the given key.

Predecessor:
Largest value smaller than the key.

Successor:
Smallest value greater than the key.

Approach:
1. Start searching for the key from the root.
2. While searching:
   - If current node > key,
     current node can be a potential successor.
     Move to the left subtree.
   - If current node < key,
     current node can be a potential predecessor.
     Move to the right subtree.
3. Once the key is found:
   - If a left subtree exists,
     predecessor is the rightmost node of the left subtree.
   - If a right subtree exists,
     successor is the leftmost node of the right subtree.
4. Return both pointers.

Why this works:
The BST property allows us to eliminate half of the tree
during the search.

Potential predecessor/successor are continuously updated
while moving towards the key.

If the key has left/right children, a closer predecessor/
successor always exists inside those subtrees.

Time Complexity:
O(H)

H = Height of the BST

Balanced BST : O(log N)
Skewed BST   : O(N)

Space Complexity:
O(1)

Only a few pointers are used.
*/

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

pair<Node*, Node*> findPredSucc(Node* root, int key){

    Node* pred = NULL;
    Node* succ = NULL;

    Node* curr = root;

    while(curr){

        if(curr->data == key){

            // Find predecessor
            if(curr->left){
                Node* temp = curr->left;

                while(temp->right)
                    temp = temp->right;

                pred = temp;
            }

            // Find successor
            if(curr->right){
                Node* temp = curr->right;

                while(temp->left)
                    temp = temp->left;

                succ = temp;
            }

            break;
        }

        else if(curr->data > key){
            succ = curr;          // Potential successor
            curr = curr->left;
        }

        else{
            pred = curr;          // Potential predecessor
            curr = curr->right;
        }
    }

    return {pred, succ};
}

int main(){

    /*
              50
            /    \
          30      70
         / \     / \
       20  40   60  80
    */

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int key = 50;

    pair<Node*, Node*> ans = findPredSucc(root, key);

    cout << "Predecessor: ";
    if(ans.first)
        cout << ans.first->data;
    else
        cout << "NULL";

    cout << endl;

    cout << "Successor: ";
    if(ans.second)
        cout << ans.second->data;
    else
        cout << "NULL";

    return 0;
}

/*
*********************************************
            MISTAKES TO AVOID
*********************************************

1. Don't forget to break after finding the key.

2. Predecessor:
   Left subtree -> Rightmost node.

3. Successor:
   Right subtree -> Leftmost node.

4. While searching:
   Going LEFT updates successor.

   Going RIGHT updates predecessor.

5. Always check whether left/right subtree exists
   before searching inside it.

6. If predecessor or successor doesn't exist,
   return NULL.

*********************************************
          GOLDEN INTERVIEW TIPS
*********************************************

★ Inorder Traversal:
  Left -> Root -> Right

★ Predecessor = Previous element in inorder.

★ Successor = Next element in inorder.

★ You don't need to perform a complete inorder traversal.

★ BST property alone is sufficient to find both
  predecessor and successor in O(H) time.

Memory Trick:

Predecessor:
Left once -> Right till end.

Successor:
Right once -> Left till end.

During search:
Going LEFT updates successor.
Going RIGHT updates predecessor.
*/