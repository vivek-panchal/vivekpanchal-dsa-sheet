class Solution {
public:
    vector<int> solve(ListNode* head ,vector<int>& ans){
        ListNode* prev=head;
        ListNode* curr=head->next;
        int criticalIndex=0;
        int CurrCriticalIndex=0;
        int index=2;
        
        while(curr->next!=NULL){
            if((curr->val>prev->val && curr->val>curr->next->val) ||
               (curr->val<prev->val && curr->val<curr->next->val))
            {
                if(criticalIndex==0){
                    criticalIndex=index;
                    CurrCriticalIndex=index;
                }
                else{
                    if(ans[1]==-1){
                        ans={INT_MAX,0};
                    }
                    ans[1]=index-criticalIndex;
                    ans[0]=min(index-CurrCriticalIndex,ans[0]); 
                    CurrCriticalIndex=index;
                }
            }
            
            index++;
            curr=curr->next;
            prev=prev->next;
        }
        
        return ans;
    }
    
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans={-1,-1};
        
        return head->next->next==NULL?ans:solve(head,ans);
    }
};
