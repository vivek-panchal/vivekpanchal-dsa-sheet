// using do while loop
class Solution {
public:
    string removeDuplicates(string s) {
        int count=0;
        int i=0;
        do{
            count=0;
            while(i<s.length())
            {
                if (s[i]== s[i+1]){
                    count++;
                    s.erase(i,2);
                    if(i>0){
                        i--;
                    }
                    break;
                }
                else{
                    i++;
                }
            }
        }
        while(count>0);
        return s;
    }
};

// using stack

class Solution {
public:
    string removeDuplicates(string s) 
    {
        string ans= "";
        stack<char> st;
        int i=0;
        while(i< s.length())
        {
            if(!st.empty() && s[i]== st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty())
        {
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
