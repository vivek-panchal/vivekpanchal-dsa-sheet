class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       // use multiset bcs we need to sort those value who overlap 
        map<int, map<int,multiset<int> > > nodes;
        queue< pair<TreeNode*, pair<int,int> > > q;
       vector<vector<int>> ans;
        
        if(root == NULL)
            return ans;
        // push first node into queue with level and  number line vertices/horizontal distance   
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()) {
            pair<TreeNode*, pair<int,int> > temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            // insert first node into map with hd mean horizontal distance and level
            nodes[hd][lvl].insert(frontNode->val);
            // left and right child of node ko queueu me dal do
            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
                
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
        // map ke second ka second multiset hai uski value ko nans me dalna hai iterate kar ke dal do
       for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
           
            ans.push_back(col);
        }
        
        return ans;
    }
};
