// using recursion

#include<bits/stdc++.h>
void solve(vector<int> &arr,vector<vector<int>>&ans,int index, int n){
  // base case 
  if(index>=n){
        ans.push_back(arr);
        return;
    }
  //store all character/element into set for prevent duplicasy
    unordered_set<int> m;
    for(int i=index;i<n;i++){
      // check the element is already present in set or not . i not present than continue
        if(m.find(arr[i])!=m.end())
           continue;
      // insert element into set
        m.insert(arr[i]);
      // swap elements to make permutation 
        swap(arr[index],arr[i]);
        solve(arr,ans,index+1,n);
      // back track element to make orignal array or string for next iteration
        swap(arr[index],arr[i]);
    }
}

vector<vector<int> > uniquePermutations(vector<int> &arr, int n) {
	// Write your code here.
    vector<vector<int>> ans;
    solve(arr,ans,0,n);
    return ans;
}
