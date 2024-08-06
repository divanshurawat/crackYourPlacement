class Solution {
public:
    bool check(TreeNode* root, int targetSum, int sum){
        if(root==NULL) return false;
        sum+=root->val;
        if(sum==targetSum && (!root->left && !root->right)) return true;
        if(check(root->left, targetSum, sum)) return true;
        if(check(root->right, targetSum, sum)) return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return check(root, targetSum, sum);
    }
};