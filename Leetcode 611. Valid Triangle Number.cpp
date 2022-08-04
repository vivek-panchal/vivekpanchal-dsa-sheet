class Solution {
public:
    int triangleNumber(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int res=0;
        for(int i=nums.size()-1;i>=0;i--){
            int lo=0,hi=i-1;
            while(lo<hi){
                if(nums[lo]+nums[hi]>nums[i]){
                    res+=hi-lo;
                    hi--;
                }
                else lo++;
            }
        }
        return res; 
    }
};
