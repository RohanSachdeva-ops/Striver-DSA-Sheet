#include <bits/stdc++.h>
using namespace std;

void sub(int i,vector<int>& v,vector<int>& final,int n){
    if(i==n){
        for(auto x:final) cout<<x<<" ";
        cout<<endl;
        return;
    }

  final.push_back(v[i]);
  sub(i+1,v,final,n);
  final.pop_back();
  sub(i+1,v,final,n);
}

int main() {
   int n;cin>>n;
   vector<int> v(n);
   for (int i = 0;i < n; i++) {
       cin >> v[i];
   }
   vector<int> final;
   sub(0,v,final,n);
}



/*

//PRINT ALL SUBSEQUENCES HAVING SUM 'sum'
#include <bits/stdc++.h>
using namespace std;

void sub(int i,vector<int>& v,vector<int>& final,int s,int sum,int n){
    if(i==n){
        if(s==sum){
        for(auto x:final) cout<<x<<" ";
        cout<<endl;
        }
        return;
    }

  final.push_back(v[i]);
  s+=v[i];
  sub(i+1,v,final,s,sum,n);
  final.pop_back();
  s-=v[i];
  sub(i+1,v,final,s,sum,n);
}

int main() {
   int n,sum;cin>>n>>sum;
   vector<int> v(n);
   for (int i = 0;i < n; i++) {
       cin >> v[i];
   }
   vector<int> final;
   sub(0,v,final,0,sum,n);
}
*/

/*
// PRINT ANY ONE OF THE SUBSEQUENCES

#include <bits/stdc++.h>
using namespace std;

bool sub(int i,vector<int>& v,vector<int>& final,int s,int sum,int n){
    if(i==n){
        if(s==sum){
        for(auto x:final) cout<<x<<" ";
        return true;
        }
        return false;
    }

  final.push_back(v[i]);
  s+=v[i];
  if(sub(i+1,v,final,s,sum,n)==true){
    return true;
  }
  final.pop_back();
  s-=v[i];
  if(sub(i+1,v,final,s,sum,n)==true){
    return true;
  }

  return false;
}

int main() {
   int n,sum;cin>>n>>sum;
   vector<int> v(n);
   for (int i = 0;i < n; i++) {
       cin >> v[i];
   }
   vector<int> final;
   sub(0,v,final,0,sum,n);
}
*/

/*
//NUMBER OF SUBSEQUENCES HAVING SUM 'sum'
#include <bits/stdc++.h>
using namespace std;

int sub(int i,vector<int>& v,int s,int sum,int n){
    if(i==n){
        if(s==sum) return 1;  
        else return 0;
    }

  s+=v[i];
  int l = sub(i+1,v,s,sum,n);
  s-=v[i];
  int r = sub(i+1,v,s,sum,n);

  return l+r;
}

int main() {
   int n,sum;cin>>n>>sum;
   vector<int> v(n);
   for (int i = 0;i < n; i++) {
       cin >> v[i];
   }
   vector<int> final;
   cout<<sub(0,v,0,sum,n);
}
*/
