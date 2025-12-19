#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& v,int i,int n){
if(i>=n/2){
  return;
}

swap(v[i],v[n-1-i]);
reverse(v, i+1, n);
}

int main() {
 int n;cin>>n;
 vector<int> v(n);
 for (int i = 0; i < n; i++) {
     cin >> v[i];
 }

reverse(v,0,n);
for(auto x:v){
  cout<<x<<" ";
}
}