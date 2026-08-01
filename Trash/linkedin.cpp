#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
  return a>b;
}

int main() {
    int n;cin>>n;
    vector<int> meet(n);
    for(int i=0;i<n;i++) cin>>meet[i];
    sort(meet.begin(),meet.end(),cmp);
    int c=0;
    int temp=0;
    for(int i=0;i<n;i++){
      temp += meet[i];
      if(temp<=0) break;
      else c++;
    }
    cout << c << endl;
}