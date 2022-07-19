class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       //search root p & q
        // current node null hai to return null kar do ki yha p & q nhi mili
        if(root==NULL)
           return NULL;
        // ager p or q me se koi bhi mil jaye to usse  hi upper bhej do ki root mil gyi
        if(root==p || root ==q)
            return root;
        else
        {
            // ager p & q na mile to left me search karo and fir right me 
            TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
            TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);
            // jis node per hame abhi hai ager uske left se bhi non null & right se bhi non null ans aaye to ye hi LCA hai current node ko return kar do 
            if(leftAns!=NULL && rightAns!=NULL )
                return root;
            // ager kisi ek side se non null aara  hai to non null ko return kar do
            if(rightAns==NULL)
                return leftAns;
            else 
                return rightAns;
        }
    }
};

