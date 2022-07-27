class Solution {
public:
    int firstBadVersion(int n) {
        int start=0;
        int end=n;
        int mid=0;
        int ans=0;
        while(start<=end){
            mid=start+(end-mid)/2;
            if(isBadVersion(mid)){
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
};
