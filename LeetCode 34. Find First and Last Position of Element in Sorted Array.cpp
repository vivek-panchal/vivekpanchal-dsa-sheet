class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
    res.push_back(-1);
    res.push_back(-1);
    int st=0,end=nums.size()-1;
    while(st<=end)
    {
        int mid = st + ((end-st)/2);
        if(nums[mid]==target)
        {
            res[0]=mid;
            end=mid-1;
        }
        if(nums[mid]<target)
            st=mid+1;
        else 
            end=mid-1;
    }
    st=0;
    end=nums.size()-1;
    while(st<=end)
    {
        int mid = st + ((end-st)/2);
        if(nums[mid]==target)
        {
            res[1]=mid;
            st=mid+1;
        }
        else if(nums[mid]<target)
            st=mid+1;
        else 
            end=mid-1;
    }
    return res;
        
    }
};
