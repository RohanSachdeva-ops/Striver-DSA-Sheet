//maxCeil
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;cin>>n>>k;
  vector<int> v(n);\
  priority_queue<int> pq;
  for(int i=0;i<n;i++) 
  {
    cin>>v[i];
    pq.push(v[i]);
  }

  while(k--){
    int t = pq.top();pq.pop();
    t = (t+1)/2;
    pq.push(t);
  }

  int sum = 0;

  while(!pq.empty()){
    int t = pq.top();pq.pop();
    cout << t <<" ";
    sum += t;
  }
  cout << endl;

  cout << sum <<endl;
}