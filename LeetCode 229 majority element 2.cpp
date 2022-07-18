class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count_1=0;
        int count_2=0;
        int ele_1;
        int ele_2;
        int n=nums.size();
        for(int i=0;i<n;i++){
             if(nums[i]==ele_1)
                count_1++;
            else if(nums[i]==ele_2)
                count_2++;
           else if(count_1==0){
                ele_1=nums[i];
                count_1++;
                continue;
            }
            else if(count_2==0){
                ele_2=nums[i];
                count_2++;
                continue;
            }
            else{
                count_1--;
                count_2--;
            }
        }
        vector<int> ans;
        count_1=count_2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele_1) count_1++;
            if(nums[i]==ele_2) count_2++;
        }
        if(count_1>n/3)ans.push_back(ele_1);
        if(count_2 > n/3 )ans.push_back(ele_2);
        return ans;
    }
};
