class Solution {
public:
    void inorder(TreeNode* root, vector<int>&v){
        if(root==NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>v;
        inorder(root, v);
        int ans=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            ans=min(ans,v[i+1]-v[i] );
        }
        return ans;
    }
};