class Solution {
public:
    bool valid(TreeNode* root, long minVal, long maxVal){
        if(root==NULL) return true;
        if(root->val>=maxVal || root->val<=minVal) return false;
        return valid(root->left, minVal, root->val) &&
                valid(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
};