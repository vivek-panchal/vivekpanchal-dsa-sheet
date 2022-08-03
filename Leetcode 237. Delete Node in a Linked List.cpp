class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp =node->next;
        //store the data of temp as node->data
        //and make node->next=temp->next;
        node->val =temp->val;
        node->next =temp->next;
    
        //delete temp from memory
        temp->next=NULL;
        delete temp;
    }
};
