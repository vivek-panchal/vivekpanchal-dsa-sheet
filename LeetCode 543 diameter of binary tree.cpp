class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
        
    }
    int diameter(TreeNode* root){
        if(root==NULL)
            return 0;
        int op1=diameter(root->left);
        int op2=diameter(root->right);
        int op3= 1+height(root->left)+height(root->right);
        return max(op1,max(op2,op3));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        return diameter(root)-1;
    }
};
