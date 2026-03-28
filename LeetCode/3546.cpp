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
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum_tot=0,curr_sum_s=0,curr_sum_e=0;
        for(int i=0 ; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                sum_tot+=grid[i][j];
            }
        }
        
        curr_sum_e=sum_tot;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j<grid[i].size(); j++){
                curr_sum_s+=grid[i][j];
                curr_sum_e-=grid[i][j];
            }
            if (curr_sum_e==curr_sum_s){
                return true;
            }
        }
        
        curr_sum_s=0;
        curr_sum_e=sum_tot;

        for (int i = 0; i < grid[0].size(); i++){
            for (int j = 0; j<grid.size(); j++){
                curr_sum_s+=grid[j][i];
                curr_sum_e-=grid[j][i];
            }
            if (curr_sum_e==curr_sum_s){
                return true;
            }
        }
    return false;
    }
};