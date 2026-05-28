#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

int main() {
    string s1,s2;cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n,vector<int> (m,0));
    //dp[i][j]-->number of distinct subsequences [0....ith] and [0....jth]

    if(s1[0]==s2[0]) dp[0][0]=1;
    else dp[0][0]=0;

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0];

        if (s1[i] == s2[0]) {
            dp[i][0] += 1;
        }
    }

    // first row
    // impossible to form longer string from one character
    for (int j = 1; j < m; j++) {
        dp[0][j] = 0;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n-1][m-1];
}