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

//BRUTE
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        if (heights.size() == 1) {
            return heights[0];
        }

        for (int i = 0; i < heights.size(); i++) {
            int min_e = heights[i], size = 1;
            ans = max(heights[i], ans);
            for (int j = i + 1; j < heights.size(); j++) {
                min_e = min(min_e, heights[j]);
                size++;
                ans = max(min_e * size, ans);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int ans = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                int curr_ht = heights[st.top()];
                st.pop();
                int curr_wt = i - st.top() - 1;
                ans = max(ans, curr_ht * curr_wt);
            }
            st.push(i);
        }

        while (st.top() != -1) {
            int curr_ht = heights[st.top()];
            st.pop();
            int curr_wt = heights.size() - st.top() - 1;
            ans = max(ans, curr_ht * curr_wt);
        }

        return ans;
    }
};