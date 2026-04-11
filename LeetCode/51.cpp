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
    vector<vector<string>> ans;

    bool is_valid(const vector<int>& x, int k, int i) {
        for (int j = 0; j < k; j++) {
            if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
                return false;
            }
        }
        return true;
    }

    void do_nq(vector<int> x, int k, int n) {
        for (int i = 0; i < n; i++) {
            if (is_valid(x, k, i)) {
                x[k] = i;
                if (k == n - 1) {
                    vector<string> board(n, string(n, '.'));
                    for (int r = 0; r < n; r++) {
                        board[r][x[r]] = 'Q';
                    }
                    ans.push_back(board);
                } else {
                    do_nq(x, k + 1, n);
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> x(n);
        do_nq(x, 0, n);
        return ans;
    }
};





class Solution {
private:
    vector<int> cols, diag1, diag2;

    void generate(vector<vector<string>> &ans, vector<string> &board, int n, int row){
        // Base case: all queens placed
        if(row == n){
            ans.emplace_back(board);
            return;
        }

        // Try placing queen in each column of current row
        for(int col = 0; col < n; col++){

            // Check if position is safe
            if(cols[col] || diag1[row + col] || diag2[row - col + (n - 1)])
                continue;

            // Place queen
            cols[col] = 1;
            diag1[row + col] = 1;
            diag2[row - col + (n - 1)] = 1;
            board[row][col] = 'Q';

            // Recur for next row
            generate(ans, board, n, row + 1);

            // Backtrack: remove queen
            cols[col] = 0;
            diag1[row + col] = 0;
            diag2[row - col + (n - 1)] = 0;
            board[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        // Initialize tracking arrays
        cols.assign(n, 0);
        diag1.assign(2*n - 1, 0);
        diag2.assign(2*n - 1, 0);

        vector<vector<string>> ans;

        // Initialize empty board
   
        vector<string> board(n, string(n, '.'));

        // Start backtracking from row 0
        generate(ans, board, n, 0);

        return ans;
    }
};