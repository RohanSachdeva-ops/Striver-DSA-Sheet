#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define endl '\n'

// Validates whether s has any matching elements at distance 2
bool checker(const string& s) {
    int n = s.size();
    for (int i = 0; i < n - 2; i++) {
        if (s[i] != '?' && s[i + 2] != '?' && s[i] == s[i + 2]) {
            return false;
        }
    }
    return true;
}

// Backtracking function to count valid full assignments of '?'
int countValidAssignments(string& str, int index) {
    int n = str.size();
    
    // Prune early if current state already violates the distance-2 condition
    if (index >= 2 && str[index - 1] != '?' && str[index - 3] != '?' && str[index - 1] == str[index - 3]) {
        return 0;
    }

    if (index == n) {
        return checker(str) ? 1 : 0;
    }

    if (str[index] != '?') {
        return countValidAssignments(str, index + 1);
    }

    int validCount = 0;
    // Try placing '0' and '1' at the current '?' position
    for (char ch : {'0', '1'}) {
        str[index] = ch;
        if (index < 2 || str[index] != str[index - 2]) {
            validCount += countValidAssignments(str, index + 1);
        }
    }
    str[index] = '?'; // Reset state (backtrack)

    return validCount;
}

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;

    // Check initial fixed string validity
    if (!checker(str)) {
        cout << 0 << endl;
        return;
    }

    cout << countValidAssignments(str, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}