class Solution {
  public:
    //anyone help me with the soln.
    Node* createMapping(Node*&root,int target,map< Node*,Node* > &m){
        
        // mapping for node to its parent
        //as for every node ,its left chil ,right child and its parent will burn
        //we can access left and right. but for parent we need mapping
        Node* res = NULL;
        queue<Node*>q;
        q.push(root);
        m[root]=NULL;
        
        while(!q.empty()){
            Node*front = q.front();
            q.pop();
            
            if(front->data==target)res = front;
            
            if(front->left){
                // as left child  parent will be front
                m[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                m[front->right]=front;
                q.push(front->right);
            }
        }
        
        return res;
        
    }
  
    // Burning Tree
    int burnTree(Node*&root, map<Node*,Node*> &m){
        
        //creating a map to check if that node is already visited or not
        map<Node*,bool> visited;
        queue<Node*>q;
        q.push(root);
        visited[root]=true;
        
        //time to burn tree.
        int ans = 0;
        
        //queue for traversal
        
        
        
        //Level Order Traversal
        while(!q.empty())
        {
            
            bool flag = 0;
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
            Node*front = q.front();
            q.pop();
            
            if(front->left && !visited[front->left]){
                flag=1;
                q.push(front->left);
                visited[front->left]=1;
               }
            
            if(front->right && !visited[front->right]){
                flag=1;
                q.push(front->right);
                visited[front->right]=1;
                }
            
            if(m[front] && !visited[m[front]]){
                flag=1;
                q.push(m[front]);
                visited[m[front]]=1;
                }
            }
            
            if(flag==1)
                ans++;
        }
        
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        // 3 steps :-
        // 1) Create node to its parent mapping.
        // 2) Finding target node.
        // 3) Burn Tree in minimum time.
        
        map<Node*,Node*> nodeToParent;
        Node * targetNode = createMapping(root,target,nodeToParent);
        
        int ans = burnTree(targetNode,nodeToParent);
        return ans;
    }
};
