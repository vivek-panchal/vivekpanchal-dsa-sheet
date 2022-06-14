class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0;
        int end=s.size()-1;
        while(start<end){
            swap(s[start++],s[end--]);
        }
    }
};
// recursive solution 
class Solution {
   void reverse(vector<char>& s , int i, int j){
        
        //base case
        if(i>j)
            return;
        swap(s[i],s[j]);
            
        i++;
        j--;
        reverse(s,i,j);
    }
public:
    void reverseString(vector<char>& s) {
        reverse(s,0,s.size()-1);
            
    }
};
