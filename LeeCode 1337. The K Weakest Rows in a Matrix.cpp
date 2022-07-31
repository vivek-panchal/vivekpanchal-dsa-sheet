class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>v;
        
        int m = mat[0].size();
        int n=mat.size();
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=0; j<m;j++)
            {
                // ise number of 1 kitne hai row me vo pta chal jayega 
             sum+=mat[i][j];   
            }
            // kis row mw kitne 1 hai vo store kar lo 
            v.push_back(make_pair(sum,i));
        }
        vector<int>ans;
        sort(v.begin(),v.end());
        for(int i=0; i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        
        return ans;             
    }
};
