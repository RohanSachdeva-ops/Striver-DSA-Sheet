#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    long long min_time = -1;
    bool possible1 = true;
    long long cost1 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            possible1 = false;
            break;
        }
        cost1 += (a[i] - b[i]);
    }
    vector<int> sorted_a = a;
    vector<int> sorted_b = b;
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());

    bool possible2 = true;
    long long cost2 = c;
    for (int i = 0; i < n; ++i) {
        if (sorted_a[i] < sorted_b[i]) {
            possible2 = false;
            break;
        }
        cost2 += (sorted_a[i] - sorted_b[i]);
    }

    // Determine the minimum valid time
    if (possible1 && possible2) {
        min_time = min(cost1, cost2);
    } else if (possible1) {
        min_time = cost1;
    } else if (possible2) {
        min_time = cost2;
    }

    cout << min_time << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}