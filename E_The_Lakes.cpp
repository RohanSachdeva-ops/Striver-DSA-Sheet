#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void dfs(int row,int col,vector<vector<int>>& mat,vector<vector<int>>& vis,int& temp,int n,int m){
    vis[row][col] = 1;
    vector<int> delrow = {1,0,-1,0};
    vector<int> delcol = {0,1,0,-1};
    
    temp += (mat[row][col]); 
    for(int i=0;i<4;i++){
        int nr = delrow[i] + row;
        int nc = delcol[i] + col;

        if(nr<n && nc<m && nr>=0 && nc>=0 && !vis[nr][nc] && mat[nr][nc]!=0){
            dfs(nr,nc,mat,vis,temp,n,m);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> vis(n,vector<int> (m,0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] && (mat[i][j]!=0)) {
                int temp = 0;
                dfs(i,j,mat,vis,temp,n,m);
                ans = max(ans,temp);
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}