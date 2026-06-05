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
  int count=0;
  for(int i=0;i<n-1;i++){
    if(__gcd(v[i],v[i+1]) == abs(v[i+1]-v[i])) count++;
  }
  cout << count << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}