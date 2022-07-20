bool search(vector<int> &in,int target){
    int i=0;
    int j= in.size()-1;
    while(i<j){
        if(in[i]+in[j]==target){
            return true;
        }
        if(in[i]+in[j]>target){
            j--;
        }
        if(in[i]+in[j]<target){
            i++;
        }
    }
    return false;
}
void inorder(BinaryTreeNode<int>* root,vector<int> &in){
    if (root==NULL)
        return ;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
  //Write your code here
    vector<int> in;
    inorder(root,in);
    return search(in,target);
}
