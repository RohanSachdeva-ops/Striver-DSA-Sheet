#include<bits/stdc++.h>
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
};
node* buildTree(node* root){
  // cout<<"Enter the data: "<<endl;
  int data;cin>>data;
  root = new node(data);

  if(data==-1){
    return NULL;
  }

  // cout<<"Enter the data left side of "<<data<<endl;
  root->left = buildTree(root->left);
  // cout<<"Enter the data right side of "<<data<<endl;
  root->right = buildTree(root->right);
  return root;

}


//  TRAVERSAL IN BINARY TREES
//By recursion
void preOrder(node* root){
  if(root == NULL) return;

  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}
//by stack
void preOrder2(node* root){
  vector<int> preorder;
  if(root==NULL) return;

  stack<node*> st;
  st.push(root);

  while(!st.empty()){
    node* top = st.top();
    st.pop();
    preorder.push_back(top->data);
    if(top->right != NULL) st.push(top->right);
    if(top->left != NULL) st.push(top->left);    
  }
  for(auto x:preorder){
    cout<<x<<" ";
  }
}

//by recursion
void postOrder(node* root){
  if(root==NULL) return;

  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" "; 
}
//by 2 stacks
void postOrder2(node* root){
  vector<int> postorder;
  if(root==NULL) return;

  stack<node*> st1,st2;
  st1.push(root);

  while(!st1.empty()){
    root = st1.top();
    st1.pop();
    st2.push(root);

    if(root->left != NULL)st1.push(root->left);
    if(root->right != NULL)st1.push(root->right);
  }
  while(!st2.empty()){
    node* top = st2.top();
    st2.pop();
    postorder.push_back(top->data);
  }

  for(auto x:postorder){
    cout<<x<<" ";
  }
}
//BY 1 stack
void postOrder3(node* root){
  if(root==NULL) return;

  vector<int> postorder;
  node* curr=root;
  stack<node*> st;
  while(curr!=NULL || !st.empty()){
    if(curr != NULL){
      st.push(curr);
      curr=curr->left;
    }else{
      node* temp=st.top()->right;
      if(temp==NULL){
        temp=st.top();
        st.pop();
        postorder.push_back(temp->data);

        while(!st.empty() && temp==st.top()->right){
          temp=st.top();st.pop();
          postorder.push_back(temp->data);
        }
      }else{
        curr=temp;
      }
    }
    
  } 
  for(auto x:postorder){
    cout<<x<<" ";
  }
    
}


//by recursion
void inOrder(node* root){
  if(root==NULL) return;

  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}
//by stack
void inOrder2(node* root){
  vector<int> inorder;
  node* temp = root;
  stack<node*> st;
  while(true){
    if(temp !=NULL){
      st.push(temp);
      temp = temp->left;
    }
    else{
      if(st.empty()) break;
      node* top = st.top();
      st.pop();

      temp=top;
      inorder.push_back(top->data);
      temp = temp->right;
    }
  }

  for(auto x:inorder){
    cout<<x<<" ";
  }
}

//LEVEL ORDER PRINT
void levelOrder(node* root){
  vector<vector<int>> ans;
  if(root==NULL) return;

  queue<node*> q;
  q.push(root);
  
  while(!q.empty()){
    int size = q.size();
    vector<int> level;
    for(int i=0;i<size;i++){
      node* front=q.front();
      q.pop();

      if(front->left != NULL) q.push(front->left);
      if(front->right != NULL) q.push(front->right);
      level.push_back(front->data);
    }
    ans.push_back(level);
  }

  for(auto x:ans){
    for(auto e:x){
      cout<<e<<" ";
    }
  }
}

