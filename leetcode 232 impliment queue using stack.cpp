// S1 is input and S2 is output as striver aproach

class MyQueue {
    stack<int> s1,s2;
    int front=-1;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.size()==0){
            // top element store kar rahe hai
            front=x;
        }
        s1.push(x);
    }
    
    int pop() {
        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s1.top();
        s1.pop();
        if(s2.size()>0)
        front=s2.top();
        while(s2.size()>0){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return s1.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
