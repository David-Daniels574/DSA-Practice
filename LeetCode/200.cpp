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
    vector<int>drow={1,0,-1,0};
    vector<int>dcol={0,1,0,-1};
    void dfs(int i , int j ,vector<vector<char>>& grid ){  
        if(grid[i][j]=='1'){
            grid[i][j]='x';
            for(int k=0 ; k<dcol.size(); k++){
                int ci=i+drow[k];
                int cj=j+dcol[k];
                if(ci<grid.size() && ci>=0 && cj<grid[ci].size() && cj>=0 && grid[ci][cj]=='1'){
                    dfs(ci,cj,grid);
                }
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0 ; i<grid.size(); i++){
            for(int j=0 ;j<grid[i].size(); j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};