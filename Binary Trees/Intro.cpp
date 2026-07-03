#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* left;
  node* right;

  node(int val){
    data=val;
    left=NULL;
    right=NULL;
  }
  node(int val,node* left, node* right){
    data=val;
    left=left;
    right=right;
  }
};

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->right = new node(5);
}