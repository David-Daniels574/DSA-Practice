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
    int lcm(int a, int b) { return (a / __gcd(a, b)) * b; }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        st.push(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int val = nums[i];
            while (!st.empty() && __gcd(val, st.top()) > 1) {
                int x = st.top();
                st.pop();
                val = lcm(val, x);
            }
            st.push(val);
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};







