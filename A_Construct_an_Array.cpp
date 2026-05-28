#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve() {
  int n;cin>>n;
  set<int> s;
  vector<bool> removed(2*n + 1,false);

  int prev=0,count=1;
  for(int i=1;i<=2*n;i++){
    if((count <= n) && !removed[i]){
        cout << i << " ";
        count++;
        removed[i]=true;
        if(prev+i <= 2*n)removed[prev+i] =true;
        prev=i;
    } 
  }
  cout << endl;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}