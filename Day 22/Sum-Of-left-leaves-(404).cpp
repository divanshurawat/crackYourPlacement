class Solution {
public:
    void addLeafs(TreeNode* root, int &sum){
        if(root==NULL) return;
        if (root->left && !root->left->left && !root->left->right) {
            sum += root->left->val;
        }
        addLeafs(root->left, sum);
        addLeafs(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        addLeafs(root, sum);
        return sum;
    }
};