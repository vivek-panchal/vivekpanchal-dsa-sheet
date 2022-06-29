// approach 1 using HASHMAP -----------------TC = O(n) && SC =O(N)-----------------------

class Solution {
private:
    void insertAtTail(Node* &head,Node* &tail,int d){
        Node* newNode= new Node(d);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        // step 1: create a clone list
        Node* cloneHead=NULL;
        Node*cloneTail=NULL;
        
        Node* temp=head;
        
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        
        //step:2 Create a map
        
        unordered_map<Node* ,Node*> oldToNewNode;
        
        Node*orignalNode =head;
        Node* cloneNode=cloneHead;
    while(orignalNode!=NULL && cloneNode !=NULL){
        oldToNewNode[orignalNode]=cloneNode;
        orignalNode=orignalNode->next;
        cloneNode=cloneNode->next;
       }
        
        orignalNode =head;
        cloneNode=cloneHead;
         
        while(orignalNode!=NULL){
            cloneNode->random=oldToNewNode[orignalNode->random];
            orignalNode=orignalNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};



// approach 2 without map -----------------TC = O(n) && SC =O(1)-----------------------

class Solution {

private:
void insertAtTail(Node* &head, Node* &tail, int data){

    Node* newNode = new Node(data);
    
    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
public:
Node* copyRandomList(Node* head) {

    // Step1 - create clone list
    
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    
    Node* temp = head;
    
    while(temp!=NULL){
        insertAtTail(cloneHead, cloneTail, temp->val);
        temp = temp->next;
    }
    
    // step2 - Add cloneNodes in between of original list
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    
    while(originalNode!=NULL && cloneNode!=NULL){
        Node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;
        
        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
        
    }
    
    // step3 - copy random pointer
    temp = head;
    
    while(temp!=NULL){
        if(temp->next!=NULL){
            temp->next->random = temp->random ? temp->random->next : temp->random;
        }
        temp = temp->next->next;
    }
    
    // step4 - revert step2
    originalNode = head;
    cloneNode = cloneHead;
    
    while(originalNode!=NULL && cloneNode!=NULL){
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;
        if(originalNode!=NULL){
           cloneNode->next = originalNode->next; 
        }
        cloneNode = cloneNode->next;
    }
    
    // step5 - return ans;
    
    return cloneHead;
}
};
