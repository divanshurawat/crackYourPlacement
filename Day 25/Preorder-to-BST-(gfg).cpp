class Solution {
  public:
    Node* build(int pre[], int &i, int bound, int size){
        if(i==size || pre[i]>bound) return NULL;
        Node* root=newNode(pre[i++]);
        root->left=build(pre, i, root->data, size);
        root->right= build(pre, i, bound, size);
        return root;
    }
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // code here
        int i=0;
        return build(pre, i, INT_MAX, size);
    }
};