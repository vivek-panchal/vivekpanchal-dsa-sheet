class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       //vector of vector bna liya string type ka because isi format me ans return karna hai
        vector<vector<string>> ans;
        //unordered map bna lenge and usme anagram store kar lenge 
        // for example if we sort eat it becom aet -> all anagram of aet which present in input are store along with aet
        unordered_map<string,vector<string>> umap;
         // loop chla ke map me store kar lenge 
        for(auto x: strs){
            string temp=x;
            sort(x.begin(),x.end());
            umap[x].push_back(temp);
        }
        // group of anagrams ko ans vector me dal do and ans return kar do
        for(auto x: umap){
            vector<string> temp= x.second;
            ans.push_back(temp);
        }
        return ans;
        
    }
};
