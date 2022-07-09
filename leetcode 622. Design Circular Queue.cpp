class MyCircularQueue {
    vector<int> q;
    int front = -1;
    int rear = -1;
    int size =0;
public:
    MyCircularQueue(int k) {
        q = vector<int> (k,-1);
        front = -1;
        rear = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        if(isEmpty()){
            front = 0;
        }
        rear = (rear +1)%size;
        q[rear] = value;
        cout<<q[rear]<<" "<<rear<<endl;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        if(front == rear ){
            front = -1;
            rear = -1;
            return true;
        }
        front = (front+1)%size;
        
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return q[front];
    }
    
    int Rear() {   
        if (isEmpty()) {
            return -1;
        }
        return q[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return ((rear+1)%size ==front);
    }
};

// Babbar solution code studio

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //to check whther queue is full
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ) {
            //cout << "Queue is Full";
            return false;
        }
        else if(front == -1) //first element to push
        {
			front = rear = 0;
            
        }
        else if(rear == size-1 && front != 0) {
            rear = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear++;
        }
        //push inside the queue
        arr[rear] = value;
        
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }
};
