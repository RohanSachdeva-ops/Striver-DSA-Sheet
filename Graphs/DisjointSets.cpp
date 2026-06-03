#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pp = pair<int,pair<int,int>>;
#define endl '\n'
#define pb push_back

class DisjointSet{
    vector<int> rank,parent,size;
    
public:
    DisjointSet(int n){
        parent.resize(n+1);
        
        rank.resize(n+1,0);
        size.resize(n+1);

        for(int i=0;i<=n;i++) parent[i]=i,size[i]=1;
    }

    //PATH COMPRESSION
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    //DYNAMIC GRAPH
    void UnionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(rank[ulp_u] < rank[ulp_v])       parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v])  parent[ulp_v] = ulp_u;
        else if(rank[ulp_u] == rank[ulp_v]) parent[ulp_v] = ulp_u,rank[ulp_u]++;
    }

    void UnionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(size[ulp_u]<size[ulp_v]) size[ulp_v]+=size[ulp_u],parent[ulp_u] = ulp_v;
        else size[ulp_u]+=size[ulp_v],parent[ulp_v] = ulp_u;
    }
};

//Minimum Spanning Tree
// 1. Prims Algorithm

void primsAlgo(){
  int n,m;cin>>n>>m;
  vector<vector<pair<int,int>>> adj(n);
  for(int i=0;i<m;i++){
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  vector<pair<int,int>> mst;
  //assuming starting point is 0
  int sum=0;
  priority_queue<pp,vector<pp>,greater<pp>> pq;
  vector<int> vis(n,0);
  //{weight,node,parent}
  pq.push({0,{0,-1}});

  while(!pq.empty()){
    auto it = pq.top();pq.pop();

    int node=it.second.first;
    int parent=it.second.second;
    int wt=it.first;

    if(vis[node] == 1) continue;
    vis[node]=1;
    sum += wt;

    if(parent != -1) mst.push_back({node,parent});

    for(auto x:adj[node]){
        int adjacentNode = x.first;
        int weight = x.second;

        if(!vis[adjacentNode]){
            pq.push({weight, {adjacentNode,node}});
        }
    }
  }

  cout << sum << endl;
  for(auto x:mst) cout << x.first <<" "<<x.second<<endl;
}

//2.KRUSKAL'S ALGORITHM

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<pair<int,pair<int,int>>> ed;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            ed.push_back({w,{u,v}});
        }
            sort(ed.begin(),ed.end());
            
            DisjointSet ds(V);
            int wt=0;
            for(auto x:ed){
                int weight = x.first;
                int uu = x.second.first;
                int vv = x.second.second;
                
                if(ds.findUPar(uu) != ds.findUPar(vv)){
                    wt += weight;
                    ds.UnionByRank(uu, vv);
                }
            
        }
        
        return wt;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /*
    DisjointSet ds(7);
    ds.UnionByRank(1,2);    
    ds.UnionByRank(2,3);    
    ds.UnionByRank(4,5);    
    ds.UnionByRank(6,7);    
    ds.UnionByRank(5,6);
    
    //if 3 and 7 are in same component or not
    if(ds.findUPar(3) == ds.findUPar(7)) cout << "SAME\n";
    else cout << "NOT SAME\n";

    ds.UnionByRank(3,7);

    if(ds.findUPar(3) == ds.findUPar(7)) cout << "SAME\n";
    else cout << "NOT SAME\n";

    */

        DisjointSet ds(7);
        ds.UnionBySize(1,2);    
        ds.UnionBySize(2,3);    
        ds.UnionBySize(4,5);    
        ds.UnionBySize(6,7);    
        ds.UnionBySize(5,6);
    
    //if 3 and 7 are in same component or not
    if(ds.findUPar(3) == ds.findUPar(7)) cout << "SAME\n";
    else cout << "NOT SAME\n";

    ds.UnionByRank(3,7);

    if(ds.findUPar(3) == ds.findUPar(7)) cout << "SAME\n";
    else cout << "NOT SAME\n";
}