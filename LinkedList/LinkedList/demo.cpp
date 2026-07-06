#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int d, Node* n){
    data=d;
    next=n;
  }
  Node(int d){
    data=d;
    next=nullptr;
  }

};

Node* convertArr2LL(vector<int> v){
  Node* head = new Node(v[0]);
  Node* mover = head;

  for(int i=1;i<v.size();i++){
    Node* temp = new Node(v[i]);
    // mover->next = temp;
    mover=temp; 
  }

  return head;
}

int main(){
  vector<int> v={1,2,3,4,5};
  Node* head = convertArr2LL(v);
  cout<<head->data<<endl;
}