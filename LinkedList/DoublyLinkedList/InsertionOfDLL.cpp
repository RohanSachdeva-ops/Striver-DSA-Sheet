#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int data;
  node* next;
  node* back;

  public:
  node(int data1, node* next1, node* back1){
    data=data1;
    next=next1;
    back=back1;
  }

  public:
  node(int data1){
    data=data1;
    next=nullptr;
    back=nullptr;
  }
};

node* convertArrToDLL(vector<int>& arr){
  node* head = new node(arr[0]);
  node* prev = head;

    for(int i=1;i<arr.size();i++){
    node* temp = new node(arr[i], nullptr, prev);
    prev->next = temp;
    prev=temp;
    }
  
    return head;
}

void printDLL(node* head){
  node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

node* InsertBeforeHead(node* head, int value){
  node* newNode = new node(value, head, nullptr);
  head->back=newNode;

  return newNode;
}

node* InsertBeforeTail(node* head, int value){

  if(head->next == NULL){
    return InsertBeforeHead(head, value);
  }

  node* tail=head;
  while(tail->next != NULL){
    tail=tail->next;
  }
  node* prev = tail->back;
  node* newNode = new node(value, tail, prev);
  prev->next=newNode;
  tail->back=newNode;
  return head;
}

node* InsertBeforeKthElement(node* head, int value, int k){
  if(k==1){
    return InsertBeforeHead(head, value);
  }
  int cnt=0;
  node* temp = head;
  while(temp){
    cnt++;
    if(cnt==k) break;
    temp=temp->next;
  }

  node* prev = temp->back;
  node* front = temp->next;

  node* newNode = new node(value,front,prev);
  prev->next=newNode;
  front->back=newNode;
  return head;
}

void InsertBeforeNodde(node* temp,int value){
  node* prev = temp->back;

  node* newNode = new node(value, prev, temp);
  prev->next=newNode;
  return;
}

int main(){
  vector<int> arr = {5,4,3,2,1};
  node* head = convertArrToDLL(arr);
  head = InsertBeforeKthElement(head, 100 ,2);
  printDLL(head);
}