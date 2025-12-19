#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////
void printVector(vector<int>& v){
  for(auto x:v)  cout<<x<<" ";
}

void merge(vector<int>& v,int low,int mid,int high){
  vector<int> temp;
  int left=low;
  int right=mid+1;
  while (left<=mid && right<=high){
    if(v[left]<=v[right]) temp.push_back(v[left++]);
    else temp.push_back(v[right++]);
  }

  while(left<=mid)  temp.push_back(v[left++]);
  while(right<=high) temp.push_back(v[right++]);
  
  for(int i=low;i<=high;i++) v[i]=temp[i-low];
}

void mergeSort(vector<int>& v,int low,int high){
  if(low>=high) return;

  int mid=(high+low)/2;
  mergeSort(v,low,mid);
  mergeSort(v,mid+1,high);
  merge(v,low,mid,high);

}
///////////////////////////////////
int converter(vector<int>& v,int low,int high){
  int pivot = v[low];
  int i=low,j=high;
  
  while(i<j){
    while(v[i]<=pivot && i<high) i++;
    while(v[j]>=pivot && i>low) j--;

    if(i<j) swap(v[i],v[j]);
  }
  swap(v[low], v[j]);
  return j;
}


void quickSort(vector<int>& v,int low,int high){
  if(low<high){
    int partitionIdx = converter(v,low,high);
    quickSort(v,low,partitionIdx-1);
    quickSort(v,partitionIdx+1,high);
  }
}


int main() {
    int n;cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
  // mergeSort(v,0,n-1);
  quickSort(v,0,n-1);
  printVector(v);
}