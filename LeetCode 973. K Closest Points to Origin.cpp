//****************************************************************  MAX HEAP SOLUTION *****************************************************************************
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> ans;
		
        //pair is using to store a*a+b*b &  value of pointes[i] 
        priority_queue<pair<int,vector<int>>> pq;
        
        for(int i=0;i<points.size();i++){
            long long int value=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({value,points[i]});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

};
//****************************************************************  MIN HEAP SOLUTION *****************************************************************************
class Solution {
    class info{
    public:
        int val,x,y;
        info(int v,int a,int b)
        {
            val=v;
            x=a;
            y=b;
        }
    };
    
    class comp{
    public:
        bool operator()(info a,info b){
            return a.val>b.val;
        }
    };
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // min heap create kara 
        priority_queue<info,vector<info>,comp> pq;
        
        for(auto it:points)
        {
            // sab index ka origin se distance nikalao
            long long val = it[0]*it[0] + it[1]*it[1];
            // distance ko indexs ke sath heap me dal do
            pq.push(info(val,it[0],it[1]));
            
        }
        vector<vector<int>> ans;
        
        while(!pq.empty() && k--)
        {
            // heap ke top ko answer me push kar do and top ko pop kar do 
            info temp = pq.top();
            pq.pop();
            ans.push_back({temp.x,temp.y});
        }
        return ans;
    }
};
