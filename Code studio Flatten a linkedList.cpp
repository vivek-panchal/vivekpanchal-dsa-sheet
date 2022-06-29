/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* sortedMerge(Node*a , Node* b){
    //base case
    if(a==NULL){
        return b;
    }
    else if (b==NULL){
        return a;
    }
    Node* result = NULL;
    //pick either a or b and apply recursion
    if(a->data <= b->data){
        result=a;
        result -> child = sortedMerge(a->child , b);
    }
    else{
        result = b;
        result -> child = sortedMerge( a, b ->child);
    }
    return result;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head==NULL || head -> next == NULL){
        return head;
    }
    Node* down = head;
    Node*right = flattenLinkedList(head -> next);
    down -> next =NULL;
    Node*ans = sortedMerge(down,right);
    
    return ans;
}
