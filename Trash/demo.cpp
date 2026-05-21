#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;cin>>str;
    int i;cin>>i;

    int l=0;string ans="";
    while (l < str.size())
    {
        if(l!=i) ans += str[l];
        l++;
    }
    cout<<ans<<endl;
    return 0;
}