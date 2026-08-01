#include <bits/stdc++.h>
using namespace std;
int cuts = 0;

int dfs(int u, int p, vector<vector<int>> &adj, int H)
{
  int max_depth = 0;
  for (auto v : adj[u])
  {
    if (v == p)
      continue;
    int d = dfs(v, u, adj, H);

    if ((d + 1 == H) && (u != 0))
    {
      cuts++;
    }else{
      max_depth = max(max_depth, d+1);
    }
  }
  return max_depth;
}

bool check(int n, int H, vector<vector<int>> &adj, int k)
{
  if (H == 0)
    return n == 1;
  cuts = 0;
  dfs(0, -1, adj, H);
  return cuts <= k;
}

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

  int low = 0, high = n;
  int ans = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (check(n, mid, adj, k))
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  cout << ans << endl;
}