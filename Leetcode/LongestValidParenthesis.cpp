#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve() {
  string str;cin>>str;
  // int open = 0;
  // int pair = 0;
  // int maxi = 0;

  // for(int i=0;i<str.size();i++){
  //   if(str[i]=='('){
  //     open++;
  //   }else{
  //     if(open){
  //       pair++;
  //       open--;
  //     }else{
  //       pair = 0;
  //     }
  //   }
  // }

  // cout << 2*maxi << endl;
  int n = str.size();
  int p = 0;

  int start = 0;
  int end = 0; 

  vector<int> dp(n);

  while((p<n)&&(p>=0)){
    if(str[p]=='('){
      int s = dp[dp.size()-1].first + 1;
      int e = dp[dp.size()-1].second;

      if(e >= s + 1){
        
      }
    }else{
      start--;
      p++;
      end++;
    }
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