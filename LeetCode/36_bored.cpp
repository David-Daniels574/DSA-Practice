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

    bool check_box(int x,int y){

    }

    bool check_row(int x){

    }

    bool check_col(int y){

    }

    bool isValidSudoku(vector<vector<char>>& board) {
       for(int i=0 ; i<board.size(); i++){
        if(check_row(i)==false || check_col(i)==false){
            return false;
        }
       }
       int x=0,y=0;
       for(int i=0 ; i<board.size(); i+=3){
        for(int j=0 ; j<board[i].size(); j+=3){
            if(check_box(i,j)==false){
                return false;
            }
        }
       }
    return true;
    }
};