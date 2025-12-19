#include <bits/stdc++.h>
using namespace std;

class node{
  public:
  int data;
  node* next;

  public:
  node(int data1, node* next1){
    data=data1;
    next=next1;
  }

  public:
  node(int data1){
    data=data1;
    next=nullptr;
  }
};

node* convertArr2LL(vector<int>& arr){
  node* head = new node(arr[0]);
  node* mover = head;

  for(int i=1;i<arr.size();i++){
    node* temp = new node(arr[i]);
    mover->next =temp;
    mover = temp;
  }

  return head;
}

int LenOfLL(node* head){
  int counter=0;
  node* temp = head;
  while(temp){
    temp = temp->next;
    counter++;
  }
  return counter;
}

int searchOfElement(node* head, int value){
  node* temp = head;
  while(temp){
    if(temp->data == value) return 1;
    temp = temp->next;
  }
  return 0;
}

int main() {
    vector<int> arr = {11,2,3,4,5};
    node* head = convertArr2LL(arr);
    
    cout<<searchOfElement(head, 21);
    return 0;
}