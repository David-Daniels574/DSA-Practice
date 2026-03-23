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
    vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n; i++) {
        int idx = i % n;

        while (!st.empty() && nums[st.top()] < nums[idx]) {
            ans[st.top()] = nums[idx];
            st.pop();
        }

        if (i < n) {  
            st.push(idx);
        }
    }
    return ans;
    }
};