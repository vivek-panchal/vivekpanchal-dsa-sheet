class info{
public:
    int mini;
    int maxi;
    bool isBST;
    int sum;
};
class Solution {
public:
    info solve(TreeNode* root, int &ans){
        // base case
        if (root==NULL){
            return {INT_MAX,INT_MIN,true,0};
        }
        
        info left=solve(root->left,ans);
        info right = solve(root->right,ans);
        
        info curr;
        
        curr.sum = left.sum + right.sum + root->val;
        curr.mini = min(root->val,left.mini);
        curr.maxi = max(root->val,right.maxi);
        if(left.isBST and right.isBST and (left.maxi < root->val) and (right.mini > root->val)){
            curr.isBST = true;
        }
        else{
            curr.isBST = false;
        }
        
        if(curr.isBST){
            ans = max(ans,curr.sum);
        }
        return curr;
          
    }
    int maxSumBST(TreeNode* root) {
        int  maxSum=0;
        solve(root,maxSum);
        return maxSum;
    }
};
