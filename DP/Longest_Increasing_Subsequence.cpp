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

int main()
{

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  vector<int> dp(n);
  //dp[i] signifies the longest LIS that ends that at index i
  // ans = max(dp[i]) (0<=i<=n-1)

  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      if(v[j]<v[i]){
        dp[i]=max(dp[i], dp[j]+1);
      }
    }
  }
  int maxi = 0;
  for(int i=0;i<n;i++) maxi = max(maxi, dp[i]);
  return maxi;  

}