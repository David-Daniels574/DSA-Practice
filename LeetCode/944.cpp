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
    int minDeletionSize(vector<string>& strs) {
        //i is str index , j is str number
        int ans=0;
        for(int i=0 ; i<strs[1].size(); i++){
            for(int j=0 ; j<strs.size()-1; j++){
                if(strs[j][i]>strs[j+1][i]){
                    ans++;
                    break;
                }
            }
        }
    return ans;
    }
};