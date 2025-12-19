#include<bits/stdc++.h>
using namespace std;

void subsetSum(int i,int s, vector<int>& v, vector<int>& final){
  if(i==v.size()){
    final.push_back(s);
    return;
  }

  subsetSum(i+1,s+v[i],v,final);
  subsetSum(i+1,s,v,final);
}


int main(){
  int n;cin>>n;
  vector<int> v(n),final;
  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }

  subsetSum(0,0,v,final);
  sort(final.begin(),final.end());
  for(auto x:final){
    cout<<x<<" ";
  }
}