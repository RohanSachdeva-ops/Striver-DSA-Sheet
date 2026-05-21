#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define pb push_back
ld best;

bool check(ld T,vector<ld>& x,vector<ld>& t,
ld n){
    ld L=0,R=1e8;
    for(ld i=0;i<n;i++){
        ld l = (ld)x[i] - max(T-t[i],(ld)0);
        ld r = (ld)x[i] + max(T-t[i],(ld)0);

        L = max(L,l);
        R = min(R,r);

        if(L>R) return false;
    }
    best = (L+R)/2;
    return true;
}

void solve() {
  int n;;cin>>n;
  vector<ld> x(n),t(n);
  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<n;i++) cin>>t[i];

  ld low = 0,high = 1e9;
  for(ld i=0;i<=50;i++){
    ld mid = (high+low)/2;
    if(check(mid,x,t,n)){
        high = mid;
    }else{
        low=mid;
    }
  }

  cout << setprecision(16) << best << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}