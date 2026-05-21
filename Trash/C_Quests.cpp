#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve() {
  int n,k;cin>>n>>k;
  int exp = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
      cin >> a[i];
  }

  vector<int> b(n)  ;
  for (int i = 0; i < n; i++) {
      cin >> b[i] ;
  }

  int sum = 0;
  int maxi = 0;
  int ans = 0;
  
  for(int i=0;i<min(n,k);i++){
    sum+=a[i];
    maxi = max(maxi, b[i]);
    ans = max(ans, sum + (k-i-1)*maxi);
  }

  cout<<ans<<endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}