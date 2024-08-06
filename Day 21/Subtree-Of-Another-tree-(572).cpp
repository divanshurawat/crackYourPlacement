class Solution {
public:
    bool isIdentical(TreeNode* a, TreeNode*b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val !=b->val) return false;
        return isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL) return true;
        if(root==NULL) return false;
        if(isIdentical(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};