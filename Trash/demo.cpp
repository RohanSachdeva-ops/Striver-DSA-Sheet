#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void solve(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(k>0){
            int j = (i+1)%n;
            int count = 0;
            int sum = 0;
            while(count!=k){
                count++;
                sum+=v[j];
                j = (j+1)%n;
            }
            ans[i]=sum;
        }else if(k==0){
            continue;
        }else {
            int j = ((i-1)+n)%n;
            int count = 0;
            int sum = 0;
            while(count!=-k){
                count++;
                sum+=v[j];
                j = (j-1+n)%n;
            }
            ans[i]=sum;
        }
    }

    for(auto x:ans) cout << x << " ";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}