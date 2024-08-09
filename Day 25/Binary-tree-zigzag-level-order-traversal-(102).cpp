class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool flag=true; //left to right flag
        while(!nodesQueue.empty()){
            int size=nodesQueue.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node=nodesQueue.front();
                nodesQueue.pop();

                //find postion to fill the node's value
                int index=(flag)?i:(size-1-i);
                row[index]=node->val;
                if(node->left) nodesQueue.push(node->left);
                if(node->right) nodesQueue.push(node->right);
            }
        //after this level
        flag=!flag;
        result.push_back(row);
        }
        return result;
        
    }
};