class Solution {
private:
  void solve(int n, int k, int i,vector<vector<int>> &ans,vector<int> &output){
   if(k==0){
           ans.push_back(output); 
           return;
        }
    if(i>n){
        return;
    }
    //include
    output.push_back(i);
    solve(n,k-1,i+1,ans,output);
    output.pop_back();
    //exclude
    solve(n,k,i+1,ans,output);  
}
public:
    vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> output;
    solve(n,k,1,ans,output);
    return ans;
    }
};
