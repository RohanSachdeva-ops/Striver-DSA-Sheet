#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,x;cin>>n>>x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    //dp[i][s]->maximum number of pages that he can get
    //under s rupees from i to n-1
    vector<vector<int>> dp(n+1,vector<int> (x+1));
    for(int i=n-1;i>=0;i--){
        for(int s=0;s<=x;s++){
            int take = INT_MIN;
            if(s-p[i] >= 0) take = pages[i] + dp[i+1][s-p[i]];
            int not_take = 0 + dp[i+1][s];

            dp[i][s] = max(take,not_take);
        }
    }

    cout << dp[0][x] << endl;
}