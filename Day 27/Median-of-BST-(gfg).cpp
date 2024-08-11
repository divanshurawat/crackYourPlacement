void inorder(Node* root, vector<int>&v){
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
float findMedian(struct Node *root)
{
      //Code here
      vector<int>v;
      inorder(root,v);
      int n=v.size();
      if(n%2!=0){
          return v[n/2];
      }
      else{
          float x=v[n/2];
          float y= v[n/2 -1];
          return (x+y)/2;
      }
      return 0;
}