//ZIG-ZAG TRANSVERSAL
void zigZag(node* root){
  vector<vector<int>> zigzag;
  if(root == NULL) return; 
  
  bool LeftToRight = true;
  queue<node*> q;
  q.push(root);

  while(!q.empty()){
    int size=q.size();
    vector<int> v(size);
    for(int i=0;i<size;i++){
      node* front = q.front();
      q.pop();

      int index = (LeftToRight) ? i : size-1-i;
      v[index]=front->data;

      if(front->left!=NULL) q.push(front->left);
      if(front->right!=NULL) q.push(front->right);
    }
    LeftToRight = !LeftToRight;
    zigzag.push_back(v);
  }

  for(auto x:zigzag) for(auto e:x) cout<<e<<" ";
}

//SINGLE TRAVERSAL FOR ALL
void PreInPost(node* root){
  stack<pair<node*, int>> st;
  st.push({root,1});
  vector<int> pre,in,post;

  while(!st.empty()){
    auto it=st.top();
    st.pop();

    if(it.second == 1){
      pre.push_back(it.first->data);
      it.second++;
      st.push(it);

      if(it.first->left!=NULL){
        st.push({it.first->left, 1});
      }
    }

    else if(it.second == 2){
      in.push_back(it.first->data);
      it.second++;
      st.push(it);

      if(it.first->right != NULL){
        st.push({it.first->right, 1});
      }
    }

    else{
      post.push_back(it.first->data);
    }
  }

  for(auto x:pre) cout<<x<<" ";cout<<endl;
  for(auto x:in) cout<<x<<" ";cout<<endl;
  for(auto x:post) cout<<x<<" ";cout<<endl;
}

//SIMPLE CONCEPTUAL QUESTIONS
int MaxDepth(node* root){
  if(root==NULL) return 0;

  int lh=MaxDepth(root->left);
  int rh=MaxDepth(root->right);

  return 1+max(lh,rh);
}

//CHECKIING IF A TREE IS BALANCED OR NOT 
//1. NOT GOOD METHOD (O(N(SQUARED)))
bool check1(node* root){
  if(root==NULL) return true;

  int lh = MaxDepth(root->left);
  int rh = MaxDepth(root->right);

  if(abs(lh-rh)>1) return false;
  
  bool left = check1(root->left);
  bool right = check1(root->right);

  if(left==false || right==false) return false;
  
  return true;
}
//2. OPTIMAL VERSION
int f1(node* root){
  if(root==NULL) return 0;
  
  int lh = MaxDepth(root->left);
  if(lh==-1) return -1;
  int rh = MaxDepth(root->right);
  if(rh==-1) return -1;
  
  if(abs(lh-rh)>1) return -1;
  return 1+max(lh,rh);
}
bool check2(node* root){
  return (f1(root)!=-1);
}


//DIAMETER -- > MAX PATH LENGTH NOT NECESSARILY PASS THROUGH ROOT
//1. O(N(squared))
int maxi=INT_MIN;
int diameter1(node* root){
  if(root==NULL) return 0;
  
  int lh=MaxDepth(root->left);
  int rh=MaxDepth(root->right);

  maxi=max(maxi,lh+rh);
  diameter1(root->left);diameter1(root->right);
  return maxi;
}
//2.O(N)
int d1(node* root,int& diameter){
  if(root==NULL) return 0;
  int lh=MaxDepth(root->left);
  int rh=MaxDepth(root->right);

  diameter=max(diameter,lh+rh);
  return 1+max(lh,rh);
}
int diameter2(node* root){
  int diameter=0;
  d1(root,diameter);
  return diameter;
}


//MAXIMUM SUM PATH
int maxPathSum1(node* root, int& maxi){
  if(root==NULL) return 0;

  int lh = maxPathSum1(root->left,maxi);
  int rh = maxPathSum1(root->right,maxi);

  maxi=max(maxi, lh+rh+root->data);
  // return (root->data)+(max(lh,rh));
  if((root->data)+(max(lh,rh)) < 0) return 0;
  else return (root->data)+(max(lh,rh));
}
int maxSumPath(node* root){
  int maxi=INT_MIN;
  maxPathSum1(root, maxi);
  return maxi;
}

