#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve()
{
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int mini = min(h, l);
    int maxi = max(h, l);

    int n1 = 0, n2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] <= mini)
        {
            n1++;
        }
        else if (v[i] <= maxi)
        {
            n2++;
        }
    }

    if(n2>=n1){
        cout << n1 << endl;
    }else {
        cout << (n2)+((n1-n2)/2) << endl;
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