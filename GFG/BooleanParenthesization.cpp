#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

using vvv = vector<vector<vector<int>>>;

int f(int i, int j, string &s, bool isTrue, int n)
{
  if (i > j)
    return 0;
  if (i == j)
  {
    if (isTrue)
      return s[i] == 'T';
    else
      return s[i] == 'F';
  }

  int ways = 0;

  for (int ind = i + 1; ind <= j - 1; ind++){
    int leftTrue = f(i,ind-1,s,1,n);
    int leftFalse = f(i,ind-1,s,0,n);
    int rightTrue = f(ind+1,j,s,1,n);
    int rightFalse = f(ind+1,j,s,0,n);

    if(s[ind]=='&'){
      if(isTrue){
        ways += (leftTrue*rightTrue);
      }else{
        ways += (leftTrue*rightFalse) + (leftFalse*rightTrue) + (leftFalse*rightFalse);
      }
    }else if(s[ind]=='|'){
      if(isTrue){
        ways += (leftTrue*rightFalse) + (leftTrue*rightTrue) + (leftFalse*rightTrue);
      }else{
        ways += (leftFalse*rightFalse);
      }
    }else if(s[ind]=='^'){
      if(isTrue){
        ways += (leftTrue*rightFalse) + (leftFalse*rightTrue);
      }else{
        ways += (leftFalse*rightFalse) + (leftTrue*rightTrue);
      }
    }
  }

  return ways;
}
int f1(int i, int j, string &s, bool isTrue, int n,vvv& dp)
{
  if (i > j)
    return 0;
  if (i == j)
  {
    if (isTrue)
      return s[i] == 'T';
    else
      return s[i] == 'F';
  }

  if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];

  int ways = 0;

  for (int ind = i + 1; ind <= j - 1; ind+=2){
    int leftTrue = f1(i,ind-1,s,1,n,dp);
    int leftFalse = f1(i,ind-1,s,0,n,dp);
    int rightTrue = f1(ind+1,j,s,1,n,dp);
    int rightFalse = f1(ind+1,j,s,0,n,dp);

    if(s[ind]=='&'){
      if(isTrue){
        ways += (leftTrue*rightTrue);
      }else{
        ways += (leftTrue*rightFalse) + (leftFalse*rightTrue) + (leftFalse*rightFalse);
      }
    }else if(s[ind]=='|'){
      if(isTrue){
        ways += (leftTrue*rightFalse) + (leftTrue*rightTrue) + (leftFalse*rightTrue);
      }else{
        ways += (leftFalse*rightFalse);
      }
    }else if(s[ind]=='^'){
      if(isTrue){
        ways += (leftTrue*rightFalse) + (leftFalse*rightTrue);
      }else{
        ways += (leftFalse*rightFalse) + (leftTrue*rightTrue);
      }
    }
  }

  return dp[i][j][isTrue] = ways;
}

int main()
{
  string s;
  cin >> s;
  int n = s.size();

  vvv dp(n,vector<vector<int>> (n,vector<int> (2,-1)));

  // cout << f(0, n - 1, s, 1, n ) << endl;
  cout << f1(0, n - 1, s, 1, n ,dp) << endl;
}