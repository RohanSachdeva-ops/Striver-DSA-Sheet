#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'

void solve() {
    int n, m;
    ll v;
    cin >> n >> m >> v;

    // 1-based indexing for easier prefix/suffix boundary management
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // Prefix sum array (using ll to prevent overflow)
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + arr[i];
    }

    // pre[i] = max blocks formed from arr[1...i]
    vector<int> pre(n + 2, 0);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += arr[i];
        if (sum >= v) {
            pre[i] = pre[i - 1] + 1;
            sum = 0;
        } else {
            pre[i] = pre[i - 1];
        }
    }

    // suf[i] = max blocks formed from arr[i...n]
    vector<int> suf(n + 2, 0);
    sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += arr[i];
        if (sum >= v) {
            suf[i] = suf[i + 1] + 1;
            sum = 0;
        } else {
            suf[i] = suf[i + 1];
        }
    }

    // If total possible blocks across the whole array is less than m
    if (pre[n] < m) {
        cout << -1 << endl;
        return;
    }

    // Precompute the right-most starting index 'x' in the suffix that can provide 'k' blocks.
    // pos[k] stores the max index x where suf[x] >= k
    vector<int> pos(m + 1, -1);
    for (int i = 1; i <= n + 1; i++) {
        int k = min(suf[i], m);
        pos[k] = max(pos[k], i);
    }
    // Propagate the maximums downwards
    for (int k = m - 1; k >= 0; k--) {
        pos[k] = max(pos[k], pos[k + 1]);
    }

    ll maxi = 0;
    
    // Test every valid prefix length i (from 0 to n)
    for (int i = 0; i <= n; i++) {
        int req = max(0, m - pre[i]); // How many blocks we still need from the suffix
        int x = pos[req];             // Best starting index for the suffix
        
        // If a valid suffix exists and doesn't overlap with our prefix
        if (x != -1 && x > i) {
            // The removed subarray is strictly between i and x (i.e., arr[i+1 ... x-1])
            maxi = max(maxi, pref[x - 1] - pref[i]);
        }
    }

    cout << maxi << endl;
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}