// very important question

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // base case 
        if(head==NULL){
            return NULL;
        }
        
        //to not reverse the last group which is less than k
        // check count of remaining element is more than K 
        ListNode* temp=head;
        for(int i=0;i<k;i++)
        {
            if(temp==NULL)
            return head;
            temp=temp->next;
        }
        
        // step 1 : reverse first K node
        ListNode* next= NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;
        int cnt=0;
        while(curr!=NULL && cnt<k){
            next= curr-> next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        
        // step 2 : recursive call
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
        
        // return head of reversed linked list : if confused why return prev pls dry run
        return prev;
    }
};
