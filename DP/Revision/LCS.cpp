#include <bits/stdc++.h>
using namespace std;

void lcs_tabulation()
{
    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n, j = m;
    string lcs = "";
    while ((i > 0) && (j > 0))
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs += str1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << endl;
}

int lcs_memoization(int i,int j,const string& str1,const string& str2,int n,int m,vector<vector<int>>& dp){
    
    //base condition
     if(i < 0 || j < 0)
        return 0;
    
    if(str1[i]==str2[j]){
        return 1+lcs_memoization(i-1,j-1,str1,str2,n,m,dp);
    }else{
        return max(lcs_memoization(i,j-1,str1,str2,n,m,dp),lcs_memoization(i-1,j,str1,str2,n,m,dp));
    }
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    
}