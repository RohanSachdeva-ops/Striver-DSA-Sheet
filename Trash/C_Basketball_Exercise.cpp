#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back
int main() {
    int n;cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(2,vector<ll> (n+1,0));
    dp[0][0] = a[0];
    dp[1][0] = 0;

    for(int i=1;i<n;i++){
        dp[1][i] = max(dp[1][i-1],-a[i]+dp[0][i-1]);
        dp[0][i] = max(dp[0][i-1], a[i]+dp[1][i-1]);
    }

    cout << max(dp[0][n-1],dp[1][n-1]);

}