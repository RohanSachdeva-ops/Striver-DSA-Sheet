#include <bits/stdc++.h>
using namespace std;


int main()
{
  string s;
  cin >> s;
  int n = s.size();

  vector<int> dp(n + 1, 0);
  dp[n] = 1;
  for (int i = n - 1; i >= 0; i--)
  {

    if(s[i]=='0'){
      dp[i]=0;
      continue;
    }

    if(s[i] <= '9' && s[i] >= '1'){
      dp[i] += dp[i+1];
    }

    if(i+2<=n && s[i]=='1'||(s[i]=='2' && s[i+1]<='6')){
      dp[i] += dp[i+2];
    }
  }
  cout << dp[0] << endl;
}