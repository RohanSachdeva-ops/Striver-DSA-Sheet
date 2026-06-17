#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = (1);
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
  }

  vector<vector<int>> ans(n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(!dp[i][j]) continue; 
      ans[i].push_back(dp[i][j]);
    }
  }


   for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i+1; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}