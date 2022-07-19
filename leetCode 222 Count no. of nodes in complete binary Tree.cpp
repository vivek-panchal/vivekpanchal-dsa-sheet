class Solution {
public:
    int countNodes(TreeNode* root) {
    
    if(!root) return 0;
    
    int lh=leftheight(root);
    int rh=rightheight(root);
    
    if(lh==rh) return pow(2,lh)-1;
    
    return 1+countNodes(root->left)+countNodes(root->right);
}

int leftheight(TreeNode *root){
    
    int ht=0;
    while(root){
        ht++;
        root=root->left;
    }
    return ht;
}

int rightheight(TreeNode *root){
    
    int ht=0;
    while(root){
        ht++;
        root=root->right;
    }
    return ht;
}
};

// second approach using preorder
class Solution {
public:
    int ans=0;
    int solve(TreeNode* root){
        
        if(root==NULL)
            return 0;
        
        
        solve(root->left);
        ans++;
        solve(root->right);
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        return solve(root);
    }
};
