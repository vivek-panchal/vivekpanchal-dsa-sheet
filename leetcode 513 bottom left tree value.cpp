class Solution {
public:
    // find left view of binary tree , save it into vector and return last element of this vector
    void solve(TreeNode* root,vector<int> &ans,int lvl){
        if(root==NULL)
            return;
        if(lvl==ans.size())
            ans.push_back(root->val);
        solve(root->left,ans,lvl+1);
        solve(root->right,ans,lvl+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans;
        solve(root,ans,0);
        int n=ans.size()-1;
        return ans[n];
    }
};
