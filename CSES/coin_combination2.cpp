#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back

const long long mod = 1e9 + 7;

int main() {
    ll n,x;cin>>n>>x;
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    } 
    
    // dp[i][s]-->number of distinct ways to sum up to sum 's'
    // from index i to n-1

    vector<vector<ll>> dp(n+1,vector<ll> (x+1,0));

    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }

    for(int i=n-1;i>=0;i--){
        for(int s=1;s<=x;s++){
            ll take = 0;
            if(s-c[i] >= 0) take = dp[i][s-c[i]];
            ll not_take = dp[i+1][s];

            dp[i][s] = (take+not_take)%mod;
        }
    }

    cout << dp[0][x] << endl;
    return 0;
}