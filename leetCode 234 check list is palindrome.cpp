//---------approach 1 list ko array me copy kar diya-------------TC= O(n) && SC= O(n)----------------------------
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // create an array
        vector<int> arr;
        // list ke head per pointer banaya list ko traverse karne ke liye 
        ListNode* temp=head;
        
        // list ka data array me dal do
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        
        // array wala check palindrone ka logic lga diya 
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            if(arr[i]!=arr[j])
                return false;
            i++;
            j--;
        }
        return true;
        
    }
};

//approach 2 find middle && reverse ----------------------TC=O(n) && SC=O(1)------------------------------------
class Solution {
private:
    ListNode* getMid(ListNode* head ) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL && fast-> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL) {
            return true;
        }
        
        //step 1 -> find Middle
        ListNode* middle = getMid(head);
        //cout << "Middle " << middle->data << endl;
        
        //step2 -> reverse List after Middle
        ListNode* temp = middle -> next;
        middle -> next = reverse(temp);
        
        //step3 - Compare both halves
        ListNode* head1 = head;
        ListNode* head2 = middle -> next;
        
        while(head2 != NULL) {
            if(head2->val != head1->val) {
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    
        //step4 - repeat step 2
        temp = middle -> next;
        middle -> next = reverse(temp);
        
        return true;
    }
};
