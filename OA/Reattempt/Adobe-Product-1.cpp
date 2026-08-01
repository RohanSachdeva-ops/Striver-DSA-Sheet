// number of subarray having specified max and min
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countSubarrays(vector<int>& nums, int max_ele, int min_ele) {
    // Edge case: impossible requirement
    if (min_ele > max_ele) {
        return 0;
    }
    
    long long ans = 0;
    
    // Initialize trackers to -1
    int last_min = -1;
    int last_max = -1;
    int last_invalid = -1;
    
    for (int R = 0; R < nums.size(); R++) {
        // 1. Check for invalid elements (barriers)
        if (nums[R] < min_ele || nums[R] > max_ele) {
            last_invalid = R;
        }
        
        // 2. Update the most recent min and max positions
        if (nums[R] == min_ele) {
            last_min = R;
        }
        if (nums[R] == max_ele) {
            last_max = R;
        }
        
        // 3. Calculate valid subarrays ending at R
        int valid_starts = min(last_min, last_max) - last_invalid;
        
        if (valid_starts > 0) {
            ans += valid_starts;
        }
    }
    
    return ans;
}