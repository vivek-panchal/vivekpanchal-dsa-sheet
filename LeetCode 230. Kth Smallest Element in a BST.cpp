class Solution {
public:
    // inorder traversal karenge bcs BST ka inorder traversal sorted hota hai , har ek iteration ke baad k ko decriment kar denge , jab k==0 ho jaye to jiss node per ham hi vhi kth smallest node hai 
    void inorder(TreeNode *root, int &k, int &ans){
        if(ans != -1) return;
        if(root == NULL) return;
        inorder(root->left, k, ans);
        k--;
        if(k == 0) {
            ans = root->val;
            return;
        }
        inorder(root->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};
