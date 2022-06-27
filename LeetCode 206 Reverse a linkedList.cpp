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

