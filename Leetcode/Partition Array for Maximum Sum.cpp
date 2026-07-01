#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

int f(int i, int k, vector<int> &arr)
{
  int n = arr.size();
  if (i >= n)
    return 0;

  int ans = 0;
  int maxi = 0;
  for (int len = 1; len <= k && i + len - 1 < n; len++)
  {
    maxi = max(maxi, arr[i + len - 1]);
    int sum = len * maxi + f(i + len, k, arr);

    ans = max(ans, sum);
  }

  return ans;
}

int f1(int i, int k, vector<int> &arr, vector<int> &dp)
{
  int n = arr.size();

  if (i == n)
    return 0;

  if (dp[i] != -1)
    return dp[i];

  int ans = 0;
  int maxi = 0;

  for (int len = 1; len <= k && i + len - 1 < n; len++)
  {

    maxi = max(maxi, arr[i + len - 1]);

    ans = max(ans,
              len * maxi + f1(i + len, k, arr, dp));
  }

  return dp[i] = ans;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  vector<int> dp(n+1, 0);

  for (int i = n - 1; i >= 0; i--)
  {
    int ans = 0;
    int maxi = 0;

    for (int len = 1; len <= k && i + len - 1 < n; len++)
    {

      maxi = max(maxi, arr[i + len - 1]);

      ans = max(ans,len * maxi + dp[i + len]);
    }
    dp[i] = ans;
  }
  cout << dp[0] << endl;
}