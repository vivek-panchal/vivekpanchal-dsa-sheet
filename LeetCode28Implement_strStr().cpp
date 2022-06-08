class Solution {
public:
    int strStr(string haystack, string needle) {
       if(needle.length()!=0){
           int x=haystack.find(needle);
           if(x==string::npos){
               return -1;
           }
           else{
               return x;
           }
       }
        else{
            return 0;
        }
    }
};
