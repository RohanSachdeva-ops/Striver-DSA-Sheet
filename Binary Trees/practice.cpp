#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int val;
  node *left;
  node *right;

  node(int data1)
  {
    val = data1;
  }
  node(int data1, node *left1, node *right1)
  {
    val = data1;
    left = left1;
    right = right1;
  }
};

node *buildTree(node *root)
{
  int val;
  cin >> val;
  root = new node(val);

  if (val == -1)
    return NULL;

  root->left = buildTree(root->left);
  root->right = buildTree(root->right);

  return root;
}

int maxDepth(node *root)
{
  if (root == NULL)
    return 0;

  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);

  return max(lh, rh) + 1;
}

bool isBalanced1(node *root)
{
  if (root == NULL)
    return true;

  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);

  if (abs(lh - rh) > 1)
    return false;

  return isBalanced1(root->left) && isBalanced1(root->right);
}

int isBalanced2(node *root)
{
  if (root == NULL)
    return 0;

  int lh = isBalanced2(root->left);
  if (lh == -1)
    return -1;
  int rh = isBalanced2(root->right);
  if (rh == -1)
    return -1;

  if (abs(lh - rh) > 1)
    return -1;

  return max(lh, rh) + 1;
}

int isBalanced2Helper(node *root)
{
  return (isBalanced2(root) != -1);
}

int maxi = 0;
// diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
int diameter(node *root)
{
  if (root == NULL)
    return 0;

  int lh = diameter(root->left);
  int rh = diameter(root->right);

  maxi = max(lh + rh, maxi);

  return max(lh, rh) + 1;
}

int maxPathSum(node *root)
{
  if (root == NULL)
    return 0;

  int lh = maxPathSum(root->left);
  int rh = maxPathSum(root->right);

  maxi = max(maxi, lh + rh + root->val);
  return (max(lh, rh) + root->val) > 0 ? max(lh, rh) + root->val : 0;
}

bool isSame(node *p, node *q)
{
  if (p == NULL && q == NULL)
  {
    return true;
  }

  if (p == NULL || q == NULL)
  {
    return false;
  }

  if (p->val != q->val)
  {
    return false;
  }

  return isSame(p->left, q->left) &&
         isSame(p->right, q->right);
}

void level_order_traversal(node* root){
  if(root == NULL) return;
  vector<vector<int>> ans;

  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    int size = q.size();
    vector<int> one_level(size);
    for(int i=0;i<size;i++){
      auto temp = q.front();
      q.pop();

      one_level[i] = temp->val;

      if(temp->left != NULL) q.push(temp->left);
      if(temp->right != NULL) q.push(temp->right);
    }
    ans.push_back(one_level);
  }

  for(auto x:ans){
    for(auto e:x){
      cout << e << " ";
    }
  }
}

void zigzag_order_traversal(node* root){
  if(root == NULL) return;
  vector<vector<int>> ans;

  queue<node*> q;
  q.push(root);

  bool left_to_right = true;

  while(!q.empty()){
    int size = q.size();
    vector<int> one_level(size);
    for(int i=0;i<size;i++){
      auto temp = q.front();
      q.pop();

      int index = (left_to_right ? i : size-1-i);
      one_level[index] = temp->val;

      if(temp->left != NULL) q.push(temp->left);
      if(temp->right != NULL) q.push(temp->right);
    }
    ans.push_back(one_level);
    left_to_right = !left_to_right;
  }

  for(auto x:ans){
    for(auto e:x){
      cout << e << " ";
    }
  }
}

bool is_leaf(node* node){
  return (!(node->left) && !(node->right)) ? true : false;
}
void leaf_vector(node* root, vector<int>& leaves){
  if(!root) return;
  if(is_leaf(root)) leaves.push_back(root->val);
  leaf_vector(root->left,leaves);
  leaf_vector(root->right,leaves);
}
void boundary_traversal(node* root){

  if(!root) return;
  if(is_leaf(root)){
    cout << root->val;
    return;
  }

  vector<int> leaves;
  leaf_vector(root,leaves);
  vector<int> other_nodes;
  if(!root) return;
  if(!is_leaf(root)) other_nodes.push_back(root->val);

  node* node = root->left;
  while(node){
    if(!is_leaf(node)) other_nodes.push_back(node->val);
    if(node->left == NULL) node = node->right;
    else node = node->left;
  }

  stack<int> st;
  node = root->right;
  while(node){
    if(!(is_leaf(node))) st.push(node->val);
    if(node->right == NULL) node=node->left;
    else node=node->right;
  }


  vector<int> ans;
  for(auto x:other_nodes) ans.push_back(x);
  for(auto x:leaves) ans.push_back(x);
  while(!st.empty()) ans.push_back(st.top()),st.pop();

  for(auto x:ans) cout << x << " ";
}

