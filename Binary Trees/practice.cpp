#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int data1)
  {
    val = data1;
  }
  TreeNode(int data1, TreeNode *left1, TreeNode *right1)
  {
    val = data1;
    left = left1;
    right = right1;
  }
};

TreeNode *buildTree(TreeNode *root)
{
  int val;
  cin >> val;
  root = new TreeNode(val);

  if (val == -1)
    return NULL;

  root->left = buildTree(root->left);
  root->right = buildTree(root->right);

  return root;
}

int maxDepth(TreeNode *root)
{
  if (root == NULL)
    return 0;

  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);

  return max(lh, rh) + 1;
}

bool isBalanced1(TreeNode *root)
{
  if (root == NULL)
    return true;

  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);

  if (abs(lh - rh) > 1)
    return false;

  return isBalanced1(root->left) && isBalanced1(root->right);
}

int isBalanced2(TreeNode *root)
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

int isBalanced2Helper(TreeNode *root)
{
  return (isBalanced2(root) != -1);
}

int maxi = 0;
int diameter(TreeNode *root)
{
  if (root == NULL)
    return 0;

  int lh = diameter(root->left);
  int rh = diameter(root->right);

  maxi = max(lh + rh, maxi);

  return max(lh, rh) + 1;
}

int maxPathSum(TreeNode *root)
{
  if (root == NULL)
    return 0;

  int lh = maxPathSum(root->left);
  int rh = maxPathSum(root->right);

  maxi = max(maxi, lh + rh + root->val);
  return (max(lh, rh) + root->val) > 0 ? max(lh, rh) + root->val : 0;
}

bool isSame(TreeNode *p, TreeNode *q)
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

void level_order_traversal(TreeNode* root){
  if(root == NULL) return;
  vector<vector<int>> ans;

  queue<TreeNode*> q;
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

void zigzag_order_traversal(TreeNode* root){
  if(root == NULL) return;
  vector<vector<int>> ans;

  queue<TreeNode*> q;
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


int main()
{
  TreeNode* root = NULL;
  root = buildTree(root);
  zigzag_order_traversal(root);

}