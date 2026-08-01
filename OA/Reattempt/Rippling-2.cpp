#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the minimum connected sets after adding one interval of length <= k
int getMinConnectedSets(const vector<int>& a, const vector<int>& b, long long k) {
    if (a.empty()) return 0;
    
    int n = a.size();
    
    // Step 1: Pair and sort intervals based on start time
    vector<pair<long long, long long>> intervals(n);
    for (int i = 0; i < n; i++) {
        intervals[i] = {a[i], b[i]};
    }
    sort(intervals.begin(), intervals.end());
    
    // Step 2: Merge overlapping or touching intervals
    vector<pair<long long, long long>> merged;
    merged.push_back(intervals[0]);
    
    for (int i = 1; i < n; i++) {
        // If current interval overlaps/touches the last merged interval, extend it
        if (intervals[i].first <= merged.back().second) {
            merged.back().second = max(merged.back().second, intervals[i].second);
        } else {
            // Otherwise, it's a disjoint interval, add it to the list
            merged.push_back(intervals[i]);
        }
    }
    
    // Step 3: Use Sliding Window to find maximum intervals we can connect
    int m = merged.size();
    int max_reduced = 0;
    int i = 0;
    
    for (int j = 0; j < m; j++) {
        // While the gap from the end of interval 'i' to the start of interval 'j' > k
        // We cannot bridge them, so we shrink the window from the left
        while (merged[j].first - merged[i].second > k) {
            i++;
        }
        
        // If we connect from i to j, we reduce the total components by (j - i)
        max_reduced = max(max_reduced, j - i);
    }
    
    // Final count is the initial merged count minus the maximum components we could bridge
    return m - max_reduced;
}

int main() {
    // Example usage:
    vector<int> a = {1, 5, 10};
    vector<int> b = {2, 6, 11};
    long long k = 4;
    
    // Initial sets: [1, 2], [5, 6], [10, 11] -> 3 connected sets
    // Adding interval of length 4 (e.g., [2, 6]) bridges [1, 2] and [5, 6].
    // Minimum sets expected: 2
    
    cout << "Minimum connected sets: " << getMinConnectedSets(a, b, k) << "\n";
    
    return 0;
}