#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve() {
  int n;cin>>n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }

  vector<bool> dp(n+1,false);
  dp[0] = true;
  for(int i=0;i<n;i++){
    int maxi = v[i];
    for(int j=1;j<=maxi;j++){
      if(i+j < n) dp[i+j] = dp[i] | dp[i+j];
    }
  }

  cout << dp[n-1] << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}