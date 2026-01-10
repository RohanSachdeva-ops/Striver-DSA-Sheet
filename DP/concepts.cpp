#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin>>h[i];
    vector<int> dp(n,-1);
    
    dp[0]=h[0];
    dp[1]=max(h[0],h[1]);
    for(int i=2;i<=n;i++){
        dp[i] = max(dp[i-1], dp[i-2]+h[i]);
    }
    cout<<dp[n];
}


// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n,k;cin>>n>>k;
//     vector<int> h(n);
//     for(int i=0;i<n;i++) cin>>h[i];
//     vector<int> dp(n,-1);
    
//     dp[0]=0;
    
//     for(int i=1;i<n;i++){
//         int mini = INT_MAX;
//             for(int j=1;j<=k;j++){
//             if(i-j>=0){ 
//                 mini = min(mini, dp[i-j]+abs(h[i]-h[i-j]));
//             }
//         }
//         dp[i]=mini;
//     }
// cout<<dp[n-1];
// }



// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;cin>>n;
//     vector<int> h(n);
//     for(int i=0;i<n;i++) cin>>h[i];
//     vector<int> dp(n,-1);
    
//     dp[0]=0;
//     dp[1]=abs(h[1]-h[0]);

//     for(int i=2;i<n;i++){
//         dp[i]=min(dp[i-1]+(abs(h[i]-h[i-1])) , dp[i-2]+(abs(h[i]-h[i-2])));
//     }
// cout<<dp[n-1];
// }