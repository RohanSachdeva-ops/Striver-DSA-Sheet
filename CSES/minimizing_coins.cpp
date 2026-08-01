// #include <bits/stdc++.h>
// using namespace std;


// int main() {
   
//     int n,x;cin>>n>>x;
//     vector<int> c(n);
//     for (int i = 0; i < n; i++) {
//         cin >> c[i];
//     }

//     vector<int> dp(x+1,1e9);
//     //dp[s]->minimum coins to make sum 's'
//     dp[0] = 0;
//     for(int s=0;s<=x;s++){
//         for(int i=0;i<n;i++){
//             if(s-c[i] >= 0) {
//                 dp[s] = min(dp[s],dp[s-c[i]]+1);
//             }
//         }
//     }
//     if(dp[x] != 1e9)cout << dp[x] << endl;
//     else cout << -1 << endl;
// }































