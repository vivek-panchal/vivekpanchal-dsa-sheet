Approach 1 using sorting

```
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0;
        int n= s.length();
        int m= t.length();
        if(m<n|| n<m)
            return false;
        else
        {
           while(i<s.size()){
            if(s[i]==t[i])
                i++;
            else 
                return false;
            } 
        }
        
        return true;
    }
};

```
**Approach 2 using hash map**

```
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
