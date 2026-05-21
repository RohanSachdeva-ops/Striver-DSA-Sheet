#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back

int ask(ll u,ll v){
    cout << "? "<< u+1 << " " << v+1 << endl;
    int k;cin>>k;
    if(k == -1) exit(0);
    else return k;
}

void print(ll r,ll c){
    cout << "! "<< r+1 << " " << c+1 << endl;
    return;
}

void solve() {
  int n,m;cin>>n>>m;

  int d1 = ask(0,0);
  if(d1 == 0){
     print(0,0);
     return;
  }
  bool col_greater = false;
  int d2=-1;
  if(d1 < n){
     d2 = ask(d1,0);
    if(d2 == 0){
        print(d1,0);
        return;
    }
    if(d2 == d1)  col_greater=true;
  }
  
  
  else{
    col_greater = true;
  }

  if(col_greater){
    int d3 = ask(0,d1);
    print(d3,d1);
  }else{
    int d3 = d2;
    print(d1,d3);
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