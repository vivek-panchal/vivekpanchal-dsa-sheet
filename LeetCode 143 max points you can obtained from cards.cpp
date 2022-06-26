class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        /*
        two poiters approach, take k elements from left
        example in 1 2 3 4 5 6 1 and k=3 take 1 2 3 from left
        now check sum if its max sum=6 , remove last left element and add first right element, remove 3 and add 1, 1 2 1-> sum=4 still not max , remove 2nd last left element and add 2nd right element, 1 1 6 , we get 8 which i max we can get
        */
        int l=k-1;
        int r=cp.size()-1;
        int leftsum = accumulate(cp.begin(),cp.begin()+k,0);
        int ans=leftsum;
        while(l>=0)
        {
            leftsum+=cp[r]-cp[l];
            ans=max(ans,leftsum);
            l--;
            r--;
        }
        return ans;
    }
};
