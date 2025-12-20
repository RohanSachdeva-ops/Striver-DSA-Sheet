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

int main(){
  graph g;
  buildGraph(g);

  shortestDist(0,g.adj);
}
