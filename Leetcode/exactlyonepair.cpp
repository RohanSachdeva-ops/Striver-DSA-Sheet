#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

bool f(int n)
{
  int temp = n;
  int prev = -1e9;
  int c = 0;
  for (int i = 0; i <= 30; i++)
  {
    if ((temp >> i) & 1)
    {
      if (i == prev + 1)
      {
        c++;
      }
      prev = i;
    }
  }
  if (c == 1)
  {
    return true;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << f(5) << endl;

  return 0;
}