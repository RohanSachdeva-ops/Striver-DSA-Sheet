#include <bits/stdc++.h>
using namespace std;

int LIS(int ind, int prev_ind, vector<int> &v, vector<vector<int>> &dp)
{
  int n = v.size();

  if (ind == n)
    return 0;

  if (dp[ind][prev_ind + 1] != -1)
    return dp[ind][prev_ind + 1];

  int not_take = LIS(ind + 1, prev_ind, v, dp);
  int take = 0;
  if (prev_ind == -1 || v[ind] > v[prev_ind])
    take = 1 + LIS(ind + 1, ind, v, dp);

  return dp[ind][prev_ind + 1] = max(not_take, take);
}

void LIS_tabulation()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
    {
      int not_take = dp[ind + 1][prev_ind + 1];
      int take = 0;
      if ((prev_ind == -1) || (v[ind] > v[prev_ind]))
        take = 1 + dp[ind + 1][ind + 1];

      dp[ind][prev_ind + 1] = max(take, not_take);
    }
  }

  // LIS(0, -1, v, dp);
  cout << dp[0][0];
}

// TC->O(N^2)
// SC->O(N)
void LIS_intuition_method()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  vector<int> dp(n, 1);
  // dp[i] signifies the longest LIS that ends that at index i
  //  ans = max(dp[i]) (0<=i<=n-1)

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (v[j] < v[i])
      {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int maxi = 0;
  for (int i = 0; i < n; i++)
    maxi = max(maxi, dp[i]);
  cout << maxi;
}

// Printing LIS - we use intuition method
// TC->O(N^2)
// SC->O(N)
void PrintingLIS()
{

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  vector<int> dp(n, 1);
  vector<int> hash(n);
  for (int i = 0; i < n; i++)
    hash[i] = i;
  int lastIndex = -1;

  // dp[i] -> max lis ending at index i
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (v[j] < v[i])
      {
        if (dp[i] < dp[j] + 1)
        {
          dp[i] = dp[j] + 1;
          hash[i] = j;
        }
      }
    }
  }
  int maxi = -1;

  for (int i = 0; i < n; i++)
  {
    if (dp[i] > maxi)
    {
      maxi = max(maxi, dp[i]);
      lastIndex = i;
    }
  }

  vector<int> lis(maxi);
  lis[0] = v[lastIndex];
  int ind = 1;
  while (hash[lastIndex] != lastIndex)
  {
    lastIndex = hash[lastIndex];
    lis[ind] = v[lastIndex];
    ind++;
  }

  reverse(lis.begin(), lis.end());
  for (auto x : lis)
    cout << x << " ";
}

// LIS using Binary Search
//  the final array is not the answer it is just the simulation

// TC - O(NlogN)
// SC - O(N)
void LIS_using_binary_search()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  vector<int> temp;
  temp.push_back(v[0]);
  for (int i = 1; i < n; i++)
  {
    if (v[i] <= v.back())
    {
      int ind = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
      v[ind] = v[i];
    }
    else
    {
      temp.push_back(v[i]);
    }
  }
  cout << temp.size();
}

void numberOfLIS()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  vector<int> dp(n, 1), cnt(n, 1);
  int maxi = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (v[j] < v[i])
      {
        if (dp[j] + 1 > dp[i])
        {
          dp[i] = dp[j] + 1;
          cnt[i] = cnt[j];
        }
        else if (dp[j] + 1 == dp[i])
        {
          cnt[i] += cnt[j];
        }
      }
    }

    maxi = max(maxi, dp[i]);
  }

  int max_number = 0;
  for (int i = 0; i < n; i++)
  {
    if (dp[i] == maxi)
    {
      max_number += cnt[i];
    }
  }

  cout << max_number << endl;
}
