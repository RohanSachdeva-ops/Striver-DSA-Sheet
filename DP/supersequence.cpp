#include<bits/stdc++.h>
using namespace std;
int main(){
    string str1,str2;cin>>str1>>str2;
    int n = str1.size(),m=str2.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    // vector<int> v1(n,0);
    // vector<int> v2(m,0);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    // cout << dp[n][m] << endl;

    string ans;
    ans.resize(dp[n][m]);

    int index = dp[n][m]-1;

    int i=n,j=m;
    while(i>0&&j>0){
        if(str1[i-1]==str2[j-1]){
            // v1[i-1]=1;
            // v2[j-1]=1;
            ans[index]=str1[i-1];
            index--;
            i--;j--;

        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }

    // cout << ans << endl;
    
    string ans2;

i = 0;
j = 0;

for(char c : ans){

    while(str1[i] != c){
        ans2 += str1[i];
        i++;
    }

    while(str2[j] != c){
        ans2 += str2[j];
        j++;
    }

    ans2 += c;
    i++;
    j++;
}

while(i < n){
    ans2 += str1[i];
    i++;
}

while(j < m){
    ans2 += str2[j];
    j++;
}

cout << ans2 << endl;
}