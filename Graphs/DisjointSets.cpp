#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

class DisjointSet{
    vector<int> rank,parent,size;
    
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
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