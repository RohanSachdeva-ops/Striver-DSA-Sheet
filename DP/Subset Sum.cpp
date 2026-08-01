#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,target;
    cin>>n>>target;

    vector<int> temp(n);
    for(int i=0;i<n;i++) cin>>temp[i];

    vector<int> dp(target+1,0);

    dp[0]=1;

    for(auto x:temp){
        for(int i=x;i<=target;i++){
            dp[i] = dp[i] | dp[i-x];
        }
    }
    cout << dp[target] << endl;
}