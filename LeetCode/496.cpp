#include <bits/stdc++.h>
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

using namespace std;
using vi = vector<int>;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;

        for(int i=nums2.size()-1 ; i>=0; i--){
            int curr=nums2[i];
            while(!st.empty() && st.top()<curr){
                st.pop();
            }
            
            if(st.empty()){
                mp[curr]=-1;
            }
            else{
                mp[curr]=st.top();
            }
            st.push(curr);
        }
        
        for(int i=0 ;i<nums1.size(); i++){
            nums1[i]=mp[nums1[i]];
        }
    return nums1;
    }
};