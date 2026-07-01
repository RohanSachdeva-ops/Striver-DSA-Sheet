#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using p = pair<int, int>;
using pp = pair<int, pair<int, int>>;
#define endl '\n'
#define pb push_back

void bfs()
{
    int n, m;
    cin >> n >> m;
    int node;
    cin >> node;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    vector<int> bfs;
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        bfs.push_back(it);
        vis[it] = 1;

        for (auto x : adj[it])
        {
            if (vis[x] != 1)
            {
                vis[x] = 1;
                q.push(x);
            }
        }
    }

    for (auto x : bfs)
        cout << x << " ";
}

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &dfsV)
{
    vis[node] = 1;
    dfsV.push_back(node);
    for (auto x : adj[node])
    {
        if (vis[x] != 1)
        {
            dfs(x, vis, adj, dfsV);
        }
    }
}

void dfsHelper()
{
    int n, m, node;
    cin >> n >> m >> node;
    vector<int> vis(n + 1), dfsV;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(node, vis, adj, dfsV);
    for (auto x : dfsV)
        cout << x << " ";
}
void dfs2()
{
    int n, m, node;
    cin >> n >> m >> node;
    vector<int> vis(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    stack<int> st;
    st.push(node);
    vector<int> dfsv;
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (vis[it] == 1)
            continue;
        vis[it] = 1;
        dfsv.pb(it);
        for (auto x : adj[it])
        {
            if (!vis[x])
            {
                st.push(x);
            }
        }
    }

    for (auto x : dfsv)
        cout << x << " ";
}

bool isCycleByBFS(int start, vector<vector<int>> &adj, vector<int> &vis)
{
    int n = adj.size() - 1;
    queue<pair<int, int>> q;
    q.push({start, -1});
    vis[start] = 1;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int node = it.first;
        int parent = it.second;

        for (auto x : adj[node])
        {
            if (!vis[x])
                q.push({x, node}), vis[x] = 1;
            else if (x != parent)
                return true;
        }
    }
    return false;
}
void isCycleByBFS_helper()
{
    int n, m, node;
    cin >> n >> m >> node;
    vector<int> vis(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (isCycleByBFS(i, adj, vis))
                cout << 1 << endl;
        }
    }
    cout << 0 << endl;
}

bool isCycleByDFS(int node, int parent, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;
    for (auto x : adj[node])
    {
        if (!vis[x])
            isCycleByDFS(x, node, adj, vis);
        else if (x != parent)
            return true;
    }
    return false;
}
void isCycleByDFS_helper()
{
    int n, m, node;
    cin >> n >> m >> node;
    vector<int> vis(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (isCycleByDFS(i, -1, adj, vis))
            {
                cout << 1 << endl;
                return;
            };
        }
    }
    cout << 0 << endl;
}

bool isCycleDirectedDFS(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis)
{
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto x : adj[node])
    {
        if (!vis[x])
        {
            if (isCycleDirectedDFS(x, adj, vis, pathVis) == true)
                return true;
        }

        else if (pathVis[x] == 1)
            return true;
    }
    pathVis[node] = 0;
    return false;
}
bool isCycleDirectedDFS_helper()
{
    int n, m;
    cin >> n >> m;
    vector<int> vis(n + 1);
    vector<int> pathVis(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (isCycleDirectedDFS(i, adj, vis, pathVis))
                return true;
        }
    }
    return false;
}

void ShortestDistanceUndirectedUnitWeight()
{
    int n, m, src;
    cin >> n >> m >> src;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        for (auto x : adj[node])
        {
            if (dist[node] + 1 < dist[x])
            {
                dist[x] = dist[node] + 1;
                q.push(x);
            }
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            ans[i] = -1;
        else
            ans[i] = dist[i];
    }
}

// No cycles allowed otherwise Djikstra's Algorithm
void dfsTopo(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& topo) {
    vis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfsTopo(it, adj, vis, topo);
        }
    }

    // push after visiting neighbors
    topo.push_back(node);
}


void topoSortDFS() {
    int n,m;cin>>n>>m;
    vector<int> vis(n, 0);
    vector<int> topo;

    vector<vector<int>> adj(n);

    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfsTopo(i, adj, vis, topo);
        }
    }

    reverse(topo.begin(), topo.end());

    for(auto x:topo) cout << x << " ";
    cout << endl;
}


void ShortestDistanceInDAG()
{
    int n, m, src;
    cin >> n >> m >> src;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(n, INT_MAX);
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            topoSort(i, adj, vis, st);
    }

    dist[src] = 0;
    while (!st.empty())
    {
        auto top = st.top();
        st.pop();
        for (auto x : adj[top])
        {
            int nb = x.first;
            int nw = x.second;
            if (dist[top] != INT_MAX && dist[nb] > dist[top] + nw)
            {
                dist[nb] = dist[top] + nw;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            cout << i << " -> -1\n";
        else
            cout << i << " -> " << dist[i] << "\n";
    }
}

// Djiktra's Algo
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

void floydWarshall(vector<vector<int>> &dist)
{
    int n = dist.size();
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][via] != 1e8 && dist[via][j] != 1e8)
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dist[i][i] < 0)
            cout << "NEGETIVE CYCLE\n";
    }
}

// Minimum Spanning Tree
//  1. Prims Algorithm

void primsAlgo()
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
    vector<pair<int, int>> mst;
    // assuming starting point is 0
    int sum = 0;
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    vector<int> vis(n, 0);
    //{weight,node,parent}
    pq.push({0, {0, -1}});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int node = it.second.first;
        int parent = it.second.second;
        int wt = it.first;

        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        sum += wt;

        if (parent != -1)
            mst.push_back({node, parent});

        for (auto x : adj[node])
        {
            int adjacentNode = x.first;
            int weight = x.second;

            if (!vis[adjacentNode])
            {
                pq.push({weight, {adjacentNode, node}});
            }
        }
    }

    cout << sum << endl;
    for (auto x : mst)
        cout << x.first << " " << x.second << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dfsHelper();
}