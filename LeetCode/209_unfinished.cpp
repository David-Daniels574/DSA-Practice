#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int start = 0;
        int ans = nums.size() + 1;

        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];

            while (sum >= target) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }

        return ans == nums.size() + 1 ? 0 : ans;
    }
};
