class Solution {
    int findPosition(vector<int>& inorder, int element,int&inStr,int&inEnd){
        for(int i=inStr;i<=inEnd;i++){
            if(inorder[i]==element)
                return i;
        }
        return -1;
    }
    TreeNode* buildBinarytree(vector<int>& postorder, vector<int>& inorder, int &postIndex,int inStr,int inEnd){
        // base case
        // ager postorder pura traverse ho jaye ya fir inorder pura traverse ho jaye to dono hi case me null return krna hai
        if(postIndex<0 ||inStr>inEnd){
            return NULL;
        }
        // postorder ke jis bhi element per khade hai usse save kra  lo bcs vo hi root hai and postorder ke index ko piche le jao
        int element = postorder[postIndex--];
        // element ke liye root bna do
        TreeNode* root = new TreeNode(element);
        // element ko inorder me dhundo kha per hai and elemnt ke right me right subtree ke liye call kar do and left me left subtree  
        int pos = findPosition(inorder,element,inStr,inEnd);
        
        // recursive call for  right  left part respectively
        root->right= buildBinarytree(postorder,inorder,postIndex,pos+1,inEnd);
        root->left= buildBinarytree(postorder,inorder,postIndex,inStr,pos-1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // important thing postorder ko piche se traverse karenge bcs last node root node hoti hai && right recursive call phle aayegi bcs POSTORDER is [L,R,N]
        // index of postorder bcs last element of postorder is always a root node 
        int index=postorder.size()-1;
        // start and end of inorder bcs we need to search first element of preorder into inorder , start and end track in which part we need to search
        int start=0;
        int end=inorder.size()-1;
        return buildBinarytree(postorder,inorder,index,start,end);
    }
};
