#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

bool check(ll mid ,vector<ll>& v,ll h){
    vector<ll> temp(v.begin(), v.begin() + mid);
    sort(temp.begin(), temp.end());

    ll sum = 0;
    for(int i = mid - 1; i >= 0; i -= 2){
        sum += temp[i];
    }

    return sum <= h;
}

void solve() {
  ll n,h;cin>>n>>h;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }

  ll low = 1,high = n,ans=0;
  while(low<=high){
    ll mid = low+(high-low)/2;
    if(check(mid,v,h)) low = mid+1,ans = mid;
    else high=mid-1;
  }

  cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}