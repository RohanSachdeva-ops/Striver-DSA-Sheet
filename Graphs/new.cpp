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
    g.addEdge(u,v,1);
  }
}

bool dfsCycle(int node,vector<vector<int>>& adj,vector<int>& vis, vector<int>& pathVis){
  int n=adj.size()-1;

  vis[node]=1;
  pathVis[node]=1;

  for(auto x:adj[node]){
    if(!vis[x]){
       if(dfsCycle(x,adj,vis,pathVis)==true){
        return true;
       }
    }
    else if(vis[x]==1 && pathVis[x]==1) return true;
  }
  pathVis[node]=0;
  return false;
}
bool isCycleDirected(vector<vector<int>>& adj){
  int n=adj.size()-1;
  vector<int> vis(n+1,0);
  vector<int> pathVis(n+1,0);
  for(int i=1;i<=n;i++){
    if(!vis[i]) {
      if(dfsCycle(i,adj,vis,pathVis)==true){
        return true;
      }
    }
  }
  return false;
}

void dfsTopo(int node,vector<vector<int>>& adj, vector<int>& vis,stack<int>& st){
  vis[node]=1;
  for(auto x:adj[node]){
    if(!vis[node]) dfsTopo(x,adj,vis,st);
  }
  st.push(node);
}
void topoDFS(vector<vector<int>>& adj){
  int n=adj.size()-1;
  vector<int> vis(n+1,0);
  stack<int> st;
  for(int i=1;i<=n;i++){
    if(!vis[i]) dfsTopo(i,adj,vis,st);
  }
  
  vector<int> topoAns;
  while(!st.empty()){
    int top = st.top();st.pop();
    topoAns.push_back(top);
  }

  for(auto x:topoAns){
    cout<<x<<" ";
  }
}


bool isCycleDirectedBFS(vector<vector<int>>& adj){
  int n=adj.size()-1;
  vector<int> inDegree(n+1,0);

  for(int i=1;i<=n;i++){
    for(auto x:adj[i]){
      inDegree[x]++;
    }
  }
  queue<int> q;
  for(int i=1;i<=n;i++){
    if(inDegree[i]==0){
      q.push(i);
    }
  }
  vector<int> ans;
  while(!q.empty()){
    int front=q.front();q.pop();
    ans.push_back(front);

    for(auto x:adj[front]){
      inDegree[x]--;
      if(inDegree[x]==0){
        q.push(x);
      }
    }
  }

  if(ans.size()!=n) return true;
  else return false;
}



int main(){
  graph g;
  buildGraph(g);
  
  cout<<isCycleDirectedBFS(g.adj);
}
