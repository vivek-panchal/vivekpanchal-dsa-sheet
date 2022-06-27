class Solution {
private:
    ListNode *startingNode(ListNode* head,ListNode *slow,ListNode *fast){
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        
        return slow;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if ( head==NULL|| head->next==NULL){
            return NULL;  
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(slow!=NULL && fast!=NULL){
            fast=fast->next;
            if(fast!=NULL)
                fast=fast->next;
            slow=slow->next;
            if(slow==fast){
                //cycle is present find starting point
                return startingNode(head,slow,fast);
            }          
        }
        return NULL;
    }
};
