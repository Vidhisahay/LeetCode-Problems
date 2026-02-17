class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
      
        // Iterate through all possible hour values (0-11)
        for (int hour = 0; hour < 12; ++hour) {
            // Iterate through all possible minute values (0-59)
            for (int minute = 0; minute < 60; ++minute) {
                // Count the number of set bits (1s) in binary representation
                // of both hour and minute values
                int hourBits = __builtin_popcount(hour);
                int minuteBits = __builtin_popcount(minute);
              
                // Check if total number of LEDs turned on matches the requirement
                if (hourBits + minuteBits == turnedOn) {
                    // Format the time string
                    // Add leading zero for minutes less than 10
                    string timeString = to_string(hour) + ":" + 
                                       (minute < 10 ? "0" : "") + 
                                       to_string(minute);
                  
                    result.push_back(timeString);
                }
            }
        }
      
        return result;
    }
};
