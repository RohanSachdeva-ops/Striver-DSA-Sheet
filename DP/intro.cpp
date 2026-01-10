//TOP-DOWN

// #include<bits/stdc++.h>
// using namespace std;

// int fibo(int n,vector<int>& dp){
//     if(n<=1) return n;
//     dp[0]=0,dp[1]=1;
//     if(dp[n]!=-1) return dp[n];
//     return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
// }


// int main(){
//     int n;cin>>n;
//     vector<int> dp(n+1,-1);
//     fibo(n,dp);
//     cout<<dp[n];
// }



// //BOTTOM UP
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;cin>>n;
//     vector<int> dp(n+1,-1);
//     dp[0]=0,dp[1]=1;
//     for(int i=2;i<=n;i++){
//         dp[i] = dp[i-1]+dp[i-2];
//     }
//     cout<<dp[n];
// }

//BOTTOM UP
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> dp(n+1,-1);
    int prev2=0,prev=1,curr=-1;
    for(int i=2;i<=n;i++){
        curr = prev+prev2;
        prev2=prev;
        prev=curr;
    }
    cout<<prev;
}