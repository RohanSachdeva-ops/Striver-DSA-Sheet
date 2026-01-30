#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> grid(n, vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int> (m,-1));
    for(int j=0;j<m;j++) dp[0][j]=grid[0][j];

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int straight = INT_MAX, LeftDiagonal=INT_MAX, RightDiagonal=INT_MAX;
            straight = grid[i][j] + dp[i-1][j];
            if(j-1 >= 0) LeftDiagonal = grid[i][j] + dp[i-1][j-1];
            if(j+1 < m) RightDiagonal = grid[i][j] + dp[i-1][j+1];
            dp[i][j] = min(straight, min(LeftDiagonal, RightDiagonal));
        }
    }

    cout<<*(min_element(dp[n-1].begin(), dp[n-1].end()));    
}