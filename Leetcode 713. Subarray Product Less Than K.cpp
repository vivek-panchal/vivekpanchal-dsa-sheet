class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int ans=0;
        int product=1;
        int n= nums.size();
        while(right<n){
            product*=nums[right];
            while(product>=k && left<n ){
                product/=nums[left];
                left++;
            }
            if(product<k){
                ans+=right-left+1;
            }
            right++;
        }
        return ans;
    }
};
