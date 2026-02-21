class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // Set containing all prime numbers up to 19
        // (maximum possible set bits in a 32-bit integer is 32, but given constraints only need up to 19)
        unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
      
        // Initialize counter for numbers with prime count of set bits
        int count = 0;
      
        // Iterate through all numbers in the range [left, right]
        for (int num = left; num <= right; ++num) {
            // Count the number of set bits (1s) in binary representation
            int setBitsCount = __builtin_popcount(num);
          
            // Check if the count of set bits is a prime number
            // If yes, increment the counter
            if (primes.count(setBitsCount)) {
                count++;
            }
        }
      
        return count;
    }
};