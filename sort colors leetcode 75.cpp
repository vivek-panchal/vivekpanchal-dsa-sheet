class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int s= 0;
        int m= 0;
        int h= n-1;
        while (m<=h){
        if (nums[m]== 0){
            swap(nums[s] , nums[m]);
            s++;
            m++;
        }
         else if (nums[m]== 1){
            m++;
        }
        else { swap(nums[m] , nums[h]);
                h--;
        }
            
        }    
    }
   
};
