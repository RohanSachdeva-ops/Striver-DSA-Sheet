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

node* reverseDLL1(node* head){
  node* temp=head;
  stack<int> st;
  while(temp){
    int el=temp->data;
    st.push(el);

    temp=temp->next;
  }

  
  temp=head;
  while(temp){
    temp->data=st.top();
    st.pop();
    
    temp=temp->next;
  }
  return head;
}

node* reverseDLL2(node* head){

  if(head==NULL || head->next==NULL){
    return head;
  }

  node* temp=head;
  node* last=NULL;
  while(temp){
    last=temp->back;
    temp->back=temp->next;
    temp->next=last;
    temp=temp->back;
  }

  return last->back;
}


int main(){
  vector<int> arr = {5,4,3,2,1};
  node* head = convertArrToDLL(arr);
  head=reverseDLL2(head);
  printDLL(head);
}