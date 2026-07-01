#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n);
  map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    mpp[v[i]]++;
  }


  int maxi = 0;
  for (auto x : mpp)
  {
    maxi = max(maxi, x.second);
  }

  int ans = 0;
  for (int i = 1; i <= maxi; i++)
  {
    int temp = 0;
    for(auto x:mpp){
      if(x.second>= i){
        temp += i;
      }
    }
    ans = max(ans,temp);

  }
  cout << ans << endl;
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