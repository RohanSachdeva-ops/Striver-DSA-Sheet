#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
  vector<vector<int>> adj;
  void addEdge(int u, int v, bool direction)
  {
    adj[u].push_back(v);
    if (direction == 0)
      adj[v].push_back(u);
  }

  void printAdjList()
  {
    for (int i = 1; i < adj.size(); i++)
    {
      cout << i << "->";
      for (auto x : adj[i])
      {
        cout << x << " ";
      }
      cout << endl;
    }
  }
};
void buildGraph(graph &g)
{
  int n, m;
  cin >> n >> m;

  g.adj.resize(n + 1);

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v, 0);
  }
}
void dfs2(int node, vector<vector<int>> &adj, vector<int> &vis)
{
  int n = adj.size() - 1;

  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
      dfs2(it, adj, vis);
  }
}
int numberOfProvinces(vector<vector<int>> &adj, vector<int> vis)
{
  int counter = 0;
  for (int i = 1; i < adj.size(); i++)
  {
    if (!vis[i])
    {
      dfs2(i, adj, vis);
      counter++;
    }
  }
  return counter;
}

bool isCycle(int node, vector<vector<int>> &adj, vector<int> &vis)
{
  int n = adj.size() - 1;

  queue<pair<int, int>> q;
  q.push({node, -1});
  vis[node] = 1;
  while (!q.empty())
  {
    auto it = q.front();
    q.pop();
    int curr = it.first, prev = it.second;

    for (auto x : adj[curr])
    {
      if (!vis[x])
      {
        vis[x] = 1;
        q.push({x, curr});
      }
      else
      {
        if (x != prev)
          return true;
      }
    }
  }
  return false;
}
bool isCycleDfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis, bool &flag)
{
  vis[node] = 1;

  for (auto &x : adj[node])
  {
    if (!vis[node])
      isCycleDfs(x, node, adj, vis, flag);
    else
    {
      if (x != parent)
      {
        flag = true;
      }
    }
  }
}

void TopoSortBFS(vector<vector<int>> &adj)
{
  int n = adj.size();
  vector<int> inDegree(n);

  for (int i = 0; i < n; i++)
  {
    for (auto it : adj[i])
    {
      inDegree[it]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < n; i++)
  {
    if (inDegree[i] == 0)
    {
      q.push(i);
    }
  }

  vector<int> topoBFS;
  while (!q.empty())
  {
    auto it = q.front();
    q.pop();
    topoBFS.push_back(it);

    for (auto x : adj[it])
    {
      inDegree[x]--;
      if (inDegree[x] == 0)
      {
        q.push(x);
      }
    }
  }

  for (auto x : topoBFS)
  {
    cout << x << " ";
  }
}

bool isCycleDirectedBFS(vector<vector<int>> &adj)
{
  int n = adj.size() - 1;
  vector<int> inDegree(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    for (auto x : adj[i])
    {
      inDegree[x]++;
    }
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    if (inDegree[i] == 0)
    {
      q.push(i);
    }
  }
  vector<int> ans;
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    ans.push_back(front);

    for (auto x : adj[front])
    {
      inDegree[x]--;
      if (inDegree[x] == 0)
      {
        q.push(x);
      }
    }
  }

  if (ans.size() != n)
    return true;
  else
    return false;
}

void dfsTopo(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
  vis[node] = 1;
  for (auto x : adj[node])
  {
    if (!vis[node])
      dfsTopo(x, adj, vis, st);
  }
  st.push(node);
}

bool dfsCycle(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis)
{
  int n = adj.size() - 1;

  vis[node] = 1;
  pathVis[node] = 1;

  for (auto x : adj[node])
  {
    if (!vis[x])
    {
      if (dfsCycle(x, adj, vis, pathVis) == true)
      {
        return true;
      }
    }
    else if (vis[x] == 1 && pathVis[x] == 1)
      return true;
  }
  pathVis[node] = 0;
  return false;
}
bool isCycleDirected(vector<vector<int>> &adj)
{
  int n = adj.size() - 1;
  vector<int> vis(n + 1, 0);
  vector<int> pathVis(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      if (dfsCycle(i, adj, vis, pathVis) == true)
      {
        return true;
      }
    }
  }
  return false;
}

void topoDFS(vector<vector<int>> &adj)
{
  int n = adj.size() - 1;
  vector<int> vis(n + 1, 0);
  stack<int> st;
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
      dfsTopo(i, adj, vis, st);
  }

  vector<int> topoAns;
  while (!st.empty())
  {
    int top = st.top();
    st.pop();
    topoAns.push_back(top);
  }

  for (auto x : topoAns)
  {
    cout << x << " ";
  }
}

