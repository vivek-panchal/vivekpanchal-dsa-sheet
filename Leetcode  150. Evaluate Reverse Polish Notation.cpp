class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // create a stack
        stack<int>st;
        // iterate given string
        for(auto x: tokens){
            // ager string[i] koi operator hai to stack se 2 element nikalo and vo operation unper perform karo but remember 1 thing jo element phle niklega vo 2nd hoga
            if(x=="+"||x=="-"||x=="*"||x=="/"){
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();
                if(x=="+"){
                    st.push(op1+op2);
                }
                if(x=="-"){
                    st.push(op1-op2);
                }
                if(x=="*"){
                    st.push(op1*op2);
                }
                if(x=="/"){
                    st.push(op1/op2);
                }
            }
            else
            {
                // covert characters into integer and push into stack
                stringstream ss(x);
                int data;
                ss>>data;
                st.push(data);
            }
        }
        return st.top();
    }
};
