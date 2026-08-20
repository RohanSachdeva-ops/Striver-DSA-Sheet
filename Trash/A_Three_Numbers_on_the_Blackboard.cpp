#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve() {
  int a,b,c;cin>>a>>b>>c;
  int aa = min({a,b,c});
  int cc = max({a,b,c});
  int bb = (a+b+c) - aa - cc;

    if(aa+bb < cc) {
        cout << bb << endl;
    }else{
        cout << cc-aa << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}