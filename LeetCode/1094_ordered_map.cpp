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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>mp;

        for(int i=0 ;i<trips.size(); i++){
            mp[trips[i][1]]+=trips[i][0];
            mp[trips[i][2]]-=trips[i][0];
        }
        int sum=0;
        for (auto& a:mp){
            sum+=a.second;
            if(sum>capacity){
                return false;
            }
        }
    return true;
    }
};