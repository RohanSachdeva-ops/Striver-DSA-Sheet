#include<bits/stdc++.h>
using namespace std;

class DisjointSets{
  public:
    vector<int> parent,rank,size;
  
  DisjointSets(int n){
    parent.resize(n);
    rank.resize(n,0);
    size.resize(n,1);

    for(int i=0;i<n;i++) parent[i]=i;
  }

  int findUParent(int node){
    if(node == parent[node]) return node;

    return parent[node] = findUParent(parent[node]);
  }

  void UnionByRank(int u,int v){
    int ulp_u = findUParent(u);
    int ulp_v = findUParent(v);

    if(rank[ulp_u]<rank[ulp_v]) {
      parent[ulp_u] = ulp_v;
    }else if(rank[ulp_v] < rank[ulp_u]){
      parent[ulp_v] = ulp_u;
    }else{
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

    void UnionBySize(int u,int v){
      int ulp_u = findUParent(u);
      int ulp_v = findUParent(v);
    
      if(size[ulp_u]<size[ulp_v]) {
      parent[ulp_u] = ulp_v;size[ulp_v]+=size[ulp_u];
      }else{
        parent[ulp_v] = ulp_u;size[ulp_u]+=size[ulp_v];
      }
  }
};

void question1(){
   int n,m;cin>>n>>m;
  vector<pair<int,int>> c;
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    c.push_back({u,v});
  }

  DisjointSets ds(n);
  int count = 0;
  for(auto x:c){
    int u = x.first;
    int v = x.second;

    if(ds.findUParent(u) == ds.findUParent(v)) count++;    
    else {
      ds.UnionByRank(u,v);
    }
  }

  int component = 0;
  for(int i=0;i<n;i++){
    if(ds.findUParent(i) == i) component++;
  }

  if(component-1 <= count) cout << component-1;
  else cout << -1 << endl;
}


int main(){
 
}