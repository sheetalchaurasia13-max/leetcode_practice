class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Pigeonhole Principle: 1440 total minutes in a day
        if (timePoints.size() > 1440) return 0;

        vector<bool> seen(1440, false);

        for (const string& time : timePoints) {
            int h = (time[0] - '0') * 10 + (time[1] - '0');
            int m = (time[3] - '0') * 10 + (time[4] - '0');
            int totalMin = h * 60 + m;

            if (seen[totalMin]) return 0; // Duplicate time point found
            seen[totalMin] = true;
        }

        int prev = -1;
        int first = -1;
        int last = -1;
        int minDiff = INT_MAX;

        for (int i = 0; i < 1440; ++i) {
            if (seen[i]) {
                if (first == -1) first = i;
                if (prev != -1) {
                    minDiff = min(minDiff, i - prev);
                }
                prev = i;
                last = i;
            }
        }

        // Check circular wrap-around difference between the last and first time point
        minDiff = min(minDiff, 1440 + first - last);

        return minDiff;
    }
};