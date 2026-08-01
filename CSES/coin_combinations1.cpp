#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7.;
int main() {
    long long n,x;cin>>n>>x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    vector<long long> dp(x+1);
    dp[0]=1;
    for(int s=0;s<=x;s++){
        for(int i=0;i<n;i++){
            if(c[i] > s) break;
            if(s-c[i] >= 0) dp[s] = (dp[s]+dp[s-c[i]])%mod;
        }
    }

    cout << dp[x] << endl;
}