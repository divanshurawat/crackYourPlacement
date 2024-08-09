class Solution{
public:
    void inorder(Node*root, int &cnt, int l ,int h){
        if(root==NULL) return;
        inorder(root->left, cnt, l, h);
        if(root->data>=l && root->data<=h) cnt++;
        inorder(root->right, cnt, l, h);
    }
    int getCount(Node *root, int l, int h)
    {
      // your code goes here  
      int cnt=0;
      inorder(root, cnt, l, h);
      return cnt;
    }
};