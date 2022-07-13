class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       // ager root ho hi na , tree empty hai
        if(!root)   return {};
        // vector bna lo answer store karne ke liye 
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        // queue me root dal di
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; ++i) {
                // tu nikal
                TreeNode* node = q.front();
                q.pop();
                // node ko temp me dal lo baad me temp ko ans me dal denge bcs vector of vector return karna hai
                temp.push_back(node -> val);
                // bache chod ja 
                if(node -> left)    q.push(node -> left);
                if(node -> right)    q.push(node -> right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
