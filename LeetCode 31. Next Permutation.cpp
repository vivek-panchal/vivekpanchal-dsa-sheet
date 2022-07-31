class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index1=-1;
        int index2=-1;
        int n=nums.size()-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index1=i; 
                break;
            }
                
        }
        if(index1<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int j=n;j>index1;j--){
            if(nums[j]>nums[index1]){
                index2=j;
                break;
            }
        }
        swap(nums[index1],nums[index2]);
        reverse(nums.begin()+index1+1,nums.end());
        }
    }
};
