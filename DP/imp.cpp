#include<bits/stdc++.h>
using namespace std;


//duplicate elements allowed ---> just like ordered arrangement of coins needed
class Solution {
  public:
    int knapSack(vector<int>& v, vector<int>& w, int bag) {
        // dp[i][bag]->maximum points that we could have from ith to (n-1)th
        //index with maximum capacity of bag = b
        int n= v.size();
        vector<vector<int>> dp(n+1,vector<int> (bag+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=bag;b++){
                int take = INT_MIN;
                if(b-w[i] >= 0) take = dp[i][b-w[i]] + v[i];
                
                int not_take = dp[i+1][b];
                dp[i][b] = max(take,not_take);
            }
        }
        
        return dp[0][bag];
    }
};
//same question
class Solution {
  public:
    int knapSack(vector<int>& v, vector<int>& w, int bag) {
        // dp[i][bag]->maximum points that we could have from 0th to ith
        //with maximum capacity of bag = b
        int n= v.size();
        vector<vector<int>> dp(n+1,vector<int> (bag+1,0));
        
        for(int b = 0; b <= bag; b++){
        if(b >= w[0]) dp[0][b] = (b / w[0]) * v[0];
         }
        
        for(int i=1;i<n;i++){
            for(int b=0;b<=bag;b++){
                int take = INT_MIN;
                if(b-w[i] >= 0) take = dp[i][b-w[i]] + v[i];
                
                int not_take = dp[i-1][b];
                dp[i][b] = max(take,not_take);
            }
        }
        
        return dp[n-1][bag];
    }
};



class Solution {
  public:
    int knapsack(int bag, vector<int> &v, vector<int> &w) {
        // dp[i][total]->maximum points that can be collected from ith to (n-1)th 
        // index with (total weight <= total)
        int n= v.size();
        vector<vector<int>> dp(n+1,vector<int> (bag+1,0));
            
        // for(int b=0;b<=bag;b++) if(w[0] <= b) dp[0][b] = v[0]; 
        
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=bag;b++){
                int take = INT_MIN;
                if(b-w[i] >= 0) take = dp[i+1][b-w[i]] + v[i];
                
                int not_take = dp[i+1][b];
                
                dp[i][b] = max(take,not_take);
            }
        }
        return dp[0][bag];
    }
};
//same question
class Solution {
  public:
    int knapsack(int bag, vector<int> &v, vector<int> &w) {
        // dp[i][total]->maximum points that can be collected from 0th to ith 
        // index with (total weight <= total)
        int n= v.size();
        vector<vector<int>> dp(n,vector<int> (bag+1,0));
            
        for(int b=0;b<=bag;b++) if(w[0] <= b) dp[0][b] = v[0]; 
        
        for(int i=1;i<n;i++){
            for(int b=0;b<=bag;b++){
                int take = INT_MIN;
                if(b-w[i] >= 0) take = dp[i-1][b-w[i]] + v[i];
                
                int not_take = dp[i-1][b];
                
                dp[i][b] = max(take,not_take);
            }
        }
        return dp[n-1][bag];
    }
};