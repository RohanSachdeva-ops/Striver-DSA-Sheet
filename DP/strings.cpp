#include<bits/stdc++.h>
using namespace std;
int lcs(string t1,string t2,int i1,int i2,vector<vector<int>>& dp,string& ans){
    if(i1<0 || i2<0) return 0;

    if(dp[i1][i2]!=-1) return dp[i1][i2];

    if(t1[i1]==t2[i2]) {
        ans+=t1[i1];
        return dp[i1][i2] = 1+lcs(t1,t2,i1-1,i2-1,dp,ans);
    }else{
        return dp[i1][i2] = 0+max(lcs(t1,t2,i1-1,i2,dp,ans), lcs(t1,t2,i1,i2-1,dp,ans));
    }
}
int main(){
    string text1,text2;cin>>text1>>text2;
        int n=text1.size();int m=text2.size();
        string ans="";
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        cout << lcs(text1,text2,n-1,m-1,dp,ans)<<endl;
        cout<<ans;
}



// #include<bits/stdc++.h>
// using namespace std;

// int lcs(string t1,string t2,int i1,int i2){
//         if(i1<0 || i2<0) return 0;

//         if(t1[i1]==t2[i2]) {
//             return 1+lcs(t1,t2,i1-1,i2-1);
//         }else{
//             return 0+max(lcs(t1,t2,i1-1,i2), lcs(t1,t2,i1,i2-1));
//         }
//     }

// int main(){
//     string t1,t2;cin>>t1>>t2;
//     int n=t1.size(),m=t2.size();

//     return lcs(text1,text2,n-1,m-1);
// }