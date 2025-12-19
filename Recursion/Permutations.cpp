/*

#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& v,vector<int>& temp, unordered_map<int,int>& m, vector<vector<int>>& ans){
  if(temp.size() == v.size()){
    ans.push_back(temp);
    return;
  } 

  for(int i=0;i<v.size();i++){

    if(m[v[i]]==1) continue;

    temp.push_back(v[i]);
    m[v[i]]=1;
    backtrack(v,temp,m,ans);

    temp.pop_back();
    m[v[i]]=0;
  }
}

int main() {
    int n;cin>>n;
    vector<int> v(n),temp;vector<vector<int>> ans;
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]]=0;
    }

    backtrack(v,temp,m,ans);

    for(auto x:ans){
      for(auto e:x){
        cout<<e<<" ";
      }
      cout<<endl;
    }
}

*/
//optimize
#include <bits/stdc++.h>
using namespace std;

void backtrack(int i,vector<int>& v, vector<vector<int>>& ans){
  if(i == v.size()){
    ans.push_back(v);
    return;
  } 

  for(int idx=i;idx<v.size();idx++){

    swap(v[idx],v[i]);
    backtrack(i+1,v,ans);
    
    swap(v[idx],v[i]);
  }
}

int main() {
    int n;cin>>n;
    vector<int> v(n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    backtrack(0,v,ans);

    for(auto x:ans){
      for(auto e:x){
        cout<<e<<" ";
      }
      cout<<endl;
    }
}