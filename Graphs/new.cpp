#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;cin>>n>>m;
  vector<vector<int>> grid(n, vector<int> (m,0));
  vector<vector<int>> dist(n, vector<int> (m,INT_MAX));

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>grid[i][j];
    }
  }

priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;

  pq.push({0, {0,0}});
  dist[0][0]=0;

  vector<int> delrow = {-1,1,0,0};
  vector<int> delcol = {0,0,-1,1};

  while(!pq.empty()){
    auto it = pq.top();pq.pop();
    int dis = it.first;
    int row = it.second.first;
    int col = it.second.second;

    if(row==n-1 && col==m-1){
       cout << dis;
       return 0;
    }

    for(int i=0;i<4;i++){
      int nr = row+delrow[i];
      int nc = col+delcol[i];

      if(nr>=0 && nc>=0 && nc<m && nr<n){
        int newEffort = max(abs(grid[row][col] - grid[nr][nc]), dis);
        if(newEffort < dist[nr][nc]){
          dist[nr][nc]=newEffort;
          pq.push({newEffort, {nr,nc}});
        }
      }
    }
  }
}