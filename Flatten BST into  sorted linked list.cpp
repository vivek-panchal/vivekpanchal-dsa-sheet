
void inorder(TreeNode<int>* root,vector<int> &in){
    if (root==NULL)
        return ;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> in;
    inorder(root,in);
    TreeNode<int>* newRoot= new TreeNode<int> (in[0]);
    TreeNode<int>* curr=newRoot;
    // 2nd step
    for(int i=1;i<in.size();i++){
        TreeNode<int>* temp=new TreeNode<int> (in[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    // 3rd step
    curr->left=NULL;
    curr->right=NULL;
    return newRoot;
}
