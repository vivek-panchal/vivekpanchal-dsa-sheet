class Solution {
public:
    bool solve(TreeNode* a,TreeNode* b){
        if(a==NULL && b==NULL)
            return true;
        if(a!=NULL && b==NULL)
            return false;
        if(b!=NULL && a==NULL)
            return false;
        if(a->val!=b->val)
            return false;
        
        // a ka left b ke right ke equal hona chaiye and vice versa
        return solve(a->left,b->right) && solve(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
       if(root==NULL)
           return true;
        return solve(root->left,root->right);
    }
};
