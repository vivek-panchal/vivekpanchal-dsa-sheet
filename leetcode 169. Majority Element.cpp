class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int e=-1;
        for (int i=0; i<nums.size();i++){
            if(count==0){
                e=nums[i];
            }
            if(e==nums[i])
                count++;
            else 
                count--;
        }
        return e;
    }
};
