#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void shiftOnePlace(int start, int end, vector<int> &arr)
{
  if (start >= end)
    return; // Safety check: nothing to shift

  int temp = arr[start];
  for (int i = start; i < end; i++)
  {
    arr[i] = arr[i + 1];
  }
  arr[end] = temp;
}

void solve()
{
  int n;
  cin >> n;
  string str;
  cin >> str;

  if ((str[0] == '0' && str[1] == '1') || (str[n - 1] == '0' && str[n - 2] == '1'))
  {
    cout << "NO\n";
    return;
  }

  for (int i = 1; i < n - 1; i++)
  {
    if ((str[i] == '0') && (str[i + 1] == str[i - 1]) && (str[i + 1] == '1'))
    {
      cout << "NO\n";
      return;
    }
  }

  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++)
  {
    ans[i] = i + 1;
  }

  int start = 0, end = -1;
  for (int i = 0; i < n; i++)
  {
    if (str[i] == '0')
    {
      start=i;
      end=i;

      while(end+1<n && str[end+1]=='0'){
        end++;
      }
      shiftOnePlace(start,end,ans);
      i = end;
    }
  }
  cout << "YES\n";
  for (auto x : ans)
  {
    cout << x << " ";
  }
  cout << endl;
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