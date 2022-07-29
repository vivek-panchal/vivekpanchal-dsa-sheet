class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=0;i<=n;i++){
            int temp = n;
            int start = 0;
            int end= n - 1;
            while (end >= start)
            {
                int mid = start + (end - start) / 2;
                if (nums[mid] >= i)
                {
                    temp = mid;
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }

            if ((n - temp) == i)
                return i;
        }
        return -1;
    }
};
