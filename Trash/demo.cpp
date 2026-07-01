#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define pb push_back

void shiftOnePlace(int start,int end,vector<int>& arr){
    int temp = arr[start];
    for(int i=start;i<(end-start+1)-1;i++){
        arr[i] = arr[i+1];
    }
    arr[end] = temp;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    shiftOnePlace(0,2,arr);
    for(auto x:arr){
        cout << x <<" ";
    }
    
}