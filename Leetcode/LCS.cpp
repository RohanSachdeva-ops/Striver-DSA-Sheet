#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve() {
  string str1,str2;cin>>str1>>str2;
  int n = str1.size();
  int m = str2.size();
  vector<vector<int>> dp(n+1,vector<int>(m+1,0));
  dp[n][m]=0;

  for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
      if(str1[i] == str2[j]){
        dp[i][j] = 1 + dp[i+1][j+1];
      }else{
        // dp[i][j] = 0;
        dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
      }
    }
  }

  cout << dp[0][0] << endl;
}

void lcs() {
    string text1,text2;cin>>text1>>text2;

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

    cout <<  dp[n-1][m-1];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) lcs();
    
    return 0;
}