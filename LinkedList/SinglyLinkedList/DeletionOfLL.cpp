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

void printLL(node* head){
  node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

int searchOfElement(node* head, int value){
  node* temp = head;
  while(temp){
    if(temp->data == value) return 1;
    temp = temp->next;
  }
  return 0;
}

node* removeHead(node* head){
  if(head == NULL) return head;

  node* temp = head;
  head = head->next;
  delete temp; //free(temp)
  return head;
}

node* removeTail(node* head){
  if(head==NULL || head->next==NULL){
    return NULL;
  }

  node* temp = head;
  while(temp->next->next != NULL){
    temp = temp->next;
  }
  delete temp->next;//free(temp->next);
  temp->next = NULL;

  return head;
}

node* removeK(node* head, int k){
  if(head == NULL) return head;

  if(k==1){
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }

  int count=0;
  node* temp = head;
  node* prev = NULL;

  while(temp != NULL){
     count++;
     if(count == k){
      prev->next = prev->next->next;
      delete temp;
      break;
    }
     prev = temp;
     temp = temp->next;
  }
  return head;
}

node* removeElement(node* head, int el){
  if(head == NULL) return head;

  if(head->data == el){
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  node* temp = head;
  node* prev = NULL;

  while(temp != NULL){
     if(temp->data == el){
      prev->next = prev->next->next;
      delete temp;
      break;
    }
     prev = temp;
     temp = temp->next;
  }
  return head;
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


int main() {
    vector<int> arr = {1,2,3,6,5};
    node* head = convertArr2LL(arr);
    // head = removeTail(head);
    // head = removeHead(head);
    // head = removeK(head,2);
    // head = removeElement(head,6);
    // head = insertHead(head, 100);
    head = insertTail(head, 100);
    printLL(head);
    cout<<endl;

    return 0;
}