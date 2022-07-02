class Solution {
public:
    // list ka size nikal liya 
    int size(ListNode*h){
        int l =0;
        while(h){
            l++;
            h = h->next;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int length=size(head);
        
        //edge cases 
        if(head==NULL || head->next==NULL || k==0|| k%length==0)
            return head;
        
        // k length se bda ho sakta hai isiliye % kiya
        k=k%length;
        
        ListNode*prev=NULL;
        ListNode*curr=head;
        
        int t=length-k;
        
        while(t--){
            prev=curr;
            curr=curr->next; 
        }
        
        prev->next=NULL;
        
        //tail banao and use head per join kar do
        ListNode* tail=curr;
        while (tail->next !=NULL){
            tail=tail->next;
        }
        tail->next=head;
        
        return curr;
    }
};
