class Solution {
public:
    void inorder(TreeNode* root, int &cnt, int k, int &kSmallest){
        if(root==NULL || cnt>=k) return;

        inorder(root->left, cnt, k, kSmallest );
        cnt++;
        if(cnt==k){
            kSmallest=root->val;
            return;
        }
        inorder(root->right, cnt, k ,kSmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kSmallest=-1;
        int cnt=0;
        inorder(root, cnt, k, kSmallest);
        return kSmallest;
    }
};