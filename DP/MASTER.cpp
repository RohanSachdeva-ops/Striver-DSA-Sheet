#include <bits/stdc++.h>
using namespace std;

/*
int main() {
    //Jumps - Min Effort
    int n;cin>>n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);
    for(int i=2;i<n;i++){
      dp[i] = min(abs(h[i-1]-h[i]) + dp[i-1],abs(h[i-2]-h[i]) + dp[i-2]);
    }

    cout << dp[n-1] << endl;
}
*/

/*
int main(){
  int n,k;cin>>n>>k;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  vector<int> dp(n+1);
  dp[0] = 0;
  // min effort to come from 0th to ith index
  for(int i=0;i<n;i++){
    int minEffort = INT_MAX;
    for(int j=1;j<=k;i++){
      if(i-j>=0) minEffort = min(minEffort, dp[i-j] +  abs(h[i]-h[i-j]));
    }
    dp[i] = minEffort;
  }

    cout << dp[n-1] << endl;
}
*/

/*
int main(){
      int n;cin>>n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> dp(n+1);

    // Bottom - Up
    dp[0] = h[0];
    dp[1] = max(h[0],h[1]);
    for(int i=1;i<n;i++){
      int take = INT_MIN;
      take = (h[i]+dp[i-2]);

      int nottake = dp[i-1];
      dp[i] = max(take,nottake);
    }

    //Top - Down

  }
  */

/*
    int maximumPoints(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>> dp(n,vector<int> (3,0));
        // Base case
        for(int j = 0; j < 3; j++) {
            dp[0][j] = mat[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=2;j++){
                int maxi = -1;
                for(int k=0;k<=2;k++){
                    if(k!=j) maxi = max(maxi,dp[i-1][k]);
                }

                dp[i][j]=maxi+mat[i][j];
            }
        }
        int ans = max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
        return ans;
    }
*/

// SubsetSum
//  1D - DP

/*
int main(){
  int n,target;cin>>n>>target;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }
  vector<int> dp(target+1,0);
  dp[0]=1;
  for(auto x:v){
    for(int i = target;i>=x;i--){
      dp[i] = dp[i] | dp[i-x];
    }
  }
  cout << dp[target];
}
  */

/*
int main(){
  int n,target;cin>>n>>target;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }
  vector<vector<int>> dp(n,vector<int> (target+1,0));

  //Base Condition
  if(v[0]<=target) dp[0][v[0]] = 1;
  for(int i=0;i<n;i++) dp[i][0]=1;

  //REPETION NOT ALLOWED
  for(int i=1;i<n;i++){
    for(int s=0;s<=target;s++){
      dp[i][s] = dp[i - 1][s];
      if(s-v[i]>=0) dp[i][s] = dp[i][s] || dp[i - 1][s-v[i]];
    }
  }

  cout << dp[n-1][target];
}
*/

/*
int main(){
  int n,target;cin>>n>>target;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }
  vector<vector<int>> dp(n,vector<int> (target+1,0));

  //Base Condition
  for(int s=v[0];s<=target;s+=v[0]) dp[0][s]=1;
  for(int i=0;i<n;i++) dp[i][0]=1;
  //REPETION NOT ALLOWED
  for(int i=1;i<n;i++){
    for(int s=0;s<=target;s++){
      dp[i][s] = dp[i - 1][s];
      if(s-v[i]>=0) dp[i][s] = dp[i][s] || dp[i - 1][s-v[i]];
    }
  }

  cout << dp[n-1][target];
}
*/

/*
int main(){
  int n,target;cin>>n>>target;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }
  vector<vector<int>> dp(n+1,vector<int> (target+1,0));

  //base
  if(v[0]<=target) dp[0][v[0]] = 1;
  for(int i=0;i<n;i++) dp[i][0]=1;

  for(int i=1;i<n;i++){
    for(int s=0;s<=target;s++){
      //take
      if(s-v[i]>=0) dp[i][s] += dp[i-1][s-v[i]];

      //nottake
      dp[i][s] += dp[i-1][s];
    }
  }

  cout << dp[n-1][target];
}
*/

int main()
{
  int n, target;
  cin >> n >> target;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  int sum = (accumulate(v.begin(), v.end(), 0));

  if(target > sum){
    cout << 0;
    return 0;
  }

  vector<vector<int>> dp(n+1, vector<int>(2 * sum + 1, 0));

  dp[0][sum - v[0]]++;
  dp[0][sum + v[0]]++;

  for (int i = 1; i < n; i++)
  {
    for (int s = 0; s <= 2 * sum; s++)
    {
      // minus
      if (s - v[i] >= 0)
        dp[i][s] += dp[i - 1][s - v[i]];

      // add
      if (s + v[i] <= 2 * sum)
        dp[i][s] += dp[i - 1][s + v[i]];
    }
  }

  cout << dp[n - 1][target + sum];
}
