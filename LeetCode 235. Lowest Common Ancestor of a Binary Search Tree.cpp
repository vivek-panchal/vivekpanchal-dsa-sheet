class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        //ager root ki value badi hai p & q se to answer left me hoga 
        
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        // ager root ki value choti hai p & q se ans to right me hoga 
        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        // in all other case root hi answer hai 
        else
            return root;
        
       // return NULL;
    }
};
