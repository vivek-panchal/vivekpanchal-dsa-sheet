class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len=0;
        int sum1=0;
        int sum2=0;
        int n= nums.size();
        for(int i=0; i<n;i++){
            sum1=sum1+nums[i];
        }
        sum1=sum1-x;
        if(sum1==0)
            return n;
        // sliding window
        int i=0;
        int j=0;
        for(j=0;j<n;j++){
            sum2=sum2+nums[j];
            while(i<n && sum2>sum1){
                sum2 = sum2-nums[i];
                i++;
            }
            if(sum1==sum2){
                len = max(len , j-i+1);
            }      
        }
        if(!len)
                return -1;
        return n-len;
    }
};
