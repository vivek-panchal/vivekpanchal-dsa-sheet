class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
// Standard category of questions where we need to apply some
// conditions on subarrays . Here is an approach you can try for these questions.
//      use a high and a low pointer
        int low=0;
        int high=0; 
        int sum=0;
        int ans=INT_MAX;//This variable denotes the size of subarray .
// If the value remains INT_MAX , we can conclude we didnt find any subarray
// satisfying the conditions and return 0. 
        while(high<nums.size())
        {
// Logic-> First find the first possible subarray(In this case find a 
// subarray from the beginning which has sum>=target).Once the sub array is found shift
// the low pointer to reduce it as much as possible to minimise the size.
            sum+=nums[high];
            while(sum>=target)
            {
 // since sum is now >=target we can safely store the size of subarray which is 
// high-low+1.We will now delete elements from the beginning as long as the remaining sum is greater/equal to target.
                ans=min(ans,high-low+1);
                sum-=nums[low];
                low++;
            }
            high++;
        }
        if(ans==INT_MAX)return 0;
        return ans;
    }
};
