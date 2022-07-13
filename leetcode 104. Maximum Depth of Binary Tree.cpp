class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int leftAns= maxDepth(root->left);
        int rightAns= maxDepth(root->right);
        
        return 1+ max(rightAns,leftAns);
    }
};
