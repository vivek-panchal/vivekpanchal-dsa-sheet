class Solution {
public:
    int arrangeCoins(int n) {
        long long start = 0;
        long long end = n;
        int ans = 1;
        while(start <= end)
        {
            long long  mid = start + ((end-start)/2);
            long long total = (mid*(mid+1)/2);
            if(total <= n)
            {
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};
