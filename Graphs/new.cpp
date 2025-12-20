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

  g.adj.resize(n+1);

  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    g.addEdge(u,v,0);
  }
}


void shortestDist(int src,vector<vector<int>>& adj){
  int n=adj.size()-1;
  vector<int> dist(n,INT_MAX);
  queue<pair<int,int>> q;
  dist[src]=0;
  q.push({src,0});

  while(!q.empty()){
    auto front=q.front();q.pop();
    
    int node=front.first, d=front.second;

    for(auto x:adj[node]){
      if(dist[x] > d+1) {
        dist[x]=d+1;
        q.push({x,d+1});
      }
    }
  }

  for(auto x:dist) cout<<x<<" ";
}

int main(){
  graph g;
  buildGraph(g);

  shortestDist(0,g.adj);
}
