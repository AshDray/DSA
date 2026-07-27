class Solution {
    private:
    int mod=1000000007;
    long long power(long long base, long long power){
        base%=mod;
        long long res=1;
        while(power){
            if(power%2){
                res=(res*base)%mod;
            }
            base=(base*base)%mod;
            power/=2;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenChoices = power(5, even);
        long long oddChoices = power(4, odd);

        return (evenChoices * oddChoices) % mod;
    }
};