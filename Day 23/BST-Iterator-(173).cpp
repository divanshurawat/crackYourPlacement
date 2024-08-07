class BSTIterator {
    stack<TreeNode*> mystack;
public:

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp=mystack.top();
        mystack.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !mystack.empty();
    }
//private:
    void pushAll(TreeNode* node){
        for(; node!=NULL; mystack.push(node), node=node->left);
    }
};