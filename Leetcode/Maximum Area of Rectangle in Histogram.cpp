#include <iostream>
#include<vector>
#include<stack>
 
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int> left_smaller(n);
  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    while ((!st.empty()) && (arr[st.top()] >= arr[i]))
    {
      st.pop();
    }

    if (st.empty())
      left_smaller[i] = 0;
    else
      left_smaller[i] = st.top() + 1;

    st.push(i);
  }

  vector<int> right_smaller(n);
  while (!st.empty())
    st.pop();

  for (int i = n - 1; i >= 0; i--)
  {
    while ((!st.empty()) && (arr[st.top()] >= arr[i])) st.pop();

    if(st.empty()) right_smaller[i] = n-1;
    else right_smaller[i] = st.top() - 1 ;
    st.push(i); 
  }
  int maxi = 0;
  for(int i=0;i<n;i++){
    maxi = max(maxi, (right_smaller[i] - left_smaller[i] + 1) * arr[i]);
  }

  cout << maxi << endl;
}
