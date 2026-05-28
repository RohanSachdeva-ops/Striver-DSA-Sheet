#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string lcs;
    lcs.resize(dp[n][m]);
    int index = dp[n][m]-1;
    
    int i=n,j=m;
    while(i>0&&j>0){
        if(s1[i-1]==s2[j-1]){
            lcs[index]=s1[i-1];
            index--;
            i--;j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    if(lcs != s2) cout << false << endl;
    
}