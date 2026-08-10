#include <bits/stdc++.h>
using namespace std;

int f(int s, vector<int>& coins){
    int n = coins.size();
    if(s == 0) return 1;    
    if(s<0) return 0;

    int number_of_ways = 0;
    for(int i=0;i<n;i++){
        if(s-coins[i]>=0) number_of_ways += (f(s-coins[i], coins));
    }

    return number_of_ways;
}

int main()
{
    long long n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    sort(coins.begin(),coins.end());

    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    // dp[s] = number of ways to make sum 's'

    for (int s = 1; s <= target; s++){
        for(int i=0;i<n;i++){
            if(s < coins[i]) break;
            if(s >= coins[i]) dp[s] += dp[s-coins[i]];
        }
    }

    cout << dp[target] << endl;
}