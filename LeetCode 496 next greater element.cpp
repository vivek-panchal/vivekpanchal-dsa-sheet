class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        int m=nums1.size();
        unordered_map<int,int> umap;
        stack<int> st;
        for(int i=n-1; i>=0;i--){
            int ele=nums2[i];
            while(!st.empty()&& st.top()<=ele){
                st.pop();
            }
            int res=(st.empty()) ? -1 : st.top();
            umap.insert({ele,res});
            st.push(ele);
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            int x= nums1[i];
            ans.push_back(umap[x]);
        }
        return ans;
    }
};
