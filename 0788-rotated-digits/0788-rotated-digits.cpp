class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (isGood(i)) {
                count++;
            }
        }
        return count;
    }

private:
    bool isGood(int num) {
        bool hasDiff = false;
        while (num > 0) {
            int digit = num % 10;
            // If any digit is 3, 4, or 7, the whole number is invalid
            if (digit == 3 || digit == 4 || digit == 7) return false;
            
            // If it's 2, 5, 6, or 9, the number will definitely change
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                hasDiff = true;
            }
            num /= 10;
        }
        // Valid only if it contains at least one "changing" digit
        return hasDiff;
    }
};
