#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,l,k;cin>>n>>l>>k;
  vector<int> timestamps(n);
  for (int i = 0; i < n; i++) {
      cin >> timestamps[i];
  }

  vector<string> errorcodes(n);
  for (int i = 0; i < n; i++) {
      cin >> errorcodes[i];
  }
  
  int maxi = timestamps[n-1];
  int r = maxi - l;
  
  int it = lower_bound(timestamps.begin(),timestamps.end(),r) - timestamps.begin();   
  map<string,int> mp;
  for(int i=it;i<n;i++){
    mp[errorcodes[i]]++;
  }
  vector<string> ans;
  for(auto x:mp){
    if(x.second >= k) {
      ans.push_back(x.first);
    }
  }

  for(auto str:ans) cout << str << " ";
}