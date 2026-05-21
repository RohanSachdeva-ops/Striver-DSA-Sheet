#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve() {
  int n;cin>>n;
  vector<vector<int>> vv(n);
  map<int,int> mp;

  for(int i=0;i<n;i++){
    int s;cin>>s;
    vector<int> temp(s);
    for(int j=0;j<s;j++){
        cin >> temp[j];
        mp[temp[j]]++;
    }
    vv[i] = temp;
  }

  bool flag=false;
  for(int i=0;i<n;i++){
    bool found=true;
    for(int j=0;j<(vv[i].size());j++){
        if(mp[vv[i][j]] <= 1) {
            found = false;
        } 
    }

    if(found == true) {
        flag=true;
        break;
    }
  }

  if(flag==true) cout << "Yes\n";
  else cout<<"No\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}