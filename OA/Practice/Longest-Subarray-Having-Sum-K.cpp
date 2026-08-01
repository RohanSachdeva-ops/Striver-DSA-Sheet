// // only positives
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   int n,k;cin>>n>>k;
//   vector<int> v(n);
//   for (int i = 0; i < n; i++) {
//       cin >> v[i];
//   }
  
//   int left = 0;
//   int right = 0;
//   int sum = v[0];
//   int maxi = -1;

//   while(right < n){
//     while(sum > k && left<=right){
//       sum -= v[left];
//       left++;
//     }

//     if(sum == k){
//       maxi = max(maxi,right-left+1);
//     }

//     right++;
//     if(right < n) sum += v[right];
//   }

//   cout << maxi << endl;
// }


// negetives + zeroes
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;cin>>n>>k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
      cin >> v[i];
  }
  
  unordered_map<int,int> mpp;
  int prefixSum = 0;
  int maxi = 0;
  for(int i=0;i<n;i++){
    prefixSum += v[i];
    int req = prefixSum - k;

    if(prefixSum == k){
      maxi = max(maxi, i+1);
    }

    if(mpp.find(req) != mpp.end()){
      maxi = max(maxi, (i-mpp[req]));
    }

    if(mpp.find(prefixSum) == mpp.end()){
      mpp[prefixSum] = i;
    }
  }

  cout << maxi << endl;
}