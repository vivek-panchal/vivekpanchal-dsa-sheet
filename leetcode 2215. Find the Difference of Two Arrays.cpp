class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
       vector<vector<int>>ans;
    vector<int>ds;
    vector<int>ds2;
    unordered_set<int>s;
    unordered_set<int>s1;
    for(auto &it:nums1)s.insert(it);
     for(auto &it:nums2)s1.insert(it);
    for(auto it:s1)
    {
       if(s.find(it)==s.end())ds.push_back(it);
    }
     for(auto it:s)
    {
       if(s1.find(it)==s1.end())ds2.push_back(it);
    }
    ans.push_back(ds2);
    ans.push_back(ds);
    return ans;
  
    }
};
