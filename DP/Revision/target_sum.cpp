#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve() {
  
}


int main() {
    int n,target;cin>>n>>target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // long long sum = accumulate(arr.begin(),arr.end(),0LL);

    // if(sum%2) {
    //     cout << -1 << endl;
    //     return 0;
    // }

    // long long target = sum/2LL;

    vector<vector<bool>> dp(n+1,vector<bool> (target+1,0));
    for(int i=0;i<n;i++) dp[i][0]=true;
    if(arr[0]<=target) dp[0][arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int s=0;s<=target;s++){
            int skip = dp[i-1][s];
            int take = false;
            if(s-arr[i]>=0) take = dp[i-1][s-arr[i]];
            dp[i][s] = skip || take;
        }
    }

    cout << dp[n-1][target] << endl;
}