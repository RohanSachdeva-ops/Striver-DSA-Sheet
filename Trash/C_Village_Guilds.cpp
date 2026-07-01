#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<int> p(n + 1);
    vector<int> depth(n + 1, 0);
    vector<int> mx(n + 1, 0); 
    
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        depth[i] = depth[p[i]] + 1;
        mx[i] = depth[i]; 
    }
    
    vector<int> max1(n + 1, -1);
    vector<int> max2(n + 1, -1);
    
    for (int i = n; i >= 2; --i) {
        int u = p[i];
        int val = mx[i];
        
        mx[u] = max(mx[u], val);
        
        if (val > max1[u]) {
            max2[u] = max1[u];
            max1[u] = val;
        } else if (val > max2[u]) {
            max2[u] = val;
        }
    }
    
    long long ans = n; 
    
    for (int i = 1; i <= n; ++i) {
        if (max2[i] != -1 && max2[i] > depth[i]) {
            ans += (max2[i] - depth[i]);
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}