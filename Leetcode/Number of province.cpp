#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int node, vector<vector<int>> &adj, vector<int> &vis)
{

  vector<int> ans;

  vis[node] = 1;
  queue<int> q;
  q.push(node);
  while (!q.empty())
  {
    int it = q.front();
    q.pop();
    ans.push_back(it);
    vis[it] = 1;
    for (auto x : adj[it])
    {
      if (!vis[x])
      {
        vis[x] = 1;
        q.push(x);
      }
    }
  }
  return ans;
}
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
{
  vis[node] = 1;
  for (auto x : adj[node])
  {
    if (!vis[x])
    {
      dfs(x, adj, vis);
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n,vector<int> (m,0));
  queue<pair<int,int>> q;
  int fresh = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>grid[i][j];
      if(grid[i][j] == 2){
        q.push({i,j});
      }else if(grid[i][j] == 1){
        fresh++;
      }
    }
  }
  int count=0;
  while(!q.empty() && fresh>0){
    int size = q.size();
    while (size--)
    {
      auto it = q.front();q.pop();
      int r = it.first;
      int c = it.second;
      vector<int> delrow = {1,-1,0,0};
      vector<int> delcol = {0,0,-1,1};
      
      for(int i=0;i<4;i++){
        int nr = r + delrow[i];
        int nc = c + delcol[i];

        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
          q.push({nr,nc});
          // grid[nr][nc] = 2;
          fresh--;
        }
      }
    }
    count++;
  }
  if(fresh) cout << -1<<endl;
  else cout << count << endl;
}