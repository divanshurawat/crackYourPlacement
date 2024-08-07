class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parent;
    void inorder(TreeNode* root){
        if(!root) return;
        if(root->left !=NULL)
            parent [root->left]=root;
        inorder(root->left);

        if(root->right !=NULL)
            parent [root->right]=root;
        inorder(root->right);
        
    }

    void BFS(TreeNode* target, int k, vector<int>&result){
        queue<TreeNode*>q;
        q.push(target);

        unordered_set<int>visited;
        visited.insert(target->val);

        while(q.empty()){
            int n=q.size();
            if(k==0) break;

            while(n--){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left!=NULL && !visited.count(curr->left->val)){
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }

                if(curr->right!=NULL && !visited.count(curr->right->val)){
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }

                if(parent.count(curr) && !visited.count(parent[curr]->val)){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        while(q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            result.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>result;
        inorder(root);

        BFS(target, k , result);
        return result;
    }
};