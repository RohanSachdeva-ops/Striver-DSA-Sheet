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

  int ans = 0;
  if(v[n-1]==1) ans++;
  for(int i=0;i<n;i++){
    if(v[i]!=1) ans += v[i];
  }
  cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}