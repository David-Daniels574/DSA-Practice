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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        vector<int>ans;

        
        for(int i=0 ;i<nums.size(); i++){
            if(!dq.empty() && dq.front().second<=i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[i]>dq.back().first){
                dq.pop_back();
            }
            dq.push_back({nums[i],i});
            if(i>=k-1){
            ans.push_back(dq.front().first);
            }
        }
        return ans;
    }
};