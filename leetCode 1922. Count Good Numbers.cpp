#define mod 1000000007
class Solution {
public:
    long long solve(long long x, long long n){
        //base condition
        if(n==0){
            return 1;
        }
        long long ans = solve(x, n/2);
        if(n&1){
            ans = ans*ans*x;
            ans = ans%mod;
        }
        else{
            ans = ans*ans;
            ans = ans%mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        //long long oddPow =;
        long long res;
        if(n&1){
            // n is even 
            res = (solve(5, n/2+1)*solve(4, n/2))%mod;
        }else{
            // n is odd
            res = (solve(5, n/2)*solve(4, n/2))%mod;
        }
        
        return res;
    }
};
