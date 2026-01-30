#include <bits/stdc++.h>
using namespace std;
int main() {
   int n,diff;cin>>n>>diff;
   vector<int> arr(n);
   for (int i = 0;i < n; i++) {
       cin >> arr[i];
    }
    int sum=accumulate(arr.begin(),arr.end(),0);

    if(sum<diff || (sum-diff)%2 !=0){
        cout<<0<<endl;
        return 0;
    }

    int target = (sum-diff)/2;

    vector<vector<int>> dp(n, vector<int> (target+1,0));
    if (arr[0] == 0) {
        dp[0][0] = 2;   // pick or not pick
    } else {
        dp[0][0] = 1;   // not pick
        if (arr[0] <= target)
            dp[0][arr[0]] = 1;  // pick
    }
    
    for(int i=1;i<n;i++){
        for(int k=0;k<=target;k++){
            int pick=0,notpick=0;
            notpick = dp[i-1][k];

            if(arr[i]<=k){
                pick = dp[i-1][k-arr[i]];
            }

            dp[i][k]=notpick+pick;
        }
    }

    cout<<dp[n-1][target]<<endl;
}
// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int s,vector<int>& arr,vector<vector<int>>& dp){
//     if(s==0) return 1;
//     if(i==0) return (arr[i]==s);

//     if(dp[i][s]!=-1) return dp[i][s];

//     int pick=0,notpick=0;
//     notpick=f(i-1, s, arr,dp);
//     if(arr[i]<=s){
//         pick = f(i-1,s-arr[i],arr,dp);
//     }

//     return dp[i][s]=pick+notpick;
// }

// int main() {
//    int n,target;cin>>n>>target;
//    vector<int> arr(n);
//    for (int i = 0;i < n; i++) {
//        cin >> arr[i];
//     }
//     vector<vector<int>> dp(n, vector<int> (target+1,-1));
//     cout<< f(n-1, target,arr,dp); 
// }

// //NUMBER OF SUBSEQUENCES HAVING SUM 'sum'
// #include <bits/stdc++.h>
// using namespace std;

// int sub(int i,vector<int>& v,int s,int sum,int n){
//     if(i==n){
//         if(s==sum) return 1;  
//         else return 0;
//     }

//   s+=v[i];
//   int l = sub(i+1,v,s,sum,n);
//   s-=v[i];
//   int r = sub(i+1,v,s,sum,n);

//   return l+r;
// }

// int main() {
//    int n,sum;cin>>n>>sum;
//    vector<int> v(n);
//    for (int i = 0;i < n; i++) {
//        cin >> v[i];
//    }
//    vector<int> final;
//    cout<<sub(0,v,0,sum,n);
// }



// #include<bits/stdc++.h>
// using namespace std;

// void printAllSubsequences(int i,int& count, int target, vector<int>& arr, vector<int>& ds){
//     int n=arr.size();
//     if(i==n){
//         if(s == target) count++;
//         return;
//     }

//     ds.push_back(arr[i]);
//     s+=arr[i];
//     printAllSubsequences(i+1,count,target, arr, ds);

//     ds.pop_back();
//     printAllSubsequences(i+1,count, target,arr,ds);

//     return;
// }


// int main(){
//     int n;cin>>n;
//     int target;cin>>target;
//     vector<int> arr(n);
//     vector<int> ds;
//     for(int i=0;i<n;i++) cin>>arr[i];
    
//     int ans=0;
//     printAllSubsequences(0,ans,target,arr,ds);
//     cout<<ans;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n; 
//     cin >> n;

//     vector<int> arr(2*n);
//     for(int i = 0; i < 2*n; i++) cin >> arr[i];

//     int posSum = 0, negSum = 0;
//     for(int x : arr){
//         if(x >= 0) posSum += x;
//         else negSum += abs(x);
//     }

//     int offset = negSum;
//     int range = posSum + negSum;

//     vector<bool> dp(range + 1, false);
//     dp[offset] = true;   // sum = 0

//     for(int x : arr){
//         vector<bool> next = dp;
//         for(int s = 0; s <= range; s++){
//             if(dp[s]){
//                 int ns = s + x;
//                 if(ns >= 0 && ns <= range)
//                     next[ns] = true;
//             }
//         }
//         dp = next;
//     }

//     int totalSum = accumulate(arr.begin(), arr.end(), 0);
//     int ans = INT_MAX;

//     for(int s = 0; s <= range; s++){
//         if(dp[s]){
//             int subsetSum = s - offset;
//             ans = min(ans, abs(totalSum - 2*subsetSum));
//         }
//     }

//     cout << ans;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n,k;cin>>n>>k;
//     vector<int> arr(n,0);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     // vector<vector<bool>> dp(n, vector<bool> (k+1,0));
//     vector<int> prev(k+1,0);
//     vector<int> current_row(k+1,0);
    
//     prev[0] = true; 
//     current_row[0]=true; 

//     if(arr[0] <= k)
//     prev[arr[0]] = true;

//     for(int idx=1;idx<n;idx++){
//         for(int target=1;target<=k;target++){
//             bool take = false;
//             if(arr[idx] <= target){
//                 take = prev[target-arr[idx]];
//             }

//             bool notTake = false;
//                 notTake = prev[target];
                
//                 current_row[target] = (take) || (notTake);
//             }
//             prev = current_row;
//     }

//     cout<<prev[k];
// }






// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n,k;cin>>n>>k;
//     vector<int> arr(n,0);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<vector<bool>> dp(n, vector<bool> (k+1,0));

//     for(int i=0;i<n;i++){
//         dp[i][0] = true;
//     }    
//     if(arr[0] <= k)
//         dp[0][arr[0]] = true;

//     for(int idx=1;idx<n;idx++){
//         for(int target=1;target<=k;target++){
//             bool take = false;
//             if(arr[idx] <= target){
//                 take = dp[idx-1][target-arr[idx]];
//             }

//             bool notTake = false;
//                 notTake = dp[idx-1][target];
                
//                 dp[idx][target] = (take) || (notTake);
//             }
//     }

//     cout<<dp[n-1][k];
// }

// #include<bits/stdc++.h>
// using namespace std;

// bool f(int idx, int target, vector<int>& arr,vector<vector<int>>& dp){
//     if(target==0) return true;
//     if(idx==0) return (arr[0]==target);

//     bool notTake = false;
//     bool take = false;

//     if(dp[idx][target] != -1) return dp[idx][target];
//     notTake = f(idx-1, target, arr,dp);

//     if(arr[idx] <= target){
//         take = f(idx-1, target-arr[idx], arr,dp);
//     }

//     return dp[idx][target] = notTake||take;
// }


// int main(){
//     int n,k;cin>>n>>k;
//     vector<int> arr(n,0);
//     vector<vector<int>> dp(n, vector<int> (k+1,-1));
//     for(int i=0;i<n;i++) cin>>arr[i];

//     cout<<(f(n-1, k, arr, dp));
// }


// #include<bits/stdc++.h>
// using namespace std;

// bool f(int idx, int target, vector<int>& arr){
//     if(target==0) return true;
//     if(idx==0) return (arr[0]==target);

//     bool notTake = false;
//     bool take = false;

//     notTake = f(idx-1, target, arr);

//     if(arr[idx] <= target){
//         take = f(idx-1, target-arr[idx], arr);
//     }

//     return notTake||take;
// }


// int main(){
//     int n,k;cin>>n>>k;
//     vector<int> arr(n,0);
//     for(int i=0;i<n;i++) cin>>arr[i];

//     cout<<(f(n-1, k, arr));
// }