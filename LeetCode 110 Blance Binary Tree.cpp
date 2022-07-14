class Solution {
public:
    int height (TreeNode* root){
       if(root==NULL)
           return 0;
        return max(height(root->left),height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
       if(root==NULL)
           return true;
        bool leftAns =isBalanced(root->left);
        bool rightAns =isBalanced(root->right);
        // abs mean absalute value
        bool diff= abs( height(root->left)-height(root->right))<=1;
        
        if(leftAns && rightAns && diff)
            return true;
        else
            return false;
    }
};
