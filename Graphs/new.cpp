#include <bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<vector<int>>& graph,vector<int>& color){
 
  for(auto x:graph[node]){
    if(color[x]==-1){
      if(color[node] == 0) color[x] = 1;
      else color[x]=0;

      if(!dfs(x,graph,color)){
        return false;
      }
    } 

    else if(color[node] == color[x]){
      return false;
    }

  }
  return true;
}
int main() {
  int n;cin>>n;
   vector<vector<int>> graph(n);
    for(int i=0;i<n;i++){
      int m;cin>>m;
      vector<int> temp(m);
      for(int j=0;j<m;j++){
        cin>>temp[j];
      }
      graph[i] = temp;
    }
    vector<int> color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i] == -1){
          color[i] = 1;
          if(!dfs(i,graph,color)){
            cout << "NO\n";
            return 0;
          }
        }
    }
    cout << "YES\n";
    return 0;
}