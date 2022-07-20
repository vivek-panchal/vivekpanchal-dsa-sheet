class Solution {
public:
    bool solve (TreeNode* root,long long mini , long long maxi){
        if(root==NULL)
            return true;
        
        if(root->val>mini && root->val<maxi){
            bool left = solve(root->left,mini , root->val);
            bool right = solve(root->right, root->val,maxi);
            return left && right ;
            
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};
