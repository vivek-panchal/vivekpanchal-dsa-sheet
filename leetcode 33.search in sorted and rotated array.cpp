class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            // check current element where we stand is our target or not , if yes return mid
            if(nums[mid]==target)
            {
                return mid;
            }
            // now check left part of mid is sorted or not 
            // if yes
            if(nums[mid]<=nums[h])
            {
               // check target mid se bda hai ya nhi , ager target mid se bda hai to check karo hight se chota hai ya nhi ager dono sahi hai to answer right part me hi ho sakta hai , left ko mid +1 kar do 
                if(target>nums[mid]&&target<=nums[h])
                    l=mid+1;
                else
                {
                   // else target left part me ho sakta hai
                    h=mid-1;
                }
            }
            else // if left part not sorted obv. right part definately sorted
            {
                // check target mid and low ki range me hai kya , ikf target mid and low ki range me hai to high ko mid -1 kar do, verna target mid and high ki range me hoga to left ko mid +1 kar do
                if(target<nums[mid]&&target>=nums[l])
                {
                    h=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }        
        }
        return -1;
    }
};
