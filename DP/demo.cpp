#include <bits/stdc++.h>
using namespace std;

bool f(int i,vector<int>& v,int target, vector<vector<bool>>& dp){
  if(target==0) return true;
  if(i==0) return target==v[0];
  

  bool nottake = false,take=false;
  nottake = f(i-1,v,target,dp);
  if(target-v[i]>=0)take = f(i-1,v,target-v[i],dp);

  return take||nottake;
}

int main() {
    int n,sum;cin>>n>>sum;
    vector<int> v(n);
    vector<vector<bool>> dp(n+1,vector<bool> (sum+1,false));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout<<f(n-1,v,sum,dp);
}