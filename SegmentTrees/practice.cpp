//Range Updates 
// (L,R) - > +val

//procedure
// 1. update the node when you visit it
// 2. once you update propagate the update downwards

//rules(firstly update the previous updates then follow further operations)
//case 1 : Check if the node completely overlaps with (l,r)
// -->Update the node, lazy propogate down and return

//case 2 : Check if the node partially overlaps
// --> left , right ,update

//case 3 : Check if the node has no overlap 
// --> return

#include <bits/stdc++.h>
using namespace std;
class segTree{
  public:
  vector<int> seg,lazy;

  segTree(int n){
    seg.resize(4*n+1,0);
    lazy.resize(4*n+1,0);
  }

  void build(int ind,int low,int high,vector<int>& arr){
    if(low == high){
      seg[ind] = arr[low];
      return;
    }
    int mid = low + (high-low)/2;
    build(2*ind+1,low,mid,arr);
    build(2*ind+2,mid+1,high,arr);
    seg[ind] = seg[2*ind+1]+seg[2*ind+2];
  }

  void updateInRange(int ind,int low,int high,int l,int r){
    if(lazy[ind] != 0){
      //update the previous remaining updates for the reminaning nodes to get updated 
      // seg[ind] += (high-low+1)*lazy[ind];

      if(lazy[ind]&1) seg[ind] = (high-low+1) - seg[ind];

      if(low != high){
        //propogate the lazy update downwards for the remaining nodes
        lazy[2*ind+1] += lazy[ind];
        lazy[2*ind+2] += lazy[ind];
      }
      lazy[ind]=0;
    }

    // l low high r
    if(l<=low && high<=r){
      seg[ind] = (high-low+1) - seg[ind];
      if(low != high){
        lazy[2*ind+1] += 1;
        lazy[2*ind+2] += 1;
      }
      return;
    }

    //low high l r , l r low high
    if(high < l || r < low){
      return;
    }

    int mid = low + (high-low)/2;
    updateInRange(2*ind+1,low,mid,l,r);
    updateInRange(2*ind+2,mid+1,high,l,r);
    seg[ind] = seg[2*ind+1]+seg[2*ind+2];
  }


  public:
  int query(int ind,int low,int high,int l,int r){
    if(lazy[ind] != 0){
      
      if(lazy[ind]&1) seg[ind] = !seg[ind];

      if(low != high){
        lazy[2*ind+1] += lazy[ind];
        lazy[2*ind+2] += lazy[ind];
      }
      lazy[ind]=0;
    }

      // low high l r | l r low high
      if(high < l || r < low){
        return 0;
      }

      // l low high r
      if(low >= l && high <= r){
        return seg[ind];
      }

      int mid = low + (high-low)/2;
      int left = query(2*ind+1,low,mid,l,r);
      int right = query(2*ind+2,mid+1,high,l,r);

      return left + right;
  }
};

//QUERY
// --> if previous update is available do it & propogate down
// --> complete overlap - return seg[ind]
// --> no overlap - return 0
// --> partial overlap --> return (left + right)



int main() {
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    segTree sg1(n);
    sg1.build(0,0,n-1,arr);

    int q;cin>>q;
    while(q--){
      int l,r;cin>>l>>r;
      cout << (sg1.query(0,0,n-1,l,r)) << endl;
      sg1.updateInRange(0,0,n-1,0,4);
      cout << (sg1.query(0,0,n-1,l,r)) << endl;
    }
}