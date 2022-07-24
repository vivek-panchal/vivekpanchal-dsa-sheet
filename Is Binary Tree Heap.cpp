class Solution {
  public:
  int countNode(struct Node* root){
      if(root==NULL){
          return 0;
      }
      int ans= 1+countNode(root->left)+countNode(root->right);
      return ans;
  }
  bool isCBT(struct Node* root,int index,int cnt ){
      if(root==NULL)
      return true;
      if(index>=cnt)
      return false;
      else
      {
          bool left= isCBT(root->left,2*index+1,cnt);
          bool right= isCBT(root->right,2*index+2,cnt);
          return left&&right;
      }
  }
  bool isMaxHeap(struct Node* root){
      if(root->left ==NULL && root->right==NULL)
      return true;
      if(root->right==NULL){
          return (root->data > root->left->data);
      }
      else{
          bool left = isMaxHeap(root->left);
          bool right= isMaxHeap(root->right);
          return (left && right && (root->data > root->left->data) && (root->data > root->right->data ));
      }
      
  }
    bool isHeap(struct Node* tree) {
        // code here
        int index=0;
        int nodeCount=countNode(tree);
        if(isCBT(tree,index,nodeCount)&&isMaxHeap(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};
