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

node* removeHead(node* head){

  if(head==NULL || head->next==NULL){
    return NULL;
  }
  node* temp = head;
  head = head->next;
  head->back = nullptr;
  temp->next = nullptr;
  delete temp;
  return head;
}

node* removeTail(node* head){

  if(head==NULL || head->next==NULL){
    return NULL;
  }

  node* tail = head;
  while(tail->next!=NULL){
    tail=tail->next;
  }
  node* prev = tail->back;
  prev->next=nullptr;
  tail->back = nullptr;

  delete tail;
  return head;
}

node* removeKthElement(node* head, int k){
  if(head==NULL){
    return NULL;
  }
  node* temp = head;
  int cnt=0;
  while(temp){
    cnt++;
    if(cnt==k) break;
    temp=temp->next;
  }

  node* KNode = temp;
  node* prev = KNode->back;
  node* front = KNode->next;

  if(prev==NULL && front==NULL){
    return NULL;
  }
  else if(prev==NULL){
    return removeHead(head);
  }
  else if(front==NULL){
    return removeTail(head);
  }

  prev->next = front;
  front->back = prev;
  KNode->next==NULL;
  KNode->back==NULL;

  return head;  
}


void removeNode(node* temp){
  node* prev = temp->back;
  node* front = temp->next;

  if(front==NULL){
    prev->next=nullptr;
    temp->back=nullptr;
    free(temp);
    return;
  }

  prev->next=front;
  front->back=prev;

  temp->back = temp->next = nullptr;
  free(temp);
}


int main(){
  vector<int> arr = {5,4,3,2,1};
  node* head = convertArrToDLL(arr);
  // head = removeHead(head);
  // head = removeKthElement(head, 3);

  removeNode(head->next->next);
  printDLL(head);
}