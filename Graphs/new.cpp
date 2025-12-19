#include<bits/stdc++.h>
using namespace std;

class graph{ 
  public:
    vector<vector<int>> adj;
    void addEdge(int u,int v,bool direction){
      adj[u].push_back(v);
      if(direction==0) 
        adj[v].push_back(u);
    }

    void printAdjList(){
      for(int i=0;i<adj.size();i++){
        cout<<i<<"->";
        for(auto x:adj[i]){
          cout<<x<<" ";
        }
        cout<<endl;
      }
    }
};
void buildGraph(graph &g){
  int n,m;cin>>n>>m;

  g.adj.resize(n);

  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    g.addEdge(u,v,1);
  }
}

void dfs(int node,vector<vector<int>>& adj, vector<int>& vis,stack<int>& st){

  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it]) dfs(it,adj,vis,st);
  }
  st.push(node);
}
void TopoSort(vector<vector<int>>& adj){
  int n=adj.size();
  stack<int> st;
  vector<int> topo;

  vector<int> vis(n,0);

  for(int i=0;i<n;i++){
    if(!vis[i]) dfs(i,adj,vis,st);
  }

  while(!st.empty()){
    auto it = st.top();st.pop();
    topo.push_back(it);
  }
  for(auto x:topo) cout<<x<<" ";
}

void TopoSortBFS(vector<vector<int>>& adj){
  int n=adj.size();
  vector<int> inDegree(n);

  for(int i=0;i<n;i++){
    for(auto it:adj[i]){
      inDegree[it]++;
    }
  }

  queue<int> q;
  for(int i=0;i<n;i++){
    if(inDegree[i]==0){
      q.push(i);
    }
  }

  vector<int> topoBFS;
  while(!q.empty()){
    auto it=q.front();q.pop();
    topoBFS.push_back(it);

    for(auto x:adj[it]){
      inDegree[x]--;
      if(inDegree[x]==0){
        q.push(x);
      }
    }
  }

  for(auto x:topoBFS){
    cout<<x<<" ";
  }
}

int main(){
  graph g;
  buildGraph(g);
  
  TopoSortBFS(g.adj);cout<<endl;
  TopoSort(g.adj);
}
