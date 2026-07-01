#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve() {
  int n,m;
  cin >> n >> m;
  
  vector<vector<int>> matrix(n);
  map<int,int> freq;
  for(int i=0;i<n;i++){
    int l;cin>>l;
    matrix[i].resize(l);
    for(int j=0;j<l;j++){
      cin >> matrix[i][j];
      freq[matrix[i][j]]++;
    }
  }

  for(int i=1;i<=m;i++){
    if(freq[i]== 0){
      cout << "NO\n";
      return;
    }
  }
  int count=0;

for(int i=0;i<n;i++){
    bool can_be_removed = true;

    for(int x : matrix[i])
        freq[x]--;

    for(int x : matrix[i]){
        if(freq[x] == 0){
            can_be_removed = false;
            break;
        }
    }

    for(int x : matrix[i])
        freq[x]++;

    if(can_be_removed)
        count++;
}
  if(count >= 2){
    cout << "YES\n";
  }else{
    cout << "NO\n";
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