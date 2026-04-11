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

    void solve(vector<vector<int>>& ans , vector<int>& temp , int i , vector<int>& arr , set<vector<int>>& st){

    if (i==arr.size()){
        if(st.count(temp)==0){
            ans.push_back(temp);
            st.insert(temp);
        }
        return;
    }

    temp.push_back(arr[i]);
    solve(ans,temp,i+1,arr,st);

    temp.pop_back();
    solve(ans,temp,i+1,arr,st);
}


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    set<vector<int>>st;
    sort(nums.begin(),nums.end());
    solve(ans,temp,0,nums,st);
    return ans;  
    }
};