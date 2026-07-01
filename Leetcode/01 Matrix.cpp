#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m;cin>>n>>m;
    vector<vector<int>> mat(n,vector<int> (m,0));
    vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>mat[i][j];
        if(!mat[i][j]) q.push({i,j}),dist[i][j]=0;
        
      }
    }

    vector<int> delcol = {-1,1,0,0};
    vector<int> delrow = {0,0,-1,1};

    while(!q.empty()){
      auto it = q.front();
      q.pop();
      int r = it.first;
      int c = it.second;

      for(int i=0;i<4;i++){
        int nr = r+delrow[i];
        int nc = c+delcol[i];

        if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==1){
          if(dist[nr][nc] > dist[r][c]+1){
            dist[nr][nc] = dist[r][c]+1;
            q.push({nr,nc});
          }
        }
      }
    }

     for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cout << dist[i][j] << " ";
      }
      cout << endl;
    }
}