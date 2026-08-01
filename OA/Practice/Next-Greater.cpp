#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int ,int> next_greater;
        for(auto x:nums2){
            while( !st.empty() && (x > st.top())){
                next_greater[st.top()] = x;
                st.pop(); 
            }
            st.push(x);
        }

        vector<int> ans;

        for(auto x:nums1){
            if(next_greater.find(x) != next_greater.end()){
                ans.push_back(next_greater[x]);
            }else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};