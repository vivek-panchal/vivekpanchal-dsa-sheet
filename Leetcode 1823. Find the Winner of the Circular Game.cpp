// It is a Josephus Problem
// easy to understand
class Solution {
private:
    void solve(vector<int>v,int k,int index,int &ans){
        if(v.size()==1){
            ans=v[0];
            return;
        }
        index=(index+k)%v.size();
        v.erase(v.begin()+index);
        solve(v,k,index,ans);
    }
public:
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        k--;
        int index=0;
        int ans=-1;
        solve(v,k,index,ans);
        return ans;
    }
};
//dificult to understand
class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1)
        return 1;
        return (findTheWinner(n-1,k)+k-1)%n+1;
    }
};
