class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
       // ager root hi null hai to target kha hoga NULL hi return kar do
        if(root==NULL)
            return NULL;
        // ager target root ke equal hai to ye hi answer hai root ko return kar do
        if(root->val==val)
            return root;
        // root ki value target se badi hai to left me answer ho sakta hai left me jao
        if(root->val>val)
            return searchBST(root->left,val);
        // ager root ki value target target se choti hai to left me answer possible nhi hai right me search karo
        if(root->val<val)
            return searchBST(root->right,val);
        
        return NULL;    
    }
};
