#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back


// void solve() {
//   int n,k;cin>>n>>k;
//   vector<int> v(n);
//   for (int i = 0; i < n; i++) {
//       cin >> v[i];
//   }

//   unordered_map<int,int> mpp; // prefixSum,count
//   mpp[0]=1;
//   int s=0;int count=0;
//   for(int i=0;i<n;i++){
//     s+=v[i];
//     if(mpp.find(s-k) != mpp.end()){
//         count += mpp[s-k];
//     }
//         mpp[s]++;
    
//   }
//   cout << count << endl;
// }


//Longest Subarray having sum k-----Method 1-----optimal if -ves are present 
void LongestSubarrayM1(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    map<int,int> mp;
    int s=0,len=0;
    for(int i=0;i<n;i++){
        s += v[i];//prefix sum
        if(mp.find(s) == mp.end()){ //if that sum is not present then add in hashmap--->insertions
            mp[s]=i;
        }



        if(s == k){
            len = max(len, i+1); //if sum comes then change 'len'----------->alteration
        }
        if(mp.find(s-k) != mp.end()){
            len = max(len,i-mp[s-k]); //if sum-k comes then change 'len'
        }

    }
    cout<<len<<endl;
}

//longest subarray having sum k but having non - negetive integers only
void LongestSubarrayM2(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int s=0,len=0,i=0,j=0;

    while(j<n){
        s+=v[j];
        if(s>k && i<j){
            s-=v[i];
            i++;
        }
        if(s==k){
            len=max(len,j-i+1);
        }
        j++;
    }
    cout<<len<<endl;
}

//Counting of subarray having sum equals k
void CountingSubarray(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    map<int,int> mp;
    mp[0]=1;
    
    int s=0,count=0;
    for(int i=0;i<n;i++){
        s+=v[i]; //prefix sum 
        if(mp.find(s-k) != mp.end()){ // if s-k present h toh count ko mp[s-k] se badhana +1 se nahi
            count+=mp[s-k];
        }
        mp[s]++; // count badhate rehna h
    }

    cout << count << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // LongestSubarrayM1();
    // LongestSubarrayM2();
    CountingSubarray();
    
    return 0;
}