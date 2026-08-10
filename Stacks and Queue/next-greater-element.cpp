#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }
  
  stack<int> st;
  unordered_map<int,int> ngeMap;
  for(int i=0;i<n;i++){
    while((!st.empty())&&(v[st.top()]<v[i])){
      ngeMap[st.top()] = v[i];
      st.pop();
    }
    st.push(i);
  }

  for(int i=0;i<n;i++){
    if(ngeMap.find(i)!=ngeMap.end()){
      cout << ngeMap[i] << " ";
    }else{
      cout << -1 << " ";
    }
  }
}