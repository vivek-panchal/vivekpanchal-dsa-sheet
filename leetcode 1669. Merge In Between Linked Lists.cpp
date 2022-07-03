class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // pls dry run for better understanding
        ListNode* tempA=0;
        ListNode* tempB=0;
        int count=1;
        ListNode* curr=list1;
        
        while(curr!=NULL){
            if(count==a){
                // jha se delete karni hai usse ek phli vali node per tempA lga diya
                tempA=curr;
            }
            if(count==b){
                // jha tak delete karni hai vha tempB lga diya
                tempB=curr->next->next;
            }
            count++;
            curr=curr->next;
        }
        // tempA ko list 2 se connect kar diya
        tempA->next=list2;
        curr=list2;
            while(curr->next!=NULL)
                curr=curr->next;
        // list2 ke end ko list1 me tempB se aage connect kar diya 
        curr->next=tempB;
        return list1;
        
    }
};
