#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  vector<vector<pair<int,int>>> adj(n);

  for(int i=0;i<m;i++)
  {
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});

  }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n,INT_MAX);
    int src=0;
    

    int count=0;
    
    dist[src]=0;  
    pq.push({0,src});
    while(!pq.empty()){
      auto it = pq.top();pq.pop();
      int node=it.second;
      int dis=it.first;

      for(auto x:adj[node]){
        int v=x.first;
        int vw=x.second;

        if(dis+vw < dist[v]){
          dist[v]=dis+vw;
          pq.push({dist[v],v});
        }
      }
    }


    int req=dist[n-1];
   vector<int> dist2(n,INT_MAX);
   queue<pair<int,int>> q;

    dist2[src]=0;  
    q.push({0,src});
    while(!q.empty()){
      auto it = q.front();q.pop();
      int node=it.second;
      int dis=it.first;

      for(auto x:adj[node]){
        int v=x.first;
        int vw=x.second;
        if(dis+vw <= dist2[v]){
          dist2[v]=dis+vw;
          q.push({dist2[v],v});
        }
      }
    }

    cout<<count;
}