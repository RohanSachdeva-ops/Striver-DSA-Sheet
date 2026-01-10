#include<bits/stdc++.h>
using namespace std;

int counter(int n,vector<int>& dp){
    if(n<=1) return 1;

    if(dp[n]!=-1) return dp[n];

    int left=counter(n-1,dp);
    int right=counter(n-2,dp);
    return dp[n]=left+right;
}

int main(){
    int n;cin>>n;
    vector<int> dp(n+1,-1);
    cout<<counter(n,dp);
}