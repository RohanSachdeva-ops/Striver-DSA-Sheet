#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    long long ans = 0;
    for (long long b = 1; b <= n; ++b) {
        long long m = n / b;
        ans += m * m;
    }
    
    cout << ans << endl;
}

int main() {
    // Optimize standard I/O operations for performance
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