//SAME TREES OR NOT--->do any traversal and check whether it gives same result or not
bool isSame(node* p, node* q){
  if(p==NULL || q==NULL) return p==q;
  else return (p->data==q->data)  &&  (isSame(p->left, q->left))  &&  (isSame(p->right, q->right));
}

//Boundary Tranversal
bool isLeaf(node* root){
  return ((root->left==NULL) && (root->right == NULL));
}
void leaf(node* root,vector<int>& l){
  if(root==NULL) return;
  
  if(isLeaf(root)){
    l.push_back(root->data);
  }
    leaf(root->left,l);
    leaf(root->right,l);
}
void boundaryTranversal(node* root){
  vector<int> ans;ans.push_back(root->data);
  node* curr1 = root->left;
  while(curr1!=NULL){
    if(isLeaf(curr1) == false) ans.push_back(curr1->data);
    
    if(curr1->left == NULL) curr1 = curr1->right;
    else curr1 = curr1->left;
  }

  node* curr2 = root->right;stack<int> st;
  while(curr2 != NULL){
    if(isLeaf(curr2) ==false) st.push(curr2->data);
    
    if(curr2->right == NULL) curr2 = curr2->left;
    else curr2 = curr2->right;
  }


  vector<int> l;leaf(root,l);
  for(int i=0;i<l.size();i++){
    ans.push_back(l[i]);
  }

  while(st.empty() == false){
    int top=st.top();st.pop();
    ans.push_back(top);
  }

  for(auto x:ans) cout<<x<<" ";

}
                                

bool cmp(pair<int, pair<int,int>>a , pair<int,pair<int,int>>b){

  if(a.second != b.second){
    if(a.second.second != b.second.second){
      return a.second.second < b.second.second;
    }else{
      return a.second.first < a.second.first;
    }
  }else{
    return a.first<b.first;
  }
}
void verticalTransversal(node* root){
  vector<pair<int, pair<int,int>>> v;
  queue<pair<node*, pair<int,int>>> q;
  q.push({root,{0,0}});
  
  while(!q.empty()){
    auto p = q.front();
    q.pop();
    node* curr=p.first;
    auto x = p.second.first, y=p.second.second;
    v.push_back({curr->data,{x, y}});

    if(curr->left!=NULL) q.push({curr->left, {x + 1, y - 1}});
    if(curr->right!=NULL) q.push({curr->right, {x + 1, y + 1}});
  }

  sort(v.begin(),v.end(),cmp);
  for(auto x:v){
    cout<<x.first<<","<<"{"<<x.second.first<<","<<x.second.second<<"}"<<endl;
  }
}

bool topView_comparator(pair<int, pair<int,int>>a , pair<int,pair<int,int>>b){

  if(a.second != b.second){
    if(a.second.second != b.second.second){
      return a.second.second < b.second.second;
    }else{
      return a.second.first < a.second.first;
    }
  }else{
    return a.first<b.first;
  }
}
void TopView(node* root){
  vector<pair<int, pair<int,int>>> v;
  queue<pair<node*, pair<int,int>>> q;
  q.push({root,{0,0}});
  
  while(!q.empty()){
    auto p = q.front();
    q.pop();
    node* curr=p.first;
    auto x = p.second.first, y=p.second.second;
    v.push_back({curr->data,{x, y}});

    if(curr->left!=NULL) q.push({curr->left, {x + 1, y - 1}});
    if(curr->right!=NULL) q.push({curr->right, {x + 1, y + 1}});
  }

  sort(v.begin(),v.end(),topView_comparator);
  int prev_y = INT_MIN;
  for(auto &x:v){
    // cout<<x.first<<","<<"{"<<x.second.first<<","<<x.second.second<<"}"<<endl;
    auto n = x.first;
    auto xc=x.second.first, yc=x.second.second;

    if(yc != prev_y) {
      cout<<n<<endl;
      prev_y = yc;
    }
  }
}

