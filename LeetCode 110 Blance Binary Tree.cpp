class Solution {
public:
    int height (TreeNode* root){
       if(root==NULL)
           return 0;
        return max(height(root->left),height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
       if(root==NULL)
           return true;
        bool leftAns =isBalanced(root->left);
        bool rightAns =isBalanced(root->right);
        // abs mean absalute value
        bool diff= abs( height(root->left)-height(root->right))<=1;
        
        if(leftAns && rightAns && diff)
            return true;
        else
            return false;
    }
};


// PAIR WALA SOLUTION

class Solution {
public:
    pair<int,bool> solve(TreeNode*root){
        if(root==NULL)
            return make_pair(0,true);
        pair<int,bool> leftAns= solve(root->left);
        pair<int,bool> rightAns =solve(root->right);
        
        bool diff = abs(leftAns.first-rightAns.first)<=1;
        if(rightAns.second&&leftAns.second&&diff){
            return make_pair(max(leftAns.first,rightAns.first)+1,true);
        }
        else{
            return make_pair(max(leftAns.first,rightAns.first)+1,false);
        }
            
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans=solve(root);
        return ans.second;
    }
};
