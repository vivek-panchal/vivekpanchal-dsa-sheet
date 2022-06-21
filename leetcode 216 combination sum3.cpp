class Solution {
private:
void solve(int k, int n,vector<vector<int>> &ans,vector<int> &output, int sum, int i){
    // base case 
    if(sum>n)
        return;
    if(k==0){
        if(sum==n)
            ans.push_back(output);
        return;      
    }
    if(i>9)
        return;
    // include
    output.push_back(i);
    sum+=i;
    solve(k-1,n,ans,output,sum,i+1);
    output.pop_back();
    sum-=i;
    // exclude
    solve(k,n,ans,output,sum,i+1); 
}

public:
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> ans;
       vector<int> output;
       int sum=0;
       int i=1;
       solve(k,n,ans,output,sum,i);
          return ans;  
    }
};
