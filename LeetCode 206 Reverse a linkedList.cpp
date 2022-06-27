// iterative solution

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev= NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* forward=curr-> next;
            curr-> next=prev;
            prev=curr;
            curr=forward;
        }
        head=prev;
        return head;
        
    }
};

// love babbar recursive approach

class Solution {
private:
    void reverse(ListNode* &head,ListNode* curr,ListNode* prev){
        // base case 
        if(curr==NULL){
           // head ko previous per point kra do
            head=prev;
            return;
        }
        ListNode* temp=curr->next;
        reverse(head,temp,curr);
        curr->next=prev;
    }
public:
    ListNode* reverseList(ListNode* head) {
      // curr ko head per point kra diya   
        ListNode* curr=head; 
        // previous ko NULL per point kra do
        ListNode* prev=NULL;
        reverse(head,curr,prev);
        
        return head;
    }
};

// recursive solution

class Solution {
public:

ListNode* reverseList(ListNode *head) {
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *prev = head->next;
    head->next = NULL;
    ListNode *next = reverseList(prev);
    prev->next = head;

    return next;
   }
};

