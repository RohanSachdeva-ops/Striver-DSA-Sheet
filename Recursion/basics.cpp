#include<bits/stdc++.h>
using namespace std;

void sum1(int i, int sum){
  if(i<1){
    cout<<sum<<endl;
    return;
  }
  sum1(i-1,sum+i);
}

int sum2(int i){
  if(i==0) return 0;
  return i+sum2(i-1);
}

void factorial1(int n,int b){
if(n<1){
  cout<<b<<endl;
  return;
}
  factorial1(n-1,b*n);
}

int factorial2(int n){
  if(n==0) return 1;
  return n*factorial2(n-1);
}

int main(){
  int n;cin>>n;

  sum1(n,0);
  cout<<sum2(n)<<endl;
  factorial1(n,1);
  cout<<factorial2(n)<<endl;
}