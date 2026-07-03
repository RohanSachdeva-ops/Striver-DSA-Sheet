#include <bits/stdc++.h>
using namespace std;

class node{
  public:
  int data; 
  node* left;
  node* right;

  public:
  node(int val){
    data=val;
    left=NULL;
    right=NULL;
  } 
  node(int val,node* l,node* r){
    data=val;
    left=l;
    right=r;
  }
};


node* buildtree(node* root){
  int data;cin>>data;
  root = new node(data);

  if(data==-1) return NULL;

  root->left = buildtree(root->left);
  root->right=buildtree(root->right);

  return root;
}

int maxPathSum(node* root, int& maxi){
  if(root == NULL) return 0;

  int lh = maxPathSum(root->left, maxi);
  int rh = maxPathSum(root->right, maxi);
  maxi = max(maxi, lh+rh+root->data);

  if((max(lh,rh)+(root->data)) < 0) return 0;
  else return max(lh,rh)+root->data;

}
int maxPathSumHelper(node* root){
  int maxi = INT_MIN;
  maxPathSum(root, maxi);
  return maxi;
}


int main() {
    node* root = NULL;
    root = buildtree(root);

    cout << maxPathSumHelper(root);
}