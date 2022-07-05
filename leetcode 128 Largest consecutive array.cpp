// ------------------------------------brute force ---------TC=O(NLOGN) || SC+O(1)------------------------

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();
        if(n==0)
           return 0;
		
		// sort the vector so that the consecutive elements become adjacent to each other
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        int c=1,ans=0;
        for(int i=1;i<n;i++)
        {
             /*nums[i] == nums[i-1]+ 1: This means the current element is consecutive to previous, 
			  so increment current streak count. */
            if(nums[i]==prev+1)
            {
                prev=nums[i];
                c++;
            }
			
		  /*nums[i] == nums[i-1]: We have found the same element as previous. Skip it, and see if we can
		still extend the sequence with next elements.*/
		
		/* when nums[i]!=nums[i-1] means we have got one of our answers,  now we can search next 
		longest  sequence */
		
            else if(nums[i] != prev)
            {
                ans=max(c,ans);
                c=1;
                prev=nums[i];
            }
        }
        ans=max(c,ans);
        return ans;
    }
};


// -----------------------SET Solution TC=O(N) SC=O(N)-----------------------------------------
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ek unordered set bna lo 
        unordered_set<int> hashset;
        
        // check if array have 0 or 1 size then return size of array
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return 1;
        }
         
        // array ke sare elemnt set me dal do
        for(int num: nums){
            hashset.insert(num);
        }
        
        int longestStreak=0;
        
        for(int num: nums){
            if(hashset.find(num-1) == hashset.end()){
                int currNum=num;
                int currStreak=1;
                
                while(hashset.find(currNum+1)!= hashset.end()){
                    currNum+=1;
                    currStreak+=1;
                }
                
                longestStreak=max(longestStreak,currStreak);
            }
        }
        
        return longestStreak;
    }
};
