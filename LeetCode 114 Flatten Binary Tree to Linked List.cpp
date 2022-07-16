class Solution {
public:
    void flatten(TreeNode* root) {
        // dry run & moris traversal for better understanding
       TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode*prev =curr->left;
                while(prev->right!=NULL)
                    prev=prev->right;
                prev->right=curr->right;
                curr->right=curr->left;
                //left pointer ko Null per point krana bhi hai
                curr->left=NULL:
            }
            curr=curr->right;
        }
    }
};
