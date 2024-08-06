class Solution {
public:
    TreeNode* buildBalancedBST(vector<int>&nums, int l, int r){
        if(l>r) return NULL;
        int mid=(l+r)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=buildBalancedBST(nums, l, mid-1);
        node->right=buildBalancedBST(nums, mid+1, r);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* newRoot= buildBalancedBST(nums, 0, nums.size()-1);
        return newRoot;
    }
};