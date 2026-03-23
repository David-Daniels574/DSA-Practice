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
    int longestBalanced(vector<int>& nums) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        int e = 0, o = 0, ans = 0, len = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] % 2 == 0) {
                    if (s1.find(nums[j]) == s1.end()) {
                        e++;
                        len++;
                        s1.insert(nums[j]);
                    } else {
                        len++;
                    }
                } else {
                    if (s2.find(nums[j]) == s2.end()) {
                        o++;
                        len++;
                        s2.insert(nums[j]);
                    } else {
                        len++;
                    }
                }
                if (o == e) {
                    ans = max(ans, len);
                }
            }

            len = 0;
            o = 0;
            e = 0;
            s1.clear();
            s2.clear();
        }
        return ans;
    }
};