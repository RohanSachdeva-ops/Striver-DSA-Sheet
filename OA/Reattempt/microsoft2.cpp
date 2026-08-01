#include <bits/stdc++.h>
using namespace std;

bool check(int k,vector<pair<int,int>> pp){
  int n = pp.size();
  for(int i=0;i<n;i++){
    if(k>=pp[i].first){
      k -= pp[i].second;
    }else{
      return false;
    }
  }
  return true;
}

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    long long bufferA = (long long)a.first - a.second;
    long long bufferB = (long long)b.first - b.second;
    
    // Sort descending by (worstCase - expected)
    if(bufferA != bufferB) {
        return bufferA > bufferB;
    }
    // Tie-breaker: sort by higher worstCase
    return a.first > b.first;
}

int main() {
    int n;cin>>n;
    vector<int> worstCase(n);
    for (int i = 0; i < n; i++) {
        cin >> worstCase[i];
    }
    vector<int> expected(n);
    for (int i = 0; i < n; i++) {
        cin >> expected[i];
    }

    vector<pair<int,int>> pp;
    for(int i=0;i<n;i++){
      pp.push_back({worstCase[i],expected[i]});
    }

    sort(pp.begin(),pp.end(),cmp);

    int ans = -1;
    int low = 0, high = 2e14;
    while(low <= high){
      int mid = low + (high-low)/2;
      if(check(mid,pp)){
        ans = mid;
        high=mid-1;
      }else{
        low = mid+1;
      }
    }

    cout << ans << endl;
}