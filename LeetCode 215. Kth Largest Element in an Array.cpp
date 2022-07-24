class Solution {
public:
    int solve(vector<int>& nums, int n,int k){
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        // put first k element into min heap
        for(int i=0;i<k;i++){
            minHeap.push(nums[i]);
        }
        
        // compare remaining element 
        
        for(int i=k;i<n;i++){
            if(nums[i]>minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // int largest = nums[nums.size()-k];
        //  return largest;
        
        int n= nums.size();
        return solve(nums,n,k);
    }
};
