#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;cin>>str;
    int n = str.size();
    unordered_map<char,int> mp;

    int left = 0;
    int maxi = 0;
    for(int right = 0;right < n; right++){
      if(mp.find(str[right]) != mp.end() && (mp[str[right]] >= left)){
        left = mp[str[right]] + 1;
      }
      mp[str[right]] = right;

      maxi = max(maxi, right - left + 1);
    }

    cout << maxi << endl;
}