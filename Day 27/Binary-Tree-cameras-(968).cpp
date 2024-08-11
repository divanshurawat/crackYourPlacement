class Solution {
public:
    int cam;
    unordered_set<TreeNode*> covered;

    int minCameraCover(TreeNode* root) {
        if (root == nullptr) return 0;
        cam = 0;
        covered.insert(nullptr); // Skip leaf nodes
        dfs(root, nullptr);
        return cam;
    }

    void dfs(TreeNode* node, TreeNode* parent) {
        if (node != nullptr) {
            dfs(node->left, node);
            dfs(node->right, node);

            // Check if a camera is needed at this node
            if ((parent == nullptr && covered.count(node) == 0) ||
                covered.count(node->left) == 0 || covered.count(node->right) == 0) {
                cam++;
                covered.insert(node);
                covered.insert(parent);
                covered.insert(node->left);
                covered.insert(node->right);
            }
        }
    }
};