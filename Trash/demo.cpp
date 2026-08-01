#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;cin>>n;
    vector<int> inventory(n);
    for(int i=0;i<n;i++) cin>>inventory[i];

    int high = *(max_element(inventory.begin(),inventory.end()));
    int low = 0;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(check(mid,inventory)){

        }else{

        }
    }
}