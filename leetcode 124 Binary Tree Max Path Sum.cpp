class Solution {
public:
    int solve(TreeNode* node , int & maxi){
        if(node==NULL)
            return 0;
        // max of 0 and solve isliye liya ki kabhi solve se negative value aaye to ham 0 store kare
        int left= max(0,solve(node->left,maxi));
        int right=max(0,solve(node->right,maxi));
        maxi=max(maxi,left+right+node->val);
        return max(left,right)+node->val;
    }
    int maxPathSum(TreeNode* root) {
       int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};
