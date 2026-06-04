// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   string s1,s2;cin>>s1>>s2;
//   int n=s1.size();
//   int m=s2.size();

//   vector<vector<int>> dp(n+1,vector<int> (m+1,0));

//   for(int j=0;j<=m;j++) dp[0][j]=0;
//   for(int i=0;i<=n;i++) dp[i][0]=0;

//   for(int i=1;i<=n;i++){
//     for(int j=1;j<=m;j++){
//       if(s1[i-1]==s2[j-1]) {
//         dp[i][j] = dp[i-1][j-1]+1;
//       }else{
//         dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//       }
//     }
//   }
//   // for(int i=0;i<=n;i++){
//   //   for(int j=0;j<=m;j++){
//   //     cout<<dp[i][j]<<" ";
//   //   }
//   //   cout<<endl;
//   // }
//   int i=n,j=m;
//   string ans(dp[n][m],'.');
//   int ind = dp[n][m]-1;

//   while(i>0 && j>0){
//     if(s1[i-1]==s2[j-1]){
//       ans[ind] = s1[i-1];
//       ind--;
//       i-=1;
//       j-=1;
//     }else{
//       if(dp[i-1][j] > dp[i][j-1]){
//         i=i-1;
//       }else{
//         j=j-1;
//       }
//     }
//   }
// //Longest Substring
//   vector<vector<int>> dp2(n+1,vector<int> (m+1,0));
//   for(int j=0;j<=m;j++) dp2[0][j]=0;
//   for(int i=0;i<=n;i++) dp2[i][0]=0;

//   int longest=0;
//   for(int i=1;i<=n;i++){
//     for(int j=1;j<=m;j++){
//       if(s1[i-1] == s2[j-1]){
//         dp2[i][j] = 1+dp2[i-1][j-1];
//         longest=max(longest,dp2[i][j]);
//       }else{
//         dp2[i][j] = 0;
//       }
//     }
//   }
// }

