class Solution {
public:
    bool isAnagram(string s, string t) {
        int n= s.length();
        int m= t.length();
        int freq[26]= {0};
        for(int i=0; i<n;i++){
            char ch = s[i];
            int index= ch -'a';
            freq[index]++;
        }
        for(int i=0; i<m;i++){
            char ch = t[i];
            int index= ch -'a';
            freq[index]--;
        }
        for(int i=0; i<26;i++){
         if(freq[i]!=0){
             return false;
         }
        }
        return true;
        
    }
};
