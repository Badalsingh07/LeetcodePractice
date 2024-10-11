class Solution {
public:
    typedef pair<int, int> p;

    int smallestChair(vector<vector<int>>& times, int t) {
        int n = times.size();
        int targettime = times[t][0]; // Target guest's arrival time

        // Augment each guest's time with their original index and sort by arrival time
        vector<pair<int, pair<int, int>>> indexedTimes;
        for (int i = 0; i < n; ++i) {
            indexedTimes.push_back({i, {times[i][0], times[i][1]}});
        }
        sort(begin(indexedTimes), end(indexedTimes), [](auto &a, auto &b) {
            return a.second.first < b.second.first;
        });

        int chair = 0;

        // Min-heap for occupied chairs (comparing by departure time)
        priority_queue<p, vector<p>, greater<p>> occupied;
        // Min-heap for free chairs
        priority_queue<int, vector<int>, greater<int>> free;

        for (int i = 0; i < n; i++) {
            int arrival = indexedTimes[i].second.first;
            int departer = indexedTimes[i].second.second;
            int originalIndex = indexedTimes[i].first; // The original guest index

            // Free the chairs for guests who have left
            while (!occupied.empty() && occupied.top().first <= arrival) {
                free.push(occupied.top().second);
                occupied.pop();
            }

            // Assign a chair
            if (free.empty()) {
                occupied.push({departer, chair});
                if (originalIndex == t) return chair;
                chair++;
            } else {
                int minchair = free.top();
                free.pop();
                if (originalIndex == t) return minchair;
                occupied.push({departer, minchair});
            }
        }

        return -1; // This line should never be reached if input is valid
    }
};
