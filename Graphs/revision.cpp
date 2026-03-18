#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void bfs(){
    int n,m;cin>>n>>m;int node;cin>>node;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    vector<int> vis(n+1,0);
    vector<int> bfs;
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
        auto it = q.front();q.pop();
        bfs.push_back(it);
        vis[it]=1;

        for(auto x:adj[it]){
            if(vis[x]!=1){
                vis[x]=1;
                q.push(x);
            }
        }
    }

    for(auto x:bfs) cout << x <<" ";
}

void dfs(int node,vector<int>& vis, vector<vector<int>>& adj,vector<int>& dfsV){
    vis[node]=1;
    dfsV.push_back(node);
    for(auto x:adj[node]){
        if(vis[x] != 1){
            dfs(x,vis,adj,dfsV);
        }
    }
}


void dfsHelper(){
    int n,m,node;cin>>n>>m>>node;
    vector<int> vis(n+1),dfsV;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(node,vis,adj,dfsV);
    for(auto x:dfsV) cout << x << " ";
}
void dfs2(){
    int n,m,node;cin>>n>>m>>node;
    vector<int> vis(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    stack<int> st;
    st.push(node);
    vector<int> dfsv;
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(vis[it] == 1) continue;
        vis[it]=1;
        dfsv.pb(it);
        for(auto x:adj[it]){
            if(!vis[x]){
             st.push(x);
            }
        }
    }

    for(auto x:dfsv) cout << x << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    dfs2();
}