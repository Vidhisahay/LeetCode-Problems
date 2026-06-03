class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                          vector<int>& waterStartTime, vector<int>& waterDuration) {
        // Calculate the minimum time when starting with land activities first, then water
        int landFirstTime = calculateMinimumTime(landStartTime, landDuration,
                                                 waterStartTime, waterDuration);

        // Calculate the minimum time when starting with water activities first, then land
        int waterFirstTime = calculateMinimumTime(waterStartTime, waterDuration,
                                                  landStartTime, landDuration);

        // Return the minimum of both approaches
        return min(landFirstTime, waterFirstTime);
    }

private:
    int calculateMinimumTime(vector<int>& firstStartTimes, vector<int>& firstDurations,
                            vector<int>& secondStartTimes, vector<int>& secondDurations) {
        // Find the earliest completion time among all first activities
        int earliestFirstCompletion = INT_MAX;
        for (int i = 0; i < firstStartTimes.size(); ++i) {
            int completionTime = firstStartTimes[i] + firstDurations[i];
            earliestFirstCompletion = min(earliestFirstCompletion, completionTime);
        }

        // Find the minimum total time by trying each second activity
        int minimumTotalTime = INT_MAX;
        for (int i = 0; i < secondStartTimes.size(); ++i) {
            // Second activity can only start after both:
            // 1. First activity is completed (earliestFirstCompletion)
            // 2. Second activity's start time is reached (secondStartTimes[i])
            int secondActivityStart = max(earliestFirstCompletion, secondStartTimes[i]);
            int totalTime = secondActivityStart + secondDurations[i];
            minimumTotalTime = min(minimumTotalTime, totalTime);
        }

        return minimumTotalTime;
    }
};
