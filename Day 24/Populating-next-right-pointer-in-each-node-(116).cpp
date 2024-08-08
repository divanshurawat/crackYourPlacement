class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        Node* curr=root;
        while(curr->left!=NULL){
            Node* temp=curr;
            while(curr){
                curr->left->next=curr->right;
                curr->right->next=  curr->next==NULL?NULL: curr->next->left;
                curr=curr->next;
            }
            curr=temp->left;
        }
        return root;
    }
};