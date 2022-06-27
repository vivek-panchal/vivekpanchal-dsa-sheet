class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if ( head==NULL|| head->next==NULL){
            return head;  
        }
        
        ListNode* curr=head;
        while(curr->next != NULL){
          if(curr->val==curr->next->val){
             ListNode* next_next=curr->next->next;
              ListNode* NodeToDelete=curr->next;
              delete(NodeToDelete);
              curr->next=next_next;
          }
        else
            // curr data not equal to next data 
            curr=curr->next;
            
        }
        return head;
    }
};