void point_system(node* root,int row, int col,vector<pair<pair<int,int>,int>>& main){

  if(!root) return;
  main.push_back({{row,col},root->val});

  point_system(root->left,row+1,col-1,main);
  point_system(root->right,row+1,col+1,main);
}
bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
  if(a.first.second != b.first.second) return a.first.second < b.first.second;
  else if(a.first.first != b.first.first) return a.first.first < b.first.first;
  else return a.second < b.second;
}
void vertical_order_traversal(node* root){
    vector<pair<pair<int,int>,int>> main;
    point_system(root,0,0,main);

    sort(main.begin(),main.end(),cmp);

    vector<vector<int>> ans;
    vector<int> temp;
    temp.push_back(main[0].second);
    
}

//use level order traversal for vertical order traversal -->{
//push root with (0,0) in queue and then pop sequentially
//map<int,pair<int,multiset<int>>>

//Top-View, Right-View, Left-View, Bottom-View, all traversal


bool root_to_node_path(node* root, int x, vector<int>& ds){
  
  if(!root) return false;
  
  ds.push_back(root->val);
  
  if(root->val == x){
    return true;
  }

  if(root_to_node_path(root->left, x, ds) || root_to_node_path(root->right,x,ds)) return true;

  ds.pop_back();
  return false;
}

vector<int> root_to_node_path_helper(node* root, int x){
  vector<int> path;
  if(root_to_node_path(root,x,path)){
    // for(auto e : path) cout << e << " ";
    return path;
  }else{
    cout << "Node Not Found\n";
  }
}

//O(N) space complexity
int lowest_common_ancestor(node* root, int p, int q){
  vector<int> path1 = root_to_node_path_helper(root,p);
  vector<int> path2 = root_to_node_path_helper(root,q);

  int temp = root->val;
  for(int i=0;i<max(path1.size(),path2.size());i++){
    if(path1[i] == path2[i]){
      temp = path1[i];
    }else{
      break;
    }
  }
  return temp;
}

node* lowestCommonAncestor(node* root, node* p, node* q) {
        if (!root)
            return NULL;
        if ((root == p) || (root == q)) {
            return root;
        }

        node* left = lowestCommonAncestor(root->left, p, q);
        node* right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
            return right;
        else if (right == NULL)
            return left;
        else
            return root;
    }


int maximum_width(node* root){
  if(!root) return 0;
  queue<pair<node*, long long>> q;
  q.push({root,0});

  long long max_width = -1;

  while(!q.empty()){
    long long first_index = q.front().second;
    long long size = q.size();
    long long last_index = -1;
    
    for(int i=0;i<size;i++){
      if(i == size-1) last_index = q.front().second;
      auto it = q.front();q.pop();
      node* node = it.first;
      long long ind = it.second - first_index;
      if((node -> left) != NULL) q.push({node->left, 2*ind+1});
      if((node -> right) != NULL) q.push({node->right, 2*ind+2});
    }
    max_width = max(max_width, last_index-first_index+1);
  }
  return max_width;
}

void children_sum_prooperty(node* root){
  if(!root) return;
  int children_sum = 0;

  if(root->left) children_sum+=(root->left)->val;
  if(root->right) children_sum+= (root->right)->val;

  if(children_sum >= (root->val)) root->val = children_sum;
  else {
    if(root->left) root->left->val = root->val;
    if(root->right) root->right->val = root->val;
  } 

  children_sum_prooperty(root->left);
  children_sum_prooperty(root->right);

  int tot = 0;
  if(root->left) tot += root->left->val;
  if(root->right) tot += root->right->val;
  if(root->left || root->right) root->val = tot;
}

