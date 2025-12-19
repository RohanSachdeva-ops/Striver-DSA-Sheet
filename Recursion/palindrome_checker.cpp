#include <bits/stdc++.h>
using namespace std;

bool checkerString(string str,int i,int t){
  if(i>=t/2) return 1;
  if(str[i] != str[t-1-i]) return 0;
  return checkerString(str,i+1,t);
}

int main() {
    string str;cin>>str;
    int t=str.length();
    cout<<checkerString(str,0,t);
}