class Solution {
public:
    void inorder(TreeNode*root, vector<int>&v){
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>v;
        inorder(root, v);
        int ans=0;
        for(auto it:v){
            if(it>=low && it<=high) ans+=it;
        }
        return ans;
    }
};