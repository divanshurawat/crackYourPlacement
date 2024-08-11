/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int countNodes(Node* node) 
     {
        if (node == NULL) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
    
     bool isBST(Node* node, int min, int max) 
     {

        if (node == NULL) return true;
        if (node->data < min || node->data > max) return false;
        return isBST(node->left, min, node->data - 1) && isBST(node->right, node->data + 1, max);
    }
    
    
    int largestBst(Node *root)
    {
        
     if (isBST(root, INT_MIN, INT_MAX)) return countNodes(root);
        int left = largestBst(root->left);
        int right = largestBst(root->right);

        return max(left, right);
    }
};