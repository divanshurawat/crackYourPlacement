lass Solution {
public:
    int pathSum_a(TreeNode* root, long long sum){
        if(!root) return 0;
        int res = 0;
        if(root->val == sum) res++;
        res += pathSum_a(root->left, sum - root->val);
        res += pathSum_a(root->right, sum - root->val);
        return res;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        return pathSum(root->left, targetSum) + pathSum_a(root, (long long)targetSum) + pathSum(root->right, targetSum);
    }
};