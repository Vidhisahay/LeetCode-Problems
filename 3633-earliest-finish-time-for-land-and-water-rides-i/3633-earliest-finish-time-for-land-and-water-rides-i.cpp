class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                          vector<int>& waterStartTime, vector<int>& waterDuration) {
        // Calculate earliest finish time for land-first then water route
        int landFirstFinishTime = calculateEarliestFinish(landStartTime, landDuration,
                                                          waterStartTime, waterDuration);

        // Calculate earliest finish time for water-first then land route
        int waterFirstFinishTime = calculateEarliestFinish(waterStartTime, waterDuration,
                                                           landStartTime, landDuration);

        // Return the minimum of both possible routes
        return min(landFirstFinishTime, waterFirstFinishTime);
    }

private:
    int calculateEarliestFinish(vector<int>& firstSegmentStart, vector<int>& firstSegmentDuration,
                                vector<int>& secondSegmentStart, vector<int>& secondSegmentDuration) {
        // Find the earliest possible completion time for the first segment
        int earliestFirstSegmentEnd = INT_MAX;
        for (int i = 0; i < firstSegmentStart.size(); ++i) {
            int currentEndTime = firstSegmentStart[i] + firstSegmentDuration[i];
            earliestFirstSegmentEnd = min(earliestFirstSegmentEnd, currentEndTime);
        }

        // Find the overall earliest finish time considering all second segment options
        int overallEarliestFinish = INT_MAX;
        for (int i = 0; i < secondSegmentStart.size(); ++i) {
            // Second segment starts at max of (first segment end, second segment start time)
            int actualSecondStart = max(earliestFirstSegmentEnd, secondSegmentStart[i]);
            int totalFinishTime = actualSecondStart + secondSegmentDuration[i];
            overallEarliestFinish = min(overallEarliestFinish, totalFinishTime);
        }

        return overallEarliestFinish;
    }
};
