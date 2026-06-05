#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

bool intersect(ll l1, ll r1, ll l2, ll r2){
    return max(l1, l2) <= min(r1, r2);
}

pair<ll,ll> intersectingSegment(ll l1, ll r1, ll l2, ll r2){
    ll L = max(l1,l2);
    ll R = min(r1,r2);

    return {L,R};
}

bool check(ll k , vector<pair<ll,ll>>& segments){
    ll l=-k, r=k;
    for(int i=0;i<segments.size();i++){
        ll x = segments[i].first,y=segments[i].second;
        if(intersect(l,r,x,y)){
            pair<ll,ll> temp = intersectingSegment(l,r,x,y);
            l = temp.first,r = temp.second;
            l = l-k;
            r = r+k;
        }else{
            return false;
        }
    }
    return true;
}

void solve() {
  ll n;cin>>n;
  vector<pair<ll,ll>> segments(n);
  for(int i=0;i<n;i++){
    ll x,y;cin>>x>>y;
    segments[i] = {x,y};
  }

  ll low = 0,high = 1e9;
  ll ans = -1;
  while(low <= high){
    ll mid = low + (high-low)/2;
    if(check(mid,segments)){
        ans = mid;
        high = mid-1;
    }else{
        low = mid+1;
    }
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