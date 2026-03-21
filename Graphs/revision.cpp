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

bool isCycleByBFS(int start,vector<vector<int>>& adj, vector<int>& vis){
    int n=adj.size()-1;
    queue<pair<int,int>> q;
    q.push({start,-1});
    vis[start]=1;

    while(!q.empty()){
        auto it=q.front();q.pop();
        int node=it.first;
        int parent=it.second;

        for(auto x:adj[node]){
            if(!vis[x]) q.push({x,node}),vis[x]=1;
            else if(x != parent) return true;
        }
    }
    return false;
}
void isCycleByBFS_helper(){
    int n,m,node;cin>>n>>m>>node;
    vector<int> vis(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(isCycleByBFS(i,adj,vis)) cout << 1 <<endl;
        }
    }
    cout << 0 << endl;
    
}


bool isCycleByDFS(int node,int parent,vector<vector<int>>& adj,vector<int>& vis){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]) isCycleByDFS(x,node,adj,vis);
        else if(x!=parent) return true;
    }
    return false;
}
void isCycleByDFS_helper(){
    int n,m,node;cin>>n>>m>>node;
    vector<int> vis(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(isCycleByDFS(i,-1,adj,vis)){ cout << 1 <<endl;return;};
        }
    }
    cout << 0 << endl;
    
}

bool isCycleDirectedDFS(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathVis){
    vis[node]=1;
    pathVis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x]){
            if(isCycleDirectedDFS(x,adj,vis,pathVis) == true) return true;
        } 

        else if(pathVis[x] == 1) return true;
        
    }

    pathVis[node]=0;
    return false;
}
bool isCycleDirectedDFS_helper(){
    int n,m;cin>>n>>m;
    vector<int> vis(n+1);
    vector<int> pathVis(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(isCycleDirectedDFS(i,adj,vis,pathVis)) return true;
        }
    }
    return false;
}


void ShortestDistanceUndirectedUnitWeight(){
    int n,m,src;cin>>n>>m>>src;
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        queue<int> q;
        q.push(src);
        dist[src]=0;
        
        while(!q.empty()){
            auto node = q.front();q.pop();
            for(auto x:adj[node]){
                if(dist[node]+1 < dist[x]){
                    dist[x]=dist[node]+1;
                    q.push(x);
                }
            }
        }
    
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX)  ans[i] = -1;
            else ans[i]=dist[i];
        }
}

void topoSort(int node,vector<vector<pair<int,int>>>& adj,vector<int>& vis,stack<int>& st){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x.first]){
            topoSort(x.first,adj,vis,st);
        } 
    }
    st.push(node);
}
void ShortestDistanceInDAG(){
        int n,m,src;cin>>n>>m>>src;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<m;i++){
            int u,v,w;cin>>u>>v>>w;
            adj[u].push_back({v,w});
        }
        
    vector<int> dist(n,INT_MAX);
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]) topoSort(i,adj,vis,st);
    }


    dist[src]=0;
    while(!st.empty()){
        auto top = st.top();st.pop();
        for(auto x:adj[top]){
            int nb=x.first;
            int nw=x.second;
            if(dist[top] != INT_MAX && dist[nb] > dist[top] + nw){
                dist[nb]=dist[top]+nw;
            }
        }
    }

    for(int i=0;i<n;i++) {
        if(dist[i] == INT_MAX) cout << i << " -> -1\n";
    else cout << i << " -> " << dist[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // ShortestDistance();
}