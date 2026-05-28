#include <bits/stdc++.h>
using namespace std;


int main() {
  string s1;cin>>s1;
  int n=s1.size();
        string s2 ="";
        for(int i=0;i<n;i++) {
          s2 += s1[n-1-i];
        }
        cout<<s2;
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int i=0;i<=n;i++) {
            dp[i][0]=0;
            dp[0][i]=0;
        }

        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;i++){
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // cout << dp[n][n];
    

}