#include <bits/stdc++.h>
using namespace std;

/*
    APPROACH:
    ---------
    Use Postorder Traversal (Left -> Right -> Root).

    For every subtree, return 4 pieces of information:
        1. maxi  -> maximum value in the subtree
        2. mini  -> minimum value in the subtree
        3. isBST -> whether the subtree itself is a BST
        4. size  -> number of nodes in the subtree

    BASE CASE:
    If root == NULL:
        maxi = INT_MIN
        mini = INT_MAX
        isBST = true
        size = 0

    For every node:
        First solve the left and right subtrees.

        size = left.size + right.size + 1

        maxi = max(root->data, right.maxi)
        mini = min(root->data, left.mini)

        The current subtree is a BST only if:
            1. left subtree is a BST
            2. right subtree is a BST
            3. root->data > left.maxi
            4. root->data < right.mini

        If current subtree is a BST:
            update the global answer with its size.

    WHY IT WORKS:
    -------------
    We need information about the entire left and right subtrees
    to decide whether the current subtree is a BST.

    Instead of repeatedly checking every subtree, we calculate
    all required information once during postorder traversal.

    Thus, every node is processed exactly once.

    TIME COMPLEXITY: O(N)
    SPACE COMPLEXITY: O(H)
    where H = height of the tree due to recursion stack.
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

class info {
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(Node* root, int& ans) {
    // base case
    if (root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currentNode;

    currentNode.size = left.size + right.size + 1;
    currentNode.maxi = max(root->data, right.maxi);
    currentNode.mini = min(root->data, left.mini);

    if (left.isBST &&
        right.isBST &&
        (root->data > left.maxi && root->data < right.mini)) {
        currentNode.isBST = true;
    }
    else {
        currentNode.isBST = false;
    }

    if (currentNode.isBST) {
        ans = max(ans, currentNode.size);
    }

    return currentNode;
}

int largestBST(Node* root) {
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main() {

    /*
             50
            /  \
           30   60
          / \   / \
         5  20 45  70
                   / \
                  65  80
    */

    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(45);
    root->right->right = new Node(70);

    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    cout << "Size of largest BST: " << largestBST(root) << endl;

    return 0;
}

/*
    MISTAKES TO AVOID:
    ------------------
    1. Don't check only left/right child values.
       We need left.maxi and right.mini because the BST
       condition applies to the ENTIRE subtree.

    2. Don't forget:
           left.isBST && right.isBST
       Even if the current root satisfies the value condition,
       the subtree is NOT a BST if either child subtree isn't a BST.

    3. Don't initialize NULL subtree information incorrectly.
       Use:
           maxi = INT_MIN
           mini = INT_MAX
           isBST = true
           size = 0

    4. Update ans ONLY when currentNode.isBST == true.

    5. Remember the direction:
           root->data > left.maxi
           root->data < right.mini

    GOLDEN INTERVIEW TIP:
    ---------------------
    Whenever a tree problem asks for information about a subtree
    and that information is required by the parent, think:

        "POSTORDER + RETURN INFORMATION"

    Here each node returns:
        {max value, min value, is BST, subtree size}

    This avoids repeatedly traversing subtrees and reduces the
    solution from potentially O(N^2) to O(N).

    ONE-LINE SUMMARY:
    -----------------
    Postorder traversal + return subtree info to determine whether
    each subtree is a BST and keep the maximum BST size.
*/