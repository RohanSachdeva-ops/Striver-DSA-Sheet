//minimmum operation to convert all element to q[i]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();
    
    // Step 1: Sort the array
    sort(nums.begin(), nums.end());
    
    // Step 2: Build the prefix sum array
    // prefix[k] will store the sum of the first k elements
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    
    vector<long long> ans;
    ans.reserve(queries.size());
    
    // Step 3: Process each query
    for (long long x : queries) {
        // Find the index of the first element >= x
        auto it = lower_bound(nums.begin(), nums.end(), x);
        long long i = distance(nums.begin(), it);
        
        // Calculate operations for elements < x
        // We need 'i' copies of 'x', minus the actual sum of those elements
        long long left_ops = (i * x) - prefix[i];
        
        // Calculate operations for elements >= x
        // We take the sum of the remaining elements, minus (n - i) copies of 'x'
        long long right_ops = (prefix[n] - prefix[i]) - ((n - i) * x);
        
        // Total operations for this query
        ans.push_back(left_ops + right_ops);
    }
    
    return ans;
}