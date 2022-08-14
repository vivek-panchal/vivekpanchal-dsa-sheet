// small change in house robbers

class Solution {
public:
    int solve(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,-1);
         int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1)
                pick+=prev2;
            int dontPick=0+prev;
            int curr=max(pick,dontPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
         int n=nums.size();
        if(n==1)
            return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=n-1)
                temp2.push_back(nums[i]);
        }
        return max(solve(temp1),solve(temp2));
    }
};
