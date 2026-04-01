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

//hehe
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int z = 0, o = 0, t = 0;

        for (int i : nums) {
            switch (i) {
            case 0:
                z++;
                break;

            case 1:
                o++;
                break;

            case 2:
                t++;
                break;

            default:
                break;
            }
        }

        int i = 0;

        while (z > 0) {
            nums[i] = 0;
            i++;
            z--;
        }
        while (o > 0) {
            nums[i] = 1;
            i++;
            o--;
        }
        while (t > 0) {
            nums[i] = 2;
            i++;
            t--;
        }
    }
};


//DNF 
void sort012(vector<int> &arr) {
    int n = arr.size();
    
    // initialize three pointers:
    // lo: boundary for 0s
    // mid: current element being checked
    // hi: boundary for 2s
    int lo = 0;
    int hi = n - 1;
    int mid = 0;
    
    // process elements until mid crosses hi
    while (mid <= hi) {
        if (arr[mid] == 0) {
            
            // current is 0: swap with lo and move both 
            // pointers forward
            swap(arr[lo++], arr[mid++]);
        }
        else if (arr[mid] == 1) {
            // current is 1: it's already in correct position
            mid++;
        }
        else {
            // current is 2: swap with hi and move hi backward
            // do not increment mid, as swapped value needs
            // to be re-checked
            swap(arr[mid], arr[hi--]);
        }
    }
}