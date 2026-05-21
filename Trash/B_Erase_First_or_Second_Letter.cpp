#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back

void solve() {
  int n;cin>>n;
  string str;cin>>str;

  vector<int> dist(n);
  set<int> st;

  for(int i=0;i<n;i++){
    st.insert(str[i]);
    dist[i] = st.size();
  }
  int ans=0;
  for(int i=0;i<n;i++){
    ans += dist[i]; 
  }

  cout << ans<<endl;
  
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}