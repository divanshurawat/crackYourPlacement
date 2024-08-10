class Solution {
public:
    int maxPathDown(TreeNode* root, int &maxi){
        if(root==NULL) return 0;
        int left=max(0, maxPathDown(root->left, maxi));
        int right= max(0, maxPathDown(root->right, maxi));
        //store the max path distance
        maxi=max(maxi, left+right+root->val);
        //return maximyum path from left subtree and right subtree to get max path distance
        
        return max(left, right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};