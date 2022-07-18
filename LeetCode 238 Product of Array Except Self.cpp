class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> leftPro (n,1);
        vector<int> rightPro(n,1);
        
        for(int i = 1; i<n; i++){
            leftPro[i] = leftPro[i-1]*nums[i-1];
            rightPro[n-i-1] = rightPro[n-i]*nums[n-i];
        }
             
        for(int k = 0; k<n; k++){
            ans[k] = leftPro[k]*rightPro[k];
        }
        return ans;
    }
};
