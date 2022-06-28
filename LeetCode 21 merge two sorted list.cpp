class Solution {
private:
 ListNode*solve(ListNode* first, ListNode* second) {
    // if only 1 element in list 1
     if(first->next==NULL){
         first->next=second;
         return first;
     }
    
     // create some pointers on both lists 
    ListNode* curr1 = first;
    ListNode* next1 = curr1 -> next;
    
    ListNode* curr2 = second;
    ListNode* next2 = curr2 -> next;
    
    while(next1 != NULL && curr2 != NULL) {
        
        if( (curr2 -> val >= curr1 -> val ) 
           && ( curr2 -> val <= next1 -> val)) {
            
            
            // add node in beetwen the nodes of first list
            curr1 -> next = curr2;
            next2=curr2->next;
            curr2 -> next = next1;
            //update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            // curr1 & next1 ko aage badha diya 
            curr1=curr1->next;
            next1=next1->next;
            // check kar lo kya pta list 1 khatam ho gyi ho 
            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
        
        
    }
     return first; 
}

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // if list 1 is empty 
        if(list1 == NULL)
        return list2;
        
        
    // if list2 is empty
       if(list2 == NULL)
        return list1;
    // check whick list is start with greater element jo bhi bade se start ho rhi hai usse first bol do
       if(list1 -> val <= list2 -> val ){
        return solve(list1, list2);
      }
      else
      {
        return solve(list2, list1);
      } 
    }
};
