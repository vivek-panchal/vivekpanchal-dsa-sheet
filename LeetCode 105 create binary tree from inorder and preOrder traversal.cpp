class Solution {
private:
    int findPosition(vector<int>& inorder, int element,int&inStr,int&inEnd){
        for(int i=inStr;i<=inEnd;i++){
            if(inorder[i]==element)
                return i;
        }
        return -1;
    }
    TreeNode* buildBinarytree(vector<int>& preorder, vector<int>& inorder, int &preIndex,int inStr,int inEnd){
        // base case
        // ager preorder pura traverse ho jaye ya fir inorder pura traverse ho jaye to dono hi case me null return krna hai
        if(preIndex>=preorder.size() ||inStr>inEnd){
            return NULL;
        }
        // pre order ke jis bhi element per khade hai usse save kra  lo bcs vo hi root hai and preorder ke index ko aage badha do
        int element = preorder[preIndex++];
        // element ke liye root bna do
        TreeNode* root = new TreeNode(element);
        // element ko inorder me dhundo kha per hai and elemnt ke left me left subtree and right me right me subtree ke liye call kar do
        int pos = findPosition(inorder,element,inStr,inEnd);
        
        // recursive call for left and right part respectively
        root->left= buildBinarytree(preorder,inorder,preIndex,inStr,pos-1);
        root->right= buildBinarytree(preorder,inorder,preIndex,pos+1,inEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // index of preOrder bcs first element of preOrder is always a root node 
        int index=0;
        // start and end of inorder bcs we need to search first element of preorder into inorder , start and end track in which part we need to search
        int start=0;
        int end=inorder.size()-1;
        return buildBinarytree(preorder,inorder,index,start,end);
        
    }
};
