class Solution {
public:
    TreeNode* mergeTree(TreeNode* root1, TreeNode* root2){
        int x=root1->val+ root2->val;
        TreeNode* node= new TreeNode(x);
        if(root1->right && root2->right){
            node->right=mergeTree(root1->right, root2->right);
        } 
        else if(!root1->right) node->right=root2->right;
        else if(!root2->right) node->right= root1->right;

        if(root1->left && root2->left){
            node->left=mergeTree(root1->left, root2->left);
        } 
        else if(!root1->left) node->left=root2->left;
        else if(!root2->left) node->left= root1->left;

        return node;

    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;

        TreeNode* root=mergeTree(root1,root2);
        return root;
    }
};