void TopView2(node* root){
  vector<int> ans;
  if(root==NULL) return;
  queue<pair<node*, int>> q;
  map<int,int> mpp;
  q.push({root,0});

  while(!q.empty()){
    auto it=q.front();q.pop();

    if(mpp.find(it.second) == mpp.end()) mpp[it.second] = it.first->data;
    
    node* curr=it.first;
    if(curr->left) q.push({curr->left,it.second-1});
    if(curr->right) q.push({curr->right,it.second+1});
  }
  for(auto it:mpp){
    cout<<it.second<<" ";
  }
}

bool rightView_comparator(pair<int, pair<int,int>>a , pair<int,pair<int,int>>b){

  if(a.second != b.second){
    if(a.second.first != b.second.first){
      return a.second.first<b.second.first;
    }else{
      return a.second.second>b.second.second;
    }
  }else{
    return a.first<b.first;
  }
}
void rightView(node* root){
  vector<pair<int, pair<int,int>>> v;
  queue<pair<node*, pair<int,int>>> q;
  q.push({root,{0,0}});
  
  while(!q.empty()){
    auto p = q.front();
    q.pop();
    node* curr=p.first;
    auto x = p.second.first, y=p.second.second;
    v.push_back({curr->data,{x, y}});

    if(curr->left!=NULL) q.push({curr->left, {x + 1, y - 1}});
    if(curr->right!=NULL) q.push({curr->right, {x + 1, y + 1}});
  }

  sort(v.begin(),v.end(),rightView_comparator);
  int prev_x = INT_MIN;
  for(auto &x:v){
    // cout<<x.first<<","<<"{"<<x.second.first<<","<<x.second.second<<"}"<<endl;
    auto n = x.first;
    auto xc=x.second.first, yc=x.second.second;

    if(xc != prev_x) {
      cout<<n<<endl;
      prev_x = xc;
    }
  }
}

void rightView2(node* root, int level,vector<int>& v){
  if(root == NULL) return;

  if(level == v.size()) v.push_back(root->data);
  rightView2(root->right, level+1,v); 
  rightView2(root->left, level+1,v); 
}
void rightViewPrinter(node* root){
  vector<int> v;
  rightView2(root,0,v);
  
  for(auto x:v) cout<<x<<"\n";
}

bool leftView_comparator(pair<int, pair<int,int>>a , pair<int,pair<int,int>>b){

  if(a.second != b.second){
    if(a.second.first != b.second.first){
      return a.second.first<b.second.first;
    }else{
      return a.second.second<b.second.second;
    }
  }else{
    return a.first<b.first;
  }
}
void leftView(node* root){
  vector<pair<int, pair<int,int>>> v;
  queue<pair<node*, pair<int,int>>> q;
  q.push({root,{0,0}});
  
  while(!q.empty()){
    auto p = q.front();
    q.pop();
    node* curr=p.first;
    auto x = p.second.first, y=p.second.second;
    v.push_back({curr->data,{x, y}});

    if(curr->left!=NULL) q.push({curr->left, {x + 1, y - 1}});
    if(curr->right!=NULL) q.push({curr->right, {x + 1, y + 1}});
  }

  sort(v.begin(),v.end(),leftView_comparator);
  int prev_x = INT_MIN;
  for(auto &x:v){
    // cout<<x.first<<","<<"{"<<x.second.first<<","<<x.second.second<<"}"<<endl;
    auto n = x.first;
    auto xc=x.second.first, yc=x.second.second;

    if(xc != prev_x) {
      cout<<n<<endl;
      prev_x = xc;
    }
  }
}


void leftView2(node* root, int level,vector<int>& v){
  if(root == NULL) return;

  if(level == v.size()) v.push_back(root->data);
  leftView2(root->left, level+1,v); 
  leftView2(root->right, level+1,v); 
}
void leftViewPrinter(node* root){
  vector<int> v;
  leftView2(root,0,v);
  
  for(auto x:v) cout<<x<<"\n";
}


int main(){
  node* root = buildTree(root);
  leftViewPrinter(root);
}