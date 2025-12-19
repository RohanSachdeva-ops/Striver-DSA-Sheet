#include<bits/stdc++.h>
using namespace std;

//We can use 2 storage method to store adjacency list i.e
//1. map<int, vector<int>>
//2. vector<vector<int>> 

class graph{ 
  public:
    unordered_map<int, vector<int>> adj;
    vector<vector<int>> adj2;
    void addEdge(int u,int v,bool direction){
      //u-->j
      adj[u].push_back(v);
      if(direction==0) 
        adj[v].push_back(u);
    }

    void printAdjList(){
      for(auto i:adj){
        cout<<i.first<<"->";
        for(auto j:i.second){
          cout<<j<<", ";
        }
        cout<<endl;
      }
    }
};

void buildGraph(graph g){
  int n,m;cin>>n>>m;

  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    g.addEdge(u,v,0);
  }
  g.printAdjList();
}

int main(){
  cout<<"Enter the number of nodes and edges repectively ";
  graph g;
  buildGraph(g);
  
  return 0;
}