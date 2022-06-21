class Solution {
private:
  void solve(vector<int>& candidates, int target,vector<int> &output,vector<vector<int>>&ans,int index,int sum){
    
    if(sum==target){
       ans.push_back(output);
       return;
    }
    if(sum>target){
       return;
    }
    if(index>=candidates.size())
        return;
    //include
    output.push_back(candidates[index]);
    sum = sum + candidates[index];
    solve(candidates,target,output,ans,index,sum);
    output.pop_back();
    sum-=candidates[index];
    //exclude
    solve(candidates,target,output,ans,index+1,sum);   
}
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> output;
    int sum=0;
    vector<vector<int>> ans;
    sort(candidates.begin(),candidates.end());
    solve(candidates,target,output,ans,0,sum);
    
    return ans;
        
    }
};
