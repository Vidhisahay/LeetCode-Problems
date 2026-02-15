class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int indexA = a.size() - 1;  // Start from the rightmost digit of string a
        int indexB = b.size() - 1;  // Start from the rightmost digit of string b
        int carry = 0;              // Initialize carry to 0
      
        // Continue while there are digits to process or carry remains
        while (indexA >= 0 || indexB >= 0 || carry > 0) {
            // Add current digit from string a (if exists), otherwise add 0
            if (indexA >= 0) {
                carry += a[indexA] - '0';  // Convert char to int and add to carry
                indexA--;
            }
          
            // Add current digit from string b (if exists), otherwise add 0
            if (indexB >= 0) {
                carry += b[indexB] - '0';  // Convert char to int and add to carry
                indexB--;
            }
          
            // Append the current bit (carry % 2) to the result
            result.push_back((carry % 2) + '0');  // Convert int to char and append
          
            // Update carry for next iteration (carry / 2)
            carry /= 2;
        }
      
        // Reverse the result since we built it backwards
        reverse(result.begin(), result.end());
      
        return result;
    }
};