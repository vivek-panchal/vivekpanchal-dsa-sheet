class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        long long int sum=0;
        for(int i=0;i<=nums.size()-1;i++){
            sum= sum+nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};
