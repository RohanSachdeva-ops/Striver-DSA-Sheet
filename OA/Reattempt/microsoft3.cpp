#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;cin>>n>>k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }
  
  int i = (lower_bound(v.begin(),v.end(),k) - v.begin());
  cout << i << endl;
}