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


/*
90 = transpose + reverse row
180 = reverse row + reverse column
270 = transpose + reverse col
*/
//to do transpose

/*
for (int i = 0; i < N; i++){
    for (int j = i+1; j < N; j++){
        swap(matrix[i][j],matrix[j][i]);
    }
}
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N=matrix.size();
        for (int i = 0; i < N; i++){
            for (int j = i+1; j < N; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (int i = 0; i < N; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    
    }
};