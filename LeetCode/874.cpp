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
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0 , y=0;
        int ans=0;

        set<pair<int,int>> obs;
        for(int i=0 ; i<obstacles.size(); i++){
            obs.insert({obstacles[i][0],obstacles[i][1]});
        }

        int x_dir=0,y_dir=1;

        for(int i=0 ; i<commands.size(); i++){
            int curr=commands[i];

            if(curr==-2){
                // turn left
                int temp = x_dir;
                x_dir = -y_dir;
                y_dir = temp;
            }
            else if(curr==-1){
                // turn right
                int temp = x_dir;
                x_dir = y_dir;
                y_dir = -temp;
            }
            else{
                for(int step=0; step<curr; step++){
                    int nx = x + x_dir;
                    int ny = y + y_dir;

                    if(obs.count({nx,ny})) break;

                    x = nx;
                    y = ny;

                    ans = max(ans, x*x + y*y);
                }
            }
        }
        return ans;
    }
};