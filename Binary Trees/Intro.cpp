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
  node(int val,node* left1, node* right1){
    data=val;
    left=left1;
    right=right1;
  }
};

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->right = new node(5);

    /*
            1--3
            |
            2--5

    */
}