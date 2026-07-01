#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

long long minEnergy(int nb, int b, vector<vector<int>>& v) {
        int n = v.size();
        if(v.empty()) return 0;
        sort(v.begin(), v.end());
        long long total_time = 0;
        int current_start = v[0][0];
        int current_end = v[0][1];
        
        for (int i = 1; i < n; i++) {
            int st = v[i][0];
            int en = v[i][1];

            // l r L R
            if (current_end < st) {
                total_time += (current_end - current_start) + 1;
                current_start = st;
                current_end = en;
            } else {
                current_end = max(current_end,en);
            }
        }
        total_time += current_end-current_start+1;

        int temp = (b+2)/3;
        return (temp*total_time);
    }


int main() {
  vector<vector<int>> edges = {{6, 12}};
  cout << minEnergy(5,5,edges);
}