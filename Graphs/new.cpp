// #include<bits/stdc++.h>
// using namespace std;

// class graph{
//   public:
//   vector<vector<pair<int,int>>> adj;

//   void addEdge(int u,int v,int weight,bool direction){
//     adj[u].push_back({u,weight});
//     if(direction==false) adj[v].push_back({v,weight});
//   }
// };

// void buildGraph(graph& g)

// int main(){

// }

#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis, stack<int>& st){
  vis[node]=1;

  for(auto x:adj[node]){
    int node = x.first;
    int weight=x.second;

    if(!vis[node]) dfs(node, adj,vis,st);
  }
  st.push(node);
}

void ShortestDistanceDirectedGraph(){
  int n,m;cin>>n>>m;
  vector<vector<pair<int,int>>> adj(n);
  
  for(int i=0;i<m;i++){
    int u,v,w;cin>>u>>v>>w;
    
    adj[u].push_back({v,w});
  }

  int src;cin>>src;

  stack<int> st;
  vector<int> vis(n,0);
  
  //toposort
  for(int i=0;i<n;i++){
    if(!vis[i]) dfs(i,adj,vis,st);
  }
  
  vector<int> dist(n,INT_MAX);
  dist[src]=0;

  while(!st.empty()){
    int node=st.top();st.pop();

    for(auto it:adj[node]){
      int v = it.first;
      int weight=it.second;

      if(dist[node]+weight < dist[v]){
        dist[v]= dist[node]+weight;
      }
    }
  }

  for(auto x:dist) cout<<x<<" ";
}

void ShortestDistanceUndirectedGraphByPriorityQueue(){
  int n,m;cin>>n>>m;
  vector<vector<pair<int,int>>> adj(n);
  for(int i=0;i<m;i++){
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }

  int src;cin>>src;
  
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  vector<int> dist(n,INT_MAX);

  dist[src]=0;
  pq.push({0,src});

  while(!pq.empty()){
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for(auto x:adj[node]){
      int v = x.first;
      int vw = x.second;

      if(dis+vw < dist[v]){
         dist[v]=dis+vw;
         pq.push({dist[v],v});
      }
    }
  }

  for(auto x:dist) cout<<x<<" ";
}

int main(){
  int n,m;cin>>n>>m;
  vector<vector<pair<int,int>>> adj(n);
  for(int i=0;i<m;i++){
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }

  int src;cin>>src;

  vector<int> dist(n,INT_MAX);
  set<pair<int,int>>st;

  dist[src]=0;
  st.insert({0, src});

  while(!st.empty()){
    auto it = *(st.begin());
    int dis = it.first;
    int node=it.second;

    st.erase(it);
    for(auto x:adj[node]){
      int v = x.first;
      int vw = x.second;

      if(dis+vw < dist[v]){
        if(dist[v] != INT_MAX){
          st.erase({dist[v],v});
        }

        dist[v]=dis+vw;
        st.insert({dist[v],v});
        
      }
    }
  }

  for(auto x:dist) cout<<x<<" ";
}