//Print all nodes at a distance k from a target node
// 1. Target node location is given
// 2. Only the value at the node is given
void markParent(node* root,unordered_map<node*,node*>& parent_track){
  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    node* front = q.front();q.pop();
    if(front->left) parent_track[front->left] = front, q.push(front->left);
    if(front->right) parent_track[front->right] = front, q.push(front->right);
  }
} 
void all_nodes_at_dist_k(node* root, node* target, int k){
  unordered_map<node*, node*> parent_track;
  unordered_map<node*, bool> visited;
  markParent(root,parent_track);
  queue<node*> q;
  q.push(target);
  visited[target] = true;
  int dist = 0;
  while(!q.empty()){
    int size = q.size();
    if(dist == k) break;
    dist++;
    for(int i=0;i<size;i++){
      node* front = q.front();q.pop();

      if(front->left && !visited[front->left]){
        q.push(front->left);
        visited[front->left] = true;
      }
      if(front->right && !visited[front->right]){
        q.push(front->right);
        visited[front->right] = true;
      }
      if(parent_track[front] && !visited[parent_track[front]]){
        q.push(parent_track[front]);
        visited[parent_track[front]] = true;
      }

    }
  }

  vector<int> ans;
  while(!q.empty()){
    int it = q.front()->val;q.pop();
    ans.push_back(it);
  }
}

node* location_finder(node* root, int src) {
    if (!root) return NULL;
    if (root->val == src) return root;

    node* l = location_finder(root->left, src);
    node* r = location_finder(root->right, src);

    if (l) return l;
    return r;
}
// int min_time_to_burn_tree
int min_time(node* root,node* src){
  if(!root) return 0;
  unordered_map<node*, node*> track_parent;
  unordered_map<node*,bool> visited;
  markParent(root,track_parent);
  queue<node*> q;
  q.push(src);
  visited[src]=true;
  int time = 0;
  while(!q.empty()){
    bool burned = false;
    int size = q.size();
    for(int i=0;i<size;i++){
      node* temp = q.front();q.pop();
      
      node* left = temp->left;
      node* right = temp->right;
      node* parent = track_parent[temp];

      if(left && !visited[left]) q.push(left),visited[left]=true,burned=true;
      if(right && !visited[right]) q.push(right),visited[right]=true,burned=true;
      if(parent && !visited[parent]) q.push(parent),visited[parent]=true,burned=true;

    }
    if(burned) time++;
  }
  return time;
}

// Count all nodes in a complete binary tree
int left_height(node* root){
  int lh = 0;
  while(root){
    lh++;
    root = root->left;
  }
  return lh;
}

int right_height(node* root){
  int rh = 0;
  while(root){
    rh++;
    root = root->right;
  }
  return rh;
}

int count_all_nodes(node* root){
  if(!root) return 0;
  int lh = left_height(root);
  int rh = right_height(root);
  if(lh == rh) return (1 << lh) - 1;

  return 1 + count_all_nodes(root->left) + count_all_nodes(root->right);
}

node* build(vector<int>& pre,vector<int>& in, int preStart, int preEnd, int inStart,int inEnd, unordered_map<int,int>& inMap){

  if((preStart > preEnd) || (inStart > inEnd)) return NULL;

  node* root = new node(pre[preStart]);
  int inRoot = inMap[pre[preStart]];
  int newCount = inRoot - inStart;

  root->left = build(pre,in,preStart+1,preStart+newCount, inStart, inRoot-1,inMap);

  root->right = build(pre,in,preStart+newCount+1,preEnd,inRoot+1,inEnd,inMap);

  return root;
}

node* construct_BT_pre_in(vector<int>& pre, vector<int>& in){
  unordered_map<int,int> inMap;
  for(int i=0;i<in.size();i++){
    inMap[in[i]] = i;
  }
  node* root = build(pre,in,0,pre.size()-1, 0,in.size()-1,inMap);
  return root;
}
node* construct_BT_post_in(vector<int>& po, vector<int>& in){
  unordered_map<int,int> inMap;
  for(int i=0;i<in.size();i++){
    inMap[in[i]] = i;
  }
  node* root = build1(po,in,0,po.size()-1, 0,in.size()-1,inMap);
  return root;
}


node* build1(vector<int>& po,vector<int>& in, int poStart, int poEnd, int inStart,int inEnd, unordered_map<int,int>& inMap){

  if((poStart > poEnd) || (inStart > inEnd)) return NULL;

  node* root = new node(po[poEnd]);
  int inRoot = inMap[po[poEnd]];
  int newCount = inEnd - inRoot;
  
  root->right = build1(po,in,poEnd-newCount,poEnd-1,inRoot+1,inEnd,inMap);

  root->left = build1(po,in,poStart,poEnd-newCount-1, inStart, inRoot-1,inMap);


  return root;
}

int main()
{
  node* root = NULL;
  root = buildTree(root);

  vector<int> pre = {1,2,4,5,3};
  vector<int> in = {4,2,5,1,3};
  root = construct_BT_pre_in(pre, in);
  
}