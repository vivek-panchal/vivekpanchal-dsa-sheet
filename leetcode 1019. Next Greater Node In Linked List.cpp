// ------------------------------------Easy brute force approach TC = O(N^2) && SC=O(1)------------------------------------------------------------
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr=head;
        ListNode* temp=NULL;
        vector<int> ans;
        // jab list me atleast 2 element honge jab hi loop me enter karenge 
        while(curr->next!=NULL){
            temp=curr->next;
            //check if temp ki value curr ki value se choti hai to temp ko aage badha denge 
            while(temp!=NULL && temp->val<=curr->val)
                temp=temp->next;
            if(temp!=NULL && temp->val>curr->val){
                // ager temp ki value badi hai current ki value se to yehi hi to chaiye , jaldi se temp ki value store kar lo ans me 
                ans.push_back(temp->val);
            }
            else
            {
                ans.push_back(0);
            }
            curr=curr->next;
        }
        // last node ke liye always 0 hoga to vo dal rahe hai bcs jab curr last node per hoga && list me 1 element hoga to while loop me ja hi nhi paenge 
        ans.push_back(0);
        return ans;
    }
};

//--------------------------approach 2 TC=O(N) && SC=O(N)-------------------------------------------------------------------

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<int> st;
        ListNode* temp=head;
        
        // list ko vector me dal do
        while(temp!=NULL){
            res.push_back(temp->val);
            temp=temp->next;
        }
        
        // array ko end se traverse karenge 
        for(int i=res.size()-1;i>=0;i--){
            //array ke current elemnt ko store kra lo 
            int val=res[i];
            // ager stack empty nhi hai && stack ke top vali value array ke current element se chotin hai to usse nikal do stack se
            while(!st.empty() && st.top()<=res[i])
                st.pop();
            
            // if stack is empty to res[i] me 0 dal do else st.top() dal do
            res[i]=st.empty()?0:st.top();
            // stack me array ke element ki value push kar do jo phle store karayi thi
            st.push(val);
        }
        
        return res;
    }
};
