#include <bits/stdc++.h>
using namespace std;

int f(int n, int W, vector<int> &val, vector<int> &wt)
{
    // 1-D DP with only unlimited picking
    // forward inner loop

    vector<int> dp(W + 1);
    for (int i = 0; i < n; i++)
    {
        for (int w = wt[i]; w <=W; w++)
        {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }

    return dp[W];
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    vector<int> wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << f(n,W,val,wt);
}