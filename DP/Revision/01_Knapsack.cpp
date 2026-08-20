// Bounded knapsack -> only one time picking

// 0-1 Knapsack
#include <bits/stdc++.h>
using namespace std;

int f1(int n, int W, vector<int> &val, vector<int> &wt)
{
    // 1-D DP with only one picking
    // backward inner loop

    vector<int> dp(W + 1);
    for (int i = 0; i < n; i++)
    {
        for (int w = W; w >= wt[i]; w--)
        {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }

    return dp[W];
}

int f2(int n, int W, vector<int> &val, vector<int> &wt)
{
    // 2D DP with only one picking

    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            int skip = dp[i - 1][w];

            int take = INT_MIN;
            if (w - wt[i-1] >= 0)
                take = val[i-1] + dp[i - 1][w - wt[i-1]];

            dp[i][w] = max(take,skip);
        }
    }

    return dp[n][W];
}

int main()
{
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

    cout << f1(n, W, val, wt);
    cout << endl;
    cout << f2(n, W, val, wt);
}
