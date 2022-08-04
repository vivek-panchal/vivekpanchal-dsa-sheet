class cmp
{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min heap banaya node type ka 
       priority_queue<ListNode* ,vector<ListNode*>,cmp> q;
        // ek new  node banayi dummy 
        ListNode* dummy= new ListNode(-1);
        // dummy per hi tail poiint kra diya 
        ListNode* tail=dummy;
        
        // put pointer of first node of all K list into min heap
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
                q.push(lists[i]);
        }
        
        while(q.size()){
            // jo pointer q ke top per hai use temp me store kar liya bcs baad me iska next element bhi to queue me dalna hai
            ListNode* temp=q.top();
            // temp ko tal ke aage lga do and tail ko aage badha do 
            tail->next=temp;
            tail=temp;
            // q ke top ko pop kar diya and usi list ki temp ke aage vali node dal di
            q.pop();
            if(temp->next!=NULL)
                q.push(temp->next);
        }
        return dummy->next;
    }
};
