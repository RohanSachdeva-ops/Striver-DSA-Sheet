#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve() {
  int n;cin>>n;
  vector<int> temp;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];

  for(int i=0;i<n;i++){
    if(v[i]<(i+1)) temp.push_back(i);
  }

  ll ans=0;
  for(int i=0;i<temp.size();i++){
    ans += (long long) (lower_bound(temp.begin(),temp.end(),v[temp[i]])-temp.begin());
    cout<<ans<<" ";
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