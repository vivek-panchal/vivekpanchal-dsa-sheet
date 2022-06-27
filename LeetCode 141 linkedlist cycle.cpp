// approach using map
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ( head==NULL){
            return false;  
        }
        //map for mark visited or not
        map<ListNode*,bool> visited;
        ListNode* temp=head;
        
        while(temp!=NULL){
            //cycle is present
            if(visited[temp]==true)
                return true;
            visited[temp]=true;
            temp=temp->next;
        }
        return false;
    }
};

// approach using FLOYD's cycle detection algorithm
// two pointer approach
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ( head==NULL|| head->next==NULL){
            return false;  
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(slow!=NULL && fast!=NULL){
            fast=fast->next;
            if(fast!=NULL)
                fast=fast->next;
            slow=slow->next;
            if(slow==fast)
                return true;     
        }
        return false;
    }
};
