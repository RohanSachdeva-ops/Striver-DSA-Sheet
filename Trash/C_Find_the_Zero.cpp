#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back

void solve(const ll n){
 
    auto ask = [&](const ll i,const ll j)->bool{
        cout<<"? "<<i+1<<" "<<j+1<<endl;
        ll k;
        cin>>k;
        if(k==-1)
            exit(0);
        return k;
    };
 
    auto prt=[&](const ll k)->void{
        cout<<"! "<<k+1<<endl;
    };
 
    for(ll i=4;i<2*n;i+=2){
        if(ask(i,i+1)){
            prt(i);
            return;
        }
    }
 
    // n-2 queries used and 0,1,2,3 untouched
    if(ask(0,1)){
        prt(0);
        return;
    }
    if(ask(0,2)){
        prt(0);
        return;
    }
 
    if(ask(1,2)){
        prt(1);
        return;
    }
    prt(3);
}

void solve2() {
  int n;cin>>n;

  auto ask = [&](ll i,ll j) -> bool{
    cout << "? " << i+1 << " " << j+1 << endl;
    int k;cin>>k;

    if(k == -1) exit(0);
    else return k;
  };

  auto prt = [&](ll k) -> void{
    cout << "! " << k+1 <<endl;
  };
 
    for(ll i=4;i<2*n;i+=2){
        if(ask(i,i+1)){
            prt(i);
            return;
        }
    }

  if(ask(0,1)) {
    prt(0);
    return;
  }

  if(ask(0,2)){
    prt(0);
    return;
  }

  if(ask(1,2)){
    prt(1);
    return;
  }
prt(3);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
        ll T=100;
        cin>>T;
        while(T--)
        {
            solve2();
            // ll n=2;
            // cin>>n;
            // solve(n);
        }
    return 0;
}

