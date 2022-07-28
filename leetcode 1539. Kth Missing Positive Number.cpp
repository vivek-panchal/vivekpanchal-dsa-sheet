class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int start = 0, end = arr.size()-1;

		while(start<=end){

			int mid = start+(end-start)/2;

			if((arr[mid] - mid -1) < k) start = mid+1;
			else    end = mid-1;
		}
		return start + k;   
	}
};




/*
i.e.
(DRY RUN)

k = 5
arr = 2  3  4  7  11
idx = 0  1  2  3  4

strt = 0 , end = 4
mid = 2 (idx)

(arr[mid] - mid - 1) < k
(   4     - 2   - 1) < 5

1<5

strt = 3, end = 4
mid = 3

(arr[mid] - mid - 1) < k
(    7    -  3  - 1) <5
3<5

strt = 4, end = 4
mid = 4

(arr[mid] - mid - 1) < k
(    11    -  4  - 1) <5
6!<5

start =4 , end = 3  (---- loop breaking point----)

return start + k
		4    + 5 = 9 (ans) 
*/



// Upvote if it's Helpful :)
