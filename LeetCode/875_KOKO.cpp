#include <deque>
#include <iostream>
#include <algorithm>
#include <string> 
#include <queue>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canFinish(const vector<int>& piles, int h, int k) {
        long long hours = 0;
        for (int pile : piles) {
            hours += pile / k;
            if (pile % k != 0) hours++;
            if (hours > h) return false;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        //min , eat 1 banana
        int left = 1;

        //max , eat all bananas
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;
        //left , right isnt index , its  the answer we have
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, h, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};