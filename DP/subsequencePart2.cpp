#include<bits/stdc++.h>
using namespace std;

int f(int i, vector<int>& w, vector<int>& val, int bag,vector<vector<int>>& dp){

    if (i == 0) {
        return (bag / w[0]) * val[0];
    }
    if(dp[i][bag]!=-1) return dp[i][bag];

    int take=-1e9;
    int nottake = f(i-1, w, val, bag,dp);
    if(w[i] <= bag){
        take = val[i]+f(i, w, val, bag-w[i],dp);
    }

    return dp[i][bag]=max(take, nottake);
}

int main(){
    int n,bag;cin>>n>>bag;
    vector<int> w(n,0), val(n,0);
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>val[i];

    vector<vector<int>> dp(n, vector<int> (bag+1, -1));
    cout << f(n-1, w ,val,bag,dp);
}