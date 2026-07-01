#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

bool isPalindrome(int i, int j, string &s)
{
  while (i < j)
  {
    if (s[i] != s[j])
      return false;
    i++;
    j--;
  }
  return true;
}

int f(int i, int j, string &s, int n, vector<vector<int>> &dp)
{
  if (i > j)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  int mini = 1e9;
  for (int ind = i; ind <= j; ind++)
  {
    if (isPalindrome(i, ind, s))
    {
      int way = 1 + (f(ind + 1, j, s, n, dp));
      mini = min(mini, way);
    }
  }

  return dp[i][j] = mini;
}

int main()
{
  string s;
  cin >> s;
  int n = s.size();

  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = i; j < n; j++)
    {
      int mini = 1e9;
      for (int ind = i; ind <= j; ind++)
      {
        if (isPalindrome(i, ind, s))
        {
          int way = 1;
          if(ind < j) way +=  dp[ind+1][j];
          mini = min(mini, way);
        }
      }
      dp[i][j] = mini;
    }
  }

  cout << dp[0][n - 1] - 1;
}