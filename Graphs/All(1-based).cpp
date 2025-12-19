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
      for(int i=1;i<adj.size();i++){
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
void dfs2(int node,vector<vector<int>>& adj,vector<int>& vis){
  int n=adj.size()-1;

  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it]) dfs2(it,adj,vis);
  }
}
int numberOfProvinces(vector<vector<int>>& adj,vector<int> vis){
  int counter=0;
  for(int i=1;i<adj.size();i++){
    if(!vis[i]){
      dfs2(i,adj,vis);
      counter++;
    }
  }
  return counter;
}

bool isCycle(int node, vector<vector<int>>& adj, vector<int>& vis){
  int n=adj.size()-1;
 

  queue<pair<int,int>> q;
  q.push({node,-1});
  vis[node]=1;
  while(!q.empty()){
    auto it=q.front();q.pop();
    int curr=it.first,prev=it.second;

    for(auto x:adj[curr]){
      if(!vis[x]){
        vis[x]=1;
        q.push({x,curr});
      }else{
        if(x != prev) return true;
      }

      
    }
  }
  return false;
}

bool isCycleDfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, bool& flag){
  vis[node]=1;

  for(auto &x:adj[node]){
    if(!vis[node]) isCycleDfs(x,node,adj,vis,flag);
    else{
      if(x!=parent) {
      flag=true;
      }
    }
  }
}

int main(){
  graph g;
  buildGraph(g);
  int n = g.adj.size()-1;

  vector<int> vis(0,n+1);
  // for(int i=1;i<n+1;i++){
  //   if(!vis[i]){
  //     if(isCycle(i,g.adj,vis) == true) {
  //       cout<<"Cycle Detected";
  //       return 0;
  //     }
  //   }
  // }
  cout<< isCycle(1,g.adj,vis);
  return 0;
}

