#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

bool cmp(pair<pair<int,int>, int> a,pair<pair<int,int>, int> b){
  if(a.first.first != b.first.first){
    return a.first.first > b.first.first;
  }else{
    return a.second < b.second;
  }
}

void solve() {
  vector<pair<int, pair<int,int>>> v1 = {{1,{0,0}} , {1,{1,0}}, {1,{0,1}}, {2,{1,1}}};
  vector<pair<pair<int,int> ,int>> v2 = {{{0,0},1}, {{1,0}, 1}, {{0,1},1}, {{1,1},2}};

  sort(v2.begin(),v2.end(),cmp);
  
  for(auto x:v2){
    cout<<"{"<<x.first.first<<","<<x.first.second<<"}"<<","<<x.second<<endl;
  } 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}