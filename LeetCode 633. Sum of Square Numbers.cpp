class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int start=0;
        long long int end=sqrt(c);
        while(end>=start){
            long long int temp= start*start + end*end;
            if(temp>c)
                end--;
            if(c>temp)
                start++;
            if(c==temp)
                return true;
        }
        return false;
    }
};
