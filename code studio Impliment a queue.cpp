class Queue {
    int *arr;
    int size;
    int qfront;
    int rear;
public:
    Queue() {
        // Implement the Constructor
        size=100001;
        arr=new int[size];
        qfront=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront==rear){
            return true;
        }
        else
            return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (rear==size){
            cout<<"queue is full"<<endl;
        }
        else
        {
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue() {
        if(rear==qfront){
            return -1;
        }
        else
        {
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(rear==qfront){
                 rear=0;
                qfront=0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(rear==qfront){
            return -1;
        }
        else
        {
            return arr[qfront];
            
        }
    }
};
