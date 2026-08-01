#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // dp[i][x] = number of ways to fill array up to index i with a[i] = x
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    // 🔹 Base case
    if (v[0] == 0) {
        for (int x = 1; x <= m; x++) {
            dp[0][x] = 1;
        }
    } else {
        dp[0][v[0]] = 1;
    }

    // 🔹 DP transitions
    for (int i = 1; i < n; i++) {
        for (int x = 1; x <= m; x++) {

            if (v[i] != 0 && v[i] != x) {
                dp[i][x] = 0;
                continue;
            }

            dp[i][x] = dp[i-1][x];

            if (x > 1)
                dp[i][x] = (dp[i][x] + dp[i-1][x-1]) % mod;

            if (x < m)
                dp[i][x] = (dp[i][x] + dp[i-1][x+1]) % mod;

            dp[i][x] %= mod;
        }
    }

    // 🔹 Final answer
    int ans = 0;
    for (int x = 1; x <= m; x++) {
        ans = (ans + dp[n-1][x]) % mod;
    }

    cout << ans << endl;
}