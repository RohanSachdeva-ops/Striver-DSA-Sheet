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

void dfsTopo(int node,vector<vector<int>>& adj, vector<int>& vis,stack<int>& st){
  vis[node]=1;
  for(auto x:adj[node]){
    if(!vis[node]) dfsTopo(x,adj,vis,st);
  }
  st.push(node);
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
}

