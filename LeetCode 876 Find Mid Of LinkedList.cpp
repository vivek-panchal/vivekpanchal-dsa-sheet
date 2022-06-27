// simple approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* store= head;
        int len=0;
        while(head!=NULL){
            head = head->next;
            len++;
        }
        len=len/2;
        ListNode* temp= store;
        int cnt=0;
        while(cnt<len){
            temp=temp->next;
            cnt++;
        }
        return temp;
    }
};

// 2 pointer approach Slow & fast pointer
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL ||  head->next==NULL)
            return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }
};
