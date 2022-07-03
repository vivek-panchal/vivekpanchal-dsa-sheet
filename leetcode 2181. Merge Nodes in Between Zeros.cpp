class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        
        // ek new list bna lo dummy name se and pointer ptr point kra do
        ListNode* dummy=new ListNode(0);
        ListNode* ptr=dummy;
        // head ke next per temp point kra do bcs head to 0 hai next se sum lenge
        ListNode* temp=head->next;
        int sum=0;
        // jab tak temp Null na ho jaye loop chla lo
        while(temp!=NULL){
            // sum nikal lo 2 zero ke beech ka 
            while(temp->val!=0){
            sum+=temp->val;
            temp=temp->next;
           }
            // dummy node me ptr ke new node lga do with value = sum
            ptr->next=new ListNode(sum);
            // ptr ko aage badha do
            ptr=ptr->next;
            // temp ko aage badha do
            temp=temp->next;
            sum=0;
        }
        // return dunny ka next bcs dummy to dummy node ko point kar rha hai jiski need nhi hai hame
        return dummy->next;
        
    }
};
