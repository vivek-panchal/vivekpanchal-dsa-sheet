// very important question ************************************* 2 APPROACHES *************************************************************************************

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


//************************************************************* Striver Approach ********************************************************************************

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // ager list empty ho ya k =1 ho to koi change nhi aaega list me 
        if(head==NULL || k==1)
            return head;
        
        // ek dummy node bna li 
        ListNode* dummy= new ListNode(0);
        // dummy ko head se attech kar diya 
        dummy->next=head;
        
        // curr, pre , nexx 3 pointer initialise kare ye reverse me help karenge 
        ListNode* curr= dummy, *nexx=dummy,*pre=dummy;
        int count=0;
        
        // node count kar lo ki list me kitni nodes hai
        while(curr->next!=NULL){
            curr=curr->next;
            count++;
        }
        
        // jab tak list me K se jyada node hai tab tak reverse karna hai
        while(count>=k){
            // curr ko head per and nexx ko head ke next per point kra do
            curr=pre->next;
            nexx=curr->next;
            
            // k nodes reverse kar do 
            for(int i=1; i<k; i++){
                curr->next=nexx->next;
                nexx->next=pre->next;
                pre->next=nexx;
                nexx=curr->next;
            }
            // pre ko current per le jao and count me se k substract kar do bcs k nodes reverse ho gyi hai
            pre=curr;
            count-=k;
        }
        return dummy->next;
    }
};
