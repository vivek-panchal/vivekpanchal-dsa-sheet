// best approach deficiency , balance , start vali

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //def is ki next step per jane ke liye kitne gas ki kami padi thi
        int def=0;
        int start=0;
        // is station per phochkar kitni balance gas bachi hai
        int bal=0;
        for(int i=0;i<gas.size();i++){
            
            // balance me current patrol ki gas dal do and jitni gas lagegi aagle pump per jane me
            bal+=gas[i]-cost[i];
            // ager balance 0 se jyada hai jabhi next pump per ja payenge 
            if(bal<0){
                def+=bal;
                start=i+1;
                bal=0;
            }
            
        }
        // is pump per aane ke liye kitne gas ki kami padi thi ager usme balance jod de , ager vo 0 se jyada hai to jha se start kiya tha vo solution hai else koi solution nhi hai
        if (def+bal>=0)
            return start;
        else
            return -1;
    }
};

// approach using queue front rear wali approach

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        queue<int> q;
        int rem=0;
        for(int i=0;i<gas.size();i++){
            if(!q.empty()){ 
                rem=rem+gas[i]-cost[i];
                if(rem<0){
                    rem=0;
                    q.pop();
                }
            }          
            if(cost[i]<=gas[i] && (gas[i]!=0 || cost[i]!=0)){   
              if(rem==0){
                    q.push(i); 
                    rem=gas[i]-cost[i];
                } 
            }
        }
        
        if(q.empty()){
            return -1;
        }
        
        int s=gas.size();
        int curr=0;
        
        for(int i=q.front();i<s+q.front();i++){
            int acc=i%s;
            curr=curr+gas[acc]-cost[acc];
            if(curr<0){
                return -1;
            }
            
        }
        
        return q.front();
    }
};
