#include <bits/stdc++.h>
using namespace std;

// void ShortestDistanceInDAG()
// {
//     int n, m, src;
//     cin >> n >> m >> src;
//     vector<vector<pair<int, int>>> adj(n);
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//     }

//     vector<int> dist(n, INT_MAX);
//     vector<int> vis(n, 0);
//     stack<int> st;
//     for (int i = 0; i < n; i++)
//     {
//         if (!vis[i])
//             topoSort(i, adj, vis, st);
//     }

//     dist[src] = 0;
//     while (!st.empty())
//     {
//         auto top = st.top();
//         st.pop();
//         for (auto x : adj[top])
//         {
//             int nb = x.first;
//             int nw = x.second;
//             if (dist[top] != INT_MAX && dist[nb] > dist[top] + nw)
//             {
//                 dist[nb] = dist[top] + nw;
//             }
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (dist[i] == INT_MAX)
//             cout << i << " -> -1\n";
//         else
//             cout << i << " -> " << dist[i] << "\n";
//     }
// }

void topoSort(int node,vector<vector<pair<int,int>>>& adj,vector<int>& vis,vector<int>& topo){
  vis[node]=1;
  for(auto x:adj[node]){
    if(!vis[x.first]) {
      topoSort(x.first,adj,vis,topo);
    }
  }
  topo.push_back(node);
}

int main() {
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> vis(n+1);
    for(int i=0;i<m;i++){
      int u,v,wt;cin>>u>>v>>wt;
      adj[u].push_back({v,wt});
    }

    vector<int> topo;
    for(int i=1;i<=n;i++){
      if(!vis[i]){
        topoSort(i,adj,vis,topo);
      }
    }

    reverse(topo.begin(),topo.end());
    
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
    stack<int> st;
    
    
}