#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

int lcs(string text1, string text2,int end1,int end2) {
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    if(end1 == n) {
      end1 = n;
      end2 = end2+1;
    }else if(end2 == m){
      end1 = end1+1;
      end2 = m;
    }else {
      end1 = end1+1;
      end2 = end2+1;
    }
    return dp[end1][end2];
}

void solve() {
  string str1,str2;cin>>str1>>str2;
  int n = str1.size();
  int m = str2.size();

  vector<vector<int>> dp(n+1,vector<int> (m+1,0));
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){

      if(i == n){
        dp[n][j] = (j+1)-lcs(str1,str2,n,j);
      }

      if(j == m){
        dp[i][m] = (m) = lcs(str1,str2,i,m);
      }

    }
  }


  cout << dp[n-1][m-1] << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}