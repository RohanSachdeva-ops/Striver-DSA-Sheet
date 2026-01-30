// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,m;cin>>n>>m;
//     vector<vector<int>> grid(n, vector<int> (m,0));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>grid[i][j];
//         }
//     }
    
//     vector<int> prev(m,0);
//     for(int j=0;j<m;j++) prev[j]=grid[0][j];

//     for(int i=1;i<n;i++){
//         vector<int> current_row(m,0);
//         for(int j=0;j<m;j++){
//             int straight = INT_MIN, LeftDiagonal=INT_MIN, RightDiagonal=INT_MIN;
            
//             straight = grid[i][j] + prev[j];
//             if(j-1 >= 0) LeftDiagonal = grid[i][j] + prev[j-1];
//             if(j+1 < m) RightDiagonal = grid[i][j] + prev[j+1];
//             current_row[j] = max(straight, max(LeftDiagonal, RightDiagonal));
//         }
//         prev=current_row;
//     }

//     cout<<*(max_element(prev.begin(), prev.end()));    
// }


// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,m;cin>>n>>m;
//     vector<vector<int>> grid(n, vector<int> (m,0));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>grid[i][j];
//         }
//     }
    
//     vector<vector<int>> dp(n, vector<int> (m,-1));
//     for(int j=0;j<m;j++) dp[0][j]=grid[0][j];

//     for(int i=1;i<n;i++){
//         for(int j=0;j<m;j++){
//             int straight = INT_MIN, LeftDiagonal=INT_MIN, RightDiagonal=INT_MIN;
//             straight = grid[i][j] + dp[i-1][j];
//             if(j-1 >= 0) LeftDiagonal = grid[i][j] + dp[i-1][j-1];
//             if(j+1 < m) RightDiagonal = grid[i][j] + dp[i-1][j+1];
//             dp[i][j] = max(straight, max(LeftDiagonal, RightDiagonal));
//         }
//     }

//     cout<<*(max_element(dp[n-1].begin(), dp[n-1].end()));    
// }


// #include<bits/stdc++.h>
// using namespace std;
// //maxpathsum

// int f(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp){
//     int n=grid.size();
//     int m=grid[0].size();
//     if(j<0 || j>=m) return -1e9;
//     if(i==0) return grid[0][j];

//     if(dp[i][j] != -1) return dp[i][j];

//     int straight = grid[i][j]+ f(i-1,j,grid,dp);
//     int diagonalLeft = grid[i][j]+ f(i-1,j-1,grid,dp);
//     int diagonalRight = grid[i][j]+ f(i-1,j+1,grid,dp);

//     return dp[i][j]=max(straight, max(diagonalLeft, diagonalRight));
// }


// int main(){
//     int n,m;cin>>n>>m;
//     vector<vector<int>> grid(n, vector<int> (m,0));
//     vector<vector<int>> dp(n, vector<int> (m,-1));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>grid[i][j];
//         }
//     }

//     int maxi=INT_MIN;
//     for(int j=0;j<m;j++){
//         maxi=max(maxi, f(n-1,j,grid,dp));
//     }
//     cout<<maxi<<endl;
// }


// #include<bits/stdc++.h>
// using namespace std;
// //maxpathsum

// int f(int i, int j, vector<vector<int>>& grid){
//     int n=grid.size();
//     int m=grid[0].size();
//     if(j<0 || j>=m) return -1e9;
//     if(i==0) return grid[0][j];

//     int straight = grid[i][j]+ f(i-1,j,grid);
//     int diagonalLeft = grid[i][j]+ f(i-1,j-1,grid);
//     int diagonalRight = grid[i][j]+ f(i-1,j+1,grid);

//     return max(straight, max(diagonalLeft, diagonalRight));
// }


// int main(){
//     int n,m;cin>>n>>m;
//     vector<vector<int>> grid(n, vector<int> (m,0));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>grid[i][j];
//         }
//     }

//     int maxi=INT_MIN;
//     for(int j=0;j<m;j++){
//         maxi=max(maxi, f(n-1,j,grid));
//     }
//     cout<<maxi<<endl;
// }