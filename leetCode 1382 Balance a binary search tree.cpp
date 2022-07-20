class Solution {
public:
    void inorder(TreeNode* root,vector<int> &in){
    if (root==NULL)
        return ;
    inorder(root->left,in);
    in.push_back(root->val);
    inorder(root->right,in);
}
    TreeNode* createBst(int s,int e,vector<int>& in){
        if(s>e)
            return NULL;
        
        int mid= (s+e)/2;
        TreeNode* newNode=new TreeNode(in[mid]);
        newNode->left=createBst(s,mid-1,in);
        newNode->right=createBst(mid+1,e,in);
        return newNode;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        return createBst(0,in.size()-1,in);
    }
};
