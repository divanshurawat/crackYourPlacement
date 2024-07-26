Node* BST(vector<int>& nums, int i, int j){
        if(i>j){
            return nullptr;
        }
        int mid=(i+j)/2;
        Node* curr=new Node(nums[mid]);
        curr->left=BST(nums, i, mid-1);
        curr->right=BST(nums, mid+1, j);
        return curr;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        int i=0, j=nums.size()-1;
        return BST(nums, i, j);
    }