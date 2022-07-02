class Solution {
public:
    // list ka size nikal liya 
    int sizee(ListNode*h){
        int l =0;
        while(h){
            l++;
            h = h->next;
        }
        return l;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n = sizee(head);
        ListNode*p = head;
        ListNode*q = head;
        
        // p ko kth node per point kra diya 
        for(int i=0;i<k-1;i++)p = p->next;
        // q ko end se kth node per point kra diya
        for(int i=0;i<n-k;i++)q = q->next;
        
        // p & q ki value swap kar di
        swap(p->val,q->val);
        
        return head;
    }
};
