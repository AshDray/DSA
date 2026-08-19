class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // Track odd numbers only (size n/2 handles odd indices)
        vector<bool> isPrime(n / 2, true);
        
        int count = 1; // Start with 1 to account for prime number 2

        // Loop through odd numbers starting from 3
        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i / 2]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j / 2] = false;
                }
            }
        }

        // Count remaining odd primes
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i / 2]) {
                count++;
            }
        }

        return count;
    }
};