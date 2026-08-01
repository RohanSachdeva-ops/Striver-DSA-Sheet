#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int dfs(TreeNode* root, int& camera){
        if(!root) return 1;

        int left = dfs(root->left, camera);
        int right = dfs(root->right, camera);

        //priority 1
        if((left == 0) || (right == 0)){
            camera++;
            return 2;
        }

        //priority 2
        if((left == 2)||(right == 2)){
            return 1;
        }

        
            return 0;
        
    }

    int minCameraCover(TreeNode* root) {
        int camera = 0;
        if(dfs(root, camera) == 0) camera++;
        return camera;
    }
};