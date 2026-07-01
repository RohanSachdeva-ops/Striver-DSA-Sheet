#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
int spf[MAXN];
void sieve() {
    for (int i = 1; i < MAXN; i++) spf[i] = i;
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    
    int sum = 0;
    int dp = 0;
    
    while (n > 1) {
        int p = spf[n];
        int count = 0;
        while (n % p == 0) {
            count++;
            n /= p;
        }
        sum += count;
        dp++;
    }
    
    cout << sum + dp - 1 << "\n";
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}