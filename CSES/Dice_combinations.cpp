#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

ll mod = 1e9+7;

int main() {
    ll n;cin>>n;
    vector<ll> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=6;k++){
            if((i-k)>=0) dp[i] = (dp[i]+dp[i-k])%mod;
        }
    }
    cout << dp[n];
}