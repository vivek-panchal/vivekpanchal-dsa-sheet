class Info{
    public:
    int data;
    int row;
    int col;
    Info(int d, int r, int c){
        this -> data = d;
        this -> row = r;
        this -> col = c;
    }
};
class Cmp{
    public:
    bool operator()(Info* a, Info* b){
        return a -> data > b -> data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        priority_queue<Info*, vector<Info*>, Cmp> minHeap;
        // cfirst element of k list push into heap or priority queue
        for(int i = 0 ; i < nums.size(); i++){
            int element = nums[i][0];
            Info* info = new Info(element, i, 0);
            maxi = max(maxi, element);
            mini = max(mini, element);
            minHeap.push(info);
        }
        // find range using mini and maxi
        int start = maxi;
        int end = mini;
        while(!minHeap.empty()){
            //  heap ke top ko store kar lo 
            Info* temp = minHeap.top();
            // heap ke top ko pop kar do
            minHeap.pop();
            // mini ko update karo , heap ke top per jo element tha vhi minimum tha 
            mini = temp -> data;
            //ager new mini & maxi vali range start & end vali rangev se choti hai to start and end ko update kar do
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
            // heap me se jo elemnet nikala tha uske aage vala element ager hai to vo dal do heap me
            // else break kar ke bhar aa jao bcs abb jo range aayegi vo confirm nhi hai ki sari list ke elemrnt usme ho
            if(temp -> col + 1 < nums[temp -> row].size()){
                maxi = max(maxi, nums[temp -> row][temp -> col + 1]);
                Info* toPush = new Info(nums[temp -> row][temp -> col + 1], temp -> row, temp -> col + 1);
                minHeap.push(toPush);
            }else
            {
                break;
            }
        }
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};
