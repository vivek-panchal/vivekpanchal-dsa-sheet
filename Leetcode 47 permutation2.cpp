class Solution {
private:
    void solve(vector<int> &arr,vector<vector<int>>&ans,int index, int n){
    if(index>=n){
        ans.push_back(arr);
        return;
    }
    unordered_set<int> m;
    for(int i=index;i<n;i++){
        if(m.find(arr[i])!=m.end())
           continue;
        m.insert(arr[i]);
        swap(arr[index],arr[i]);
        solve(arr,ans,index+1,n);
        swap(arr[index],arr[i]);
    }
}    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        solve(nums,ans,0,n);
        return ans;
    }
};