void shortestDist(int src, vector<vector<int>> &adj)
{
  int n = adj.size() - 1;
  vector<int> dist(n, INT_MAX);
  queue<pair<int, int>> q;
  dist[src] = 0;
  q.push({src, 0});

  while (!q.empty())
  {
    auto front = q.front();
    q.pop();
    int node = front.first, d = front.second;

    for (auto x : adj[node])
    {
      if (dist[x] > d + 1)
      {
        dist[x] = d + 1;
        q.push({x, d + 1});
      }
    }
  }

  for (auto x : dist)
    cout << x << " ";
}

void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st)
{
  vis[node] = 1;

  for (auto x : adj[node])
  {
    int node = x.first;
    int weight = x.second;

    if (!vis[node])
      dfs(node, adj, vis, st);
  }
  st.push(node);
}

void ShortestDistanceDirectedGraph()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);

  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
  }

  int src;
  cin >> src;

  stack<int> st;
  vector<int> vis(n, 0);

  // toposort
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
      dfs(i, adj, vis, st);
  }

  vector<int> dist(n, INT_MAX);
  dist[src] = 0;

  while (!st.empty())
  {
    int node = st.top();
    st.pop();

    for (auto it : adj[node])
    {
      int v = it.first;
      int weight = it.second;

      if (dist[node] + weight < dist[v])
      {
        dist[v] = dist[node] + weight;
      }
    }
  }

  for (auto x : dist)
    cout << x << " ";
}

void ShortestDistanceUndirectedGraphByPriorityQueue()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int src;
  cin >> src;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dist(n, INT_MAX);

  dist[src] = 0;
  pq.push({0, src});

  while (!pq.empty())
  {
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (auto x : adj[node])
    {
      int v = x.first;
      int vw = x.second;

      if (dis + vw < dist[v])
      {
        dist[v] = dis + vw;
        pq.push({dist[v], v});
      }
    }
  }

  for (auto x : dist)
    cout << x << " ";
}

void ShortestDistanceUndirectedGraphBySets()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int src;
  cin >> src;

  vector<int> dist(n, INT_MAX);
  set<pair<int, int>> st;

  dist[src] = 0;
  st.insert({0, src});

  while (!st.empty())
  {
    auto it = *(st.begin());
    int dis = it.first;
    int node = it.second;

    st.erase(it);
    for (auto x : adj[node])
    {
      int v = x.first;
      int vw = x.second;

      if (dis + vw < dist[v])
      {
        if (dist[v] != INT_MAX)
        {
          st.erase({dist[v], v});
        }

        dist[v] = dis + vw;
        st.insert({dist[v], v});
      }
    }
  }

  for (auto x : dist)
    cout << x << " ";
}

void ShortestPath()
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int src;
  cin >> src;

  vector<int> dist(n + 1, INT_MAX);
  set<pair<int, int>> st;

  vector<int> parent(n + 1);
  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  dist[src] = 0;
  st.insert({0, src});

  while (!st.empty())
  {
    auto it = *(st.begin());
    int dis = it.first;
    int node = it.second;

    st.erase(it);
    for (auto x : adj[node])
    {
      int node_v = x.first;
      int weight = x.second;

      if (dis + weight < dist[node_v])
      {
        if (dist[node_v] != INT_MAX)
        {
          st.erase({dist[node_v], node_v});
        }

        dist[node_v] = dis + weight;
        st.insert({dist[node_v], node_v});
        parent[node_v] = node;
      }
    }
  }
  int dest;
  cin >> dest;
  int i = dest;
  vector<int> finalans;
  while (true)
  {
    finalans.push_back(i);
    if (dist[i] == 0)
      break;
    i = parent[i];
  }
  for (int i = finalans.size() - 1; i >= 0; i--)
    cout << finalans[i] << " ";
}

void ShortestDistanceInMatrix()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }

  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  int src_row, src_col;
  cin >> src_row >> src_col;

  int dest_row, dest_col;
  cin >> dest_row >> dest_col;

  dist[src_row][src_col] = 0;
  set<pair<int, pair<int, int>>> st;

  st.insert({0, {src_row, src_col}});

  vector<int> delrow = {-1, -1, -1, 0, 0, 1, 1, 1};
  vector<int> delcol = {-1, 0, 1, -1, 1, -1, 0, 1};

  while (!st.empty())
  {
    auto it = *(st.begin());
    int dis = it.first;
    int row = it.second.first;
    int col = it.second.second;

    st.erase(it);

    for (int i = 0; i < 8; i++)
    {
      int newrow = row + delrow[i];
      int newcol = col + delcol[i];

      if (newcol < m && newrow < n && newrow >= 0 && newcol >= 0 && grid[newrow][newcol] == 0 && dist[newrow][newcol] > dis + 1)
      {

        if (dist[newrow][newcol] != INT_MAX)
          st.erase({dist[newrow][newcol], {newrow, newcol}});
        dist[newrow][newcol] = dis + 1;
        st.insert({dist[newrow][newcol], {newrow, newcol}});
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << dist[i][j] + 1 << " ";
    }
    cout << endl;
  }
}
int main()
{
  graph g;
  buildGraph(g);
}
