#include<bits/stdc++.h>
using namespace std;

class graph{
  public:
    vector<vector<int>> adj;

    void addEdge(int u,int v,bool direction){
      adj[u].push_back(v);
      if(direction==0) adj[v].push_back(u);
    }
    
    void printAdjList(){
      int n=adj.size()-1;
      for(int i=1;i<=n;i++){
        cout<<i<<"-> ";
        for(auto x:adj[i]){
          cout<<x<<" ";
        }
        cout<<endl;
      }
    }
};

void buildTree(graph& g){
  int n,m;cin>>n>>m;
  g.adj.resize(n+1);

  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    g.addEdge(u,v,0);
  }
}

// vector<int> bfs(int node, vector<vector<int>>& adj){
//   vector<int> bfs_vector;

//   int n=adj.size()-1;
//   vector<int> vis(n+1,0);

//   vis[node]=1;
//   queue<int> q; q.push(node);
//   while(!q.empty()){
//     int it=q.front();q.pop();
//     bfs_vector.push_back(it);

//     for(auto x:adj[it]){
//       if(!vis[x]){
//         vis[x]=1;
//         q.push(x);
//       } 
//     }
//   }

//   return bfs_vector;
// }


void bfs(int row,int col,vector<vector<int>>& v, vector<vector<int>>& vis){
  int n=v.size();
  int m=v[0].size();
  queue<pair<int,int>> q;
  q.push({row,col});
  vis[row][col]=1;
  while(!q.empty()){
    auto it = q.front();q.pop();
    int x = it.first; int y = it.second;
    

    for(int delrow=-1;delrow<=1;delrow++){
      for(int delcol=-1;delcol<=1;delcol++){
        int x_new = x+delrow;
        int y_new = y+delcol;

        if( x_new>=0 && x_new<n && y_new>=0 && y_new<m && !vis[x_new][y_new] && v[x_new][y_new] ){
          vis[x_new][y_new]=1;
          q.push({x_new,y_new});
        }
      }
    }
  }
}
void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& dfs_vector, vector<int>& vis){
  vis[node]=1;
  dfs_vector.push_back(node);

  for(auto x:adj[node]){
    if(!vis[x]) dfsHelper(x,adj,dfs_vector,vis); 
  }
}
vector<int> dfs (int node, vector<vector<int>>& adj){
  int n=adj.size()-1;
  vector<int> dfs_vector;
  vector<int> vis(n+1,0);
  dfsHelper(node, adj, dfs_vector,vis);
  return dfs_vector;
  }

int numberOfConnectedComponent(vector<vector<int>>& v){
  int n=v.size();
  int m=v[0].size();
  vector<vector<int>> vis(n, vector<int> (m,0));
  int counter=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(!vis[i][j] && v[i][j]==1) {
        counter++;
        bfs(i,j,v,vis);
      }
    }
  }
  return counter;
}

int main(){
  // graph g;
  // buildTree(g);

  int n, m;cin>>n>>m;
  vector<vector<int>> v(n, vector<int> (m,0));

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>v[i][j];
    }
  }

  cout<<numberOfConnectedComponent(v);
}