// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   string originalString;cin>>originalString;
//   int n = originalString.size();

//   vector<char> min_char(n);
//   min_char[n-1] = originalString[n-1];

//   for(int i=n-2;i>=0;i--){
//     if(originalString[i] < min_char[i+1]) min_char[i] = originalString[i];
//     else min_char[i] = min_char[i+1]; 
//   } 

//   string temp = "";
//   string encrypt = "";
  
//   for(int i=0;i<n;i++){
//     temp.push_back(originalString[i]);
//     while(!temp.empty()){
//       if(i == n-1 || temp.back() <= min_char[i+1]){
//         encrypt.push_back(temp.back());
//         temp.pop_back();
//       }else{
//         break;
//       }
//     }
//   }

//   cout << encrypt << endl;
// }

#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;cin>>n>>k;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>b[i];

  vector<pair<int,int>> intervals(n);
  for(int i=0;i<n;i++){
    intervals[i] = {a[i],b[i]};
  }

  sort(intervals.begin(),intervals.end());

  vector<pair<int,int>> merged;
  merged.push_back(intervals[0]);
  
  for(int i=1;i<n;i++){
    if(merged.back().second >= intervals[i].first) {
      merged.back().second = max(merged.back().second, intervals[i].second);
    }else{
      merged.push_back(intervals[i]);
    }
  }

  int m = merged.size();
  int max_reduced = 0;
  int i = 0;
  for(int j=0;j<m;j++){
    while(merged[j].first - merged[i].second > k) {
        i++;
    }
    max_reduced = max(max_reduced, j - i);
  }

  cout << m - max_reduced << endl;
}