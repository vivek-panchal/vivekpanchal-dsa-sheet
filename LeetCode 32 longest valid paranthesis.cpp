class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        stack<int> index;
        index.push(-1);
        int length=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                index.push(i);
            }
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                    index.pop();
                    int top=index.top();
                    int temp= i-top;
                    length=max(length,temp);
                }
                else{
                    index.push(i);
                }
            }
        }
        return length;
    }
};
