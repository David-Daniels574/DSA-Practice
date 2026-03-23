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
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }

        vector<vector<char>>tmp(numRows,vector<char>(s.size(),'?'));

        int r=0,c=0,dir=0;
        for(int i=0 ; i<s.size(); i++){
            tmp[r][c]=s[i];
            if(r==numRows-1){dir=-1;}
            if(r==0){dir=0;}
            if(dir==0)r++;
            else {r--;c++;}
            
        }
        int x=0;
        for (int i = 0; i < tmp.size(); i++){
            for (int j = 0; j < tmp[i].size(); j++){
                if (tmp[i][j]!='?'){
                    s[x]=tmp[i][j];
                    x++;    
                }    
            }
        }
        return s;
    }
};
