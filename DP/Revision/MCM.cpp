#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> dp(n,vector<int> (n,0));
    
    for(int i=0;i<n;i++) dp[i][i]=0;
    
    for(int i=n-1;i>=1;i--){
      for(int j=i+1;j<n;j++){
        int mini = 1e9;
        for(int k=i;k<j;k++){
          int steps = v[k]*v[i-1]*v[j] + dp[i][k] + dp[k+1][j];
          mini = min(mini,steps);
        }
        dp[i][j]=mini;
      }
    }

    cout << dp[1][n-1] << endl;
}