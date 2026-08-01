#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;cin>>n>>k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }
  
  unordered_map<int,int> mpp;
  mpp[0]=1;
  int prefixSum = 0;
  int count = 0;
  for(int i=0;i<n;i++){
    prefixSum += v[i];
    int req = prefixSum - k;
    count += mpp[req];
    mpp[prefixSum]++;
  }
  cout << count << endl;
}