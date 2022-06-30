/// ager samjh na aaye to striver ki video dekhni hai

class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial=1;
        vector<int> numbers;
        for(int i=1; i<n;i++){
            // compute factorial of N-1 numbers
            factorial=factorial*i;
            // store N-1 numbers into vectors
            numbers.push_back(i);
        }
        // insert last number into vector
        numbers.push_back(n);
        string ans="";
        // k=k-1 bcs we use 0 base indexing
        k=k-1;
        while(true){
            // answer me vo number dal do jo vector me K/factorial index per hai bcs vo number hi permutation me first place per hoga 
            ans=ans + to_string(numbers[k/factorial]);
            // jo number ANS ME DAL DIYA USSE REMOVE KAR DO BCS USSE ABB HAM USE NHI KAR SAKTE 
            numbers.erase(numbers.begin()+k/factorial);
            // check kar lo ki array empty na ho gya ho ager array empty ho gya hai to hame apna naswer mil gya hai , ruk jao and ans return kar do
            if(numbers.size()==0){
                break;
            }
            // k ko update kar do bcs next step ke liye 
            k=k%factorial;
            factorial=factorial/numbers.size();
        }
        return ans;
    }
};
