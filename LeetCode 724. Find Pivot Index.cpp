class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n =nums.size();
        int sum=0;
        int leftSum=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0; i<=n-1;i++){
            if(leftSum==sum-nums[i])
                return i;
            
            sum=sum-nums[i];
            leftSum=leftSum+nums[i];
        }
        
        return ans;
    }
};
