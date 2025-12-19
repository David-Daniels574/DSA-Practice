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
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
       double diag=0; 
       int area=0;
       for(int i=0 ; i<dimensions.size(); i++){
        int x=dimensions[i][0];
        int y=dimensions[i][1];
        double td=sqrt(x*x + y*y);
        int ta=x*y;
        if(td>diag){
            diag=td;
            area=ta;
        }
        else if(td==diag){
            area=max(area,ta);
        }
       }
    return area; 
    }
};