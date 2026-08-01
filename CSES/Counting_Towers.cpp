#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;

    vector<int> queries(t);
    int max_n = 0;

    // Read all queries and find maximum n
    for(int i = 0; i < t; i++){
        cin >> queries[i];
        max_n = max(max_n, queries[i]);
    }

    // DP array
    vector<vector<ll>> dp(max_n + 1, vector<ll>(2));

    // Base case
    dp[1][0] = 1;
    dp[1][1] = 1;

    // Precompute
    for(int i = 2; i <= max_n; i++){
        dp[i][0] = (2LL * dp[i-1][0] + dp[i-1][1]) % mod;
        dp[i][1] = (4LL * dp[i-1][1] + dp[i-1][0]) % mod;
    }

    // Answer queries
    for(int n : queries){
        cout << (dp[n][0] + dp[n][1]) % mod << '\n';
    }

    return 0;
}