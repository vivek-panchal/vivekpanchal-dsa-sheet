class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum=0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
        k=k%sum;
        int index = 0;
        while(chalk[index]<=k)
        {
            k = k-chalk[index];
            index++;
            index = index%chalk.size();
        }
        return index;
        
    }
};
