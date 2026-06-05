#include <bits/stdc++.h>
using namespace std;

vector<int> a(1e5),seg(1e7);

void build(int ind, int low, int high){
  if(low == high){
    seg[ind] = a[low];
    return;
  }

  int mid = low + (high-low)/2;
  build(2*ind + 1,low,mid);
  build(2*ind+2 , mid+1,high);
  seg[ind] = (seg[2*ind+1]+seg[2*ind+2]);
}
int query(int ind,int low,int high,int l,int r){
  if(high < l || low > r){
    return 0;
  }

  if(low>=l && high<=r){
    return seg[ind];
  }

  int mid = low + (high-low)/2;
  int left = query(2*ind+1,low,mid,l,r);
  int right = query(2*ind+2,mid+1,high,l,r);
  return left+right;
}
void update(int ind,int low,int high,int i,int val){
  if(low == high){
    seg[ind] = val;
    return;
  }
  int mid = low + (high-low)/2;
  if(i <= mid) update(2*ind+1,low,mid,i,val);
  else update(2*ind+2,mid+1,high,i,val);

  seg[ind] = (seg[2*ind+1]+seg[2*ind+2]);
}



int main() {
     int n;cin>>n;
     for (int i = 0; i < n; i++) {
         cin >> a[i];
     }

     build(0,0,n-1);
     cout << query(0,0,n-1,0,4) << endl;
     update(0,0,n-1,0,10);
     cout << query(0,0,n-1,0,4) << endl;
}