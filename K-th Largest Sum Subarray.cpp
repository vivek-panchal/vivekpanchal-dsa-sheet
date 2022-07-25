// simple approach TC = O(N^2logN) and SC=O(N^2)

#include<algorithm>
int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sumStore;
    int n= arr.size();
    // store sum of all sub array 
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum +=arr[j];
            sumStore.push_back(sum);
        }
    }
    // sort the sum of subarrays and return Kth element from the end
    sort(sumStore.begin(),sumStore.end());
    return sumStore[sumStore.size()-k];
}


//---------------optimal solution using min heap --------TC=O(N^2) SC=O(K)----------
#include<algorithm>
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int,vector<int>,greater<int>> mini;
    int n= arr.size();
    // store sum of all sub array 
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum +=arr[j];
            if(mini.size()<k){
                mini.push(sum);
            }
            else{
                if(mini.top()<sum){
                    mini.pop();
                    mini.push(sum);
                } 
            }
        }
    }

    return mini.top();
}
