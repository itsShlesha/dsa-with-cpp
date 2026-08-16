#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEM STATEMENT:
    - Given two BSTs, merge them into a single balanced BST.
    - The resulting BST should contain all the nodes from both BSTs.
    - We need to maintain the BST property and keep the resulting tree
      balanced.

    APPROACH:
    - First perform inorder traversal on both BSTs.
    - Since inorder traversal of a BST gives sorted elements, we get
      two sorted arrays.
    - Merge these two sorted arrays using the two-pointer technique.
    - Now we have one sorted array containing all elements from both BSTs.
    - Construct a balanced BST from this sorted array by recursively
      choosing the middle element as the root.
    - Use the left half for the left subtree and the right half for
      the right subtree.

    WHY IT WORKS:
    - Inorder traversal converts both BSTs into sorted arrays.
    - Merging two sorted arrays gives one sorted array containing
      all elements.
    - Choosing the middle element recursively creates a balanced BST
      while maintaining the sorted/BST property.

    TIME COMPLEXITY:
    - Inorder traversals -> O(n + m)
    - Merging arrays -> O(n + m)
    - Constructing BST -> O(n + m)
    - Overall -> O(n + m)

    SPACE COMPLEXITY:
    - Inorder arrays + merged array -> O(n + m)
    - Recursion stack -> O(log(n + m))
    - Overall -> O(n + m)
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

void inorder(Node* root, vector<int>& in){
    if(root == NULL){
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int>& in1, vector<int>& in2){
    vector<int> ans(in1.size() + in2.size());

    int i = 0, j = 0;
    int k = 0;

    while(i < in1.size() && j < in2.size()){
        if(in1[i] < in2[j]){
            ans[k++] = in1[i];
            i++;
        }else{
            ans[k++] = in2[j];
            j++;
        }
    }

    while(i < in1.size()){
        ans[k++] = in1[i];
        i++;
    }

    while(j < in2.size()){
        ans[k++] = in2[j];
        j++;
    }

    return ans;
}

Node* inorderToBST(int s, int e, vector<int>& in){
    if(s > e){
        return NULL;
    }

    int mid = (s + e) / 2;

    Node* root = new Node(in[mid]);

    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);

    return root;
}

Node* mergeBST(Node* root1, Node* root2){

    //step1 : store inorder
    vector<int> in1, in2;

    inorder(root1, in1);
    inorder(root2, in2);

    //step2: merge two sorted arrays
    vector<int> mergedArray = mergeArrays(in1, in2);

    //step3: inorder to BST
    return inorderToBST(0, mergedArray.size() - 1, mergedArray);
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
    - Don't forget to return the merged vector from mergeArrays().
    - In inorderToBST(), recursively call inorderToBST(), NOT inorder().
    - Both inorder arrays are already sorted, so don't sort them again.
    - Remember to process the remaining elements after the main merge loop.
    - Always choose the middle element while constructing the final BST.

    GOLDEN INTERVIEW TIPS:
    - Whenever you see "merge two BSTs", think:
          BST1 -> Inorder -> Sorted Array
          BST2 -> Inorder -> Sorted Array
                         ↓
                    Merge Arrays
                         ↓
                   Sorted Array
                         ↓
                    Balanced BST
    - The problem is basically a combination of three standard patterns:
          1. BST -> Sorted Array
          2. Merge Two Sorted Arrays
          3. Sorted Array -> Balanced BST
    - The two-pointer merge is better than inserting every element of
      one BST into the other because it keeps the overall complexity linear.

    ONE-LINE SUMMARY:
    - Convert both BSTs to sorted arrays using inorder, merge them, then
      recursively build a balanced BST from the merged sorted array.
*/