#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int m = 0, c = 1;
    int count = 0;
    for (auto ch : str)
        if (ch == '#')
            count++;
    if (count == 0)
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if ((str[i] == '#') && (str[i] == str[i + 1]))
        {
            c++;
        }
        else
        {
            m = max(m, c);
            c = 1;
        }
    }
    if (m & 1)
    {
        cout << (m + 1) / 2 << endl;
    }
    else
    {
        cout << m / 2 << endl;
    }
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