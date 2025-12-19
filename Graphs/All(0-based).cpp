#include<bits/stdc++.h>
using namespace std;

class graph{ 
  public:
    vector<vector<int>> adj;

    // graph(int n = 0) {
    //     adj.resize(n);
    // }

    void addEdge(int u,int v,bool direction){
      //u-->j
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
    g.addEdge(u,v,0);
  }
  // g.printAdjList();
}

vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        vis[0]=1;
        queue<int> q; q.push(0);
        vector<int> bfs;
        while(!q.empty()){
            auto it = q.front();q.pop();
            bfs.push_back(it);
            for(auto x:adj[it]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
        return bfs;
    }

int main(){
  graph g;
  buildGraph(g);

  g.printAdjList();
  // vector<int> v = bfs(g.adj);
  // for(auto x:v) cout<<x<<" ";
  return 0;
}

