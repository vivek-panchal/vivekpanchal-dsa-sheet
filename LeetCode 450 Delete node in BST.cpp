class Solution {
public:
    int findPred(TreeNode* root){
        TreeNode* temp = root;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        if(key==root->val){
            //0 child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            //1 child
            // left child hai
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // right child present hai
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            //2 child
            if(root->left!=NULL && root->right!=NULL){
                // inorder pred. nikalo
                int pred= findPred(root->left);
                // copy pred into root
                root->val=pred;
                // delete pred
                root->left = deleteNode(root->left,pred);
            }
        }
        else if(key>root->val){
            root->right= deleteNode(root->right,key); 
        }
        else
            root->left= deleteNode(root->left,key);
        
        return root;
    }
};
