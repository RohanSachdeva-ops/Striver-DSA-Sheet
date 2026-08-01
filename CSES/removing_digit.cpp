#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int> dp(n+1,1e9);
    dp[0]=0;
    for(int x=0;x <= n;x++){
        int temp = x;
        while(temp>0){
            int digit = temp%10;
            temp = temp/10;
            if(digit == 0) continue;
            dp[x] = min(dp[x],1+dp[x-digit]);
        }
    }

    cout << dp[n] << endl;
}