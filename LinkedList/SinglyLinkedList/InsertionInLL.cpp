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

void printLL(node* head){
  node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

node* insertHead(node* head, int value){
  node* temp = new node(value, head);
  return temp;
}

node* insertTail(node* head, int value){
  if(head == NULL){
    return new node(value);
  }

  node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  node* newnode = new node(value);
  temp->next = newnode;

  return head;
}

node* insertk(node* head, int value, int k){
  if(head == NULL){
    return new node(value);
  }

  int count=0;
  node* temp = head;
  while (temp)
  {
    count++;
    if(count == k-1){
      node* x = new node(value, temp->next);
      temp->next = x;
    }
    temp = temp->next;
  }
  return head;
}


node* insertBeforeValue(node* head, int value, int el){
  if(head == NULL){
    return NULL;
  }

  if(head->data == el){
    return new node(value, head);
  }

  node* temp = head;
  while (temp->next)
  {
    if(temp->next->data = el){
      node* x = new node(value, temp->next);
      temp->next = x;
    }
    temp = temp->next;
  }
  return head;
}


int main() {
    vector<int> arr = {1,2,3,6,5};
    node* head = convertArr2LL(arr);
    // head = insertK(head, 100, 3);
    // head = insertBeforeValue(head, 100, 5);
    printLL(head);
    cout<<endl;

    return 0;
}