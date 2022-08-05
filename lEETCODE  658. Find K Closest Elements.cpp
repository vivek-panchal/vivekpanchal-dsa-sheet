//**************************************************************** TWO POINTER APPROACH *********************************************************************

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=0;
        int j=arr.size()-1;
        
        while(i < j && j-i+1 != k) {
            int diff1 = abs(arr[i] - x);
            int diff2 = abs(arr[j] - x);
            if(diff1 <= diff2) {
                j--;
            } else {
                i++;
            }
        }
        
        vector<int> ans;
        for(int x=i;x<=j;x++) {
            ans.push_back(arr[x]);
        }
        return ans;

    }
};

// Binary Search Approach
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0, high = arr.size()-k;
        while (low < high){
            
            int mid = low + (high - low)/2;
            if(x - arr[mid] > arr[mid + k] - x){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[low+i]);
        }
        
        return ans;
        
    }
};
