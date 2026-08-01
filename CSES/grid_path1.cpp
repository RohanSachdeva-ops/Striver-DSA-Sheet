#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
    int n;cin>>n;
    vector<vector<int>> grid(n,vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;cin>>c;
            if(c == '.') grid[i][j]=1;
            else grid[i][j]=-1;
        }
    }
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));

    if(grid[0][0] == -1) dp[0][0] = 0;
    else dp[0][0] = 1;
    for (int i =1; i < n; i++)
    {
        if(grid[0][i] == -1) dp[0][i] = 0;
        else dp[0][i] = dp[0][i-1];
    }


    for (int i = 1; i < n; i++)
    {
        if(grid[i][0] == -1) dp[i][0]=0;
        else dp[i][0] = dp[i-1][0];
    }
    
    for(int i=1;i<n;i++){
     for(int j=1;j<n;j++){
        int up = 0;
        int left = 0;

        if(i-1 >= 0) up = dp[i-1][j];
        if(j-1>=0) left = dp[i][j-1];
        
        if(grid[i][j] != -1) dp[i][j] = (up + left)%mod;
        else dp[i][j]=0;
     }   
    }

    cout << dp[n-1][n-1] <<endl;
}