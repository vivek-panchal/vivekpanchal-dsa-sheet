class Solution {
private:
    vector<string> ans;
private:
    void solve(TreeNode* root, string temp){
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL){
            temp += to_string(root -> val);
            ans.push_back(temp);
        }
        temp = temp + to_string(root -> val) + "->";
        solve(root -> left, temp);
        solve(root -> right, temp);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");
        return ans;
    }
};
