#include <bits/stdc++.h>
using namespace std;

void dfs1(int u,int p,vector<vector<int>>& adj,vector<int>& ans, vector<int>& cnt) {

  for(auto v:adj[u]){
    if(v == p) continue;
    dfs1(v, u, adj, ans, cnt);

    cnt[u] += cnt[v];
    ans[u] += cnt[v]+ans[v];
  }
}


void dfs2(int u,int p,vector<vector<int>>& adj,vector<int>& ans, vector<int>& cnt,int n) {

  for(auto v:adj[u]){
    if(v == p) continue;
    ans[v] = (ans[u]-cnt[v]) + (n - cnt[v]);
    dfs2(v, u, adj, ans, cnt, n);
  }

}


int main() {
    int n,m;
    cin >> n >> m;

    vector<int> ans(n);
    vector<int> cnt(n,1);
    
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
      int u,v;cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs1(0,-1,adj,ans,cnt);
    dfs2(0,-1,adj,ans,cnt,n);

    for(auto x:ans) cout << x <<" ";
    
}