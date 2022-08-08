class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> result(n, 0);
        for(int i = 0; i<n; i++){
            // stack me ager koi index pda hai to check karo uss index per jo elemnet hai vo current element se bda hai ya chota , if stack vale index per chota element pda hai to jo stack vala index hai and jo current index ka difference  hai usko result me dal do and stack me se pop kar do 
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                result[st.top()] = i-st.top();
                st.pop();
            }
            // current index ko hamesa stack me dalte chalna hai 
            st.push(i);
        }
        return result;
    }
};
