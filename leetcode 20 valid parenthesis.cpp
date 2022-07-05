class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
     for(int i=0; i<s.length(); i++) {
         
         char ch = s[i];
         
         //if opening bracket, stack push
         if(ch == '(' || ch == '{' || ch == '['){
             st.push(ch);
         }
         else
         {
              //if close bracket, stacktop check and pop
             //for closing bracket
             if(!st.empty()) {
                 // stack empty nhi hai and current bracket ek closing bracket hai to check kar lo ki uska openin bracket stack ke top per pada hai ya nhi
                  char top = st.top();
                 // ager top pe sahi opening bracket hai to top ko pop kar do
                  if( (ch == ')' && top == '(') || ( ch == '}' && top == '{') || (ch == ']' && top == '[') ) {
                      st.pop();
                  }
                 else
                 {
                     // ager stack ke top per sahi opening bracket nhi hai to invalid brackets hai false return kar do
                     return false;
                 }
             }
             else
             {
                 // stack empty hai to phla bracket hi closing brack hai ye to invalid hai
                 return false;
             } 
         }  
     }
    // stack empty hai and string bhi complete traverse ho gyi to valid hain sab
    if(st.empty())
        return true;
    else
        return false; // stack empty nhi hai but string khatam ho gyi to sab invalid hai
    }
};
