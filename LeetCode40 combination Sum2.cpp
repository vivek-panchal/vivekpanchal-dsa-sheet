class Solution {
private:
void solve(vector<int> &candidates, int n, int target,vector<vector<int>> &ans,vector<int> &output,int sum,int index){
    if(sum==target){
       ans.push_back(output);
       return;
    }
    if(sum>target){
       return;
    }
    if(index>=n)
        return;
    //include
    output.push_back(candidates[index]);
    sum = sum + candidates[index];
    solve(candidates,n,target,ans,output,sum,index+1);
    output.pop_back();
    sum-=candidates[index];
    //exclude
    while(index+1<n && candidates[index]==candidates[index+1])
        index++;
    solve(candidates,n,target,ans,output,sum,index+1);
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n= candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        int sum=0;
        solve(candidates,n,target,ans,output,sum,0);
     return ans; 
    }
};
