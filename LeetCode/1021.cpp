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
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";

        for (char c : s) {
            if (c == '(') {
                if (!st.empty()) {
                    ans += c;  // not outer
                }
                st.push(c);
            } 
            else { // c == ')'
                st.pop();
                if (!st.empty()) {
                    ans += c;  // not outer
                }
            }
        }

        return ans;
    }
};


class Solution {
public:
    // Function to remove outermost parentheses of every primitive string in the
    // decomposition of s
    string removeOuterParentheses(string s) {
        string result;   // To store the final result
        int balance = 0; // To keep track of the balance of parentheses

        // Iterate through each character in the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // If balance is greater than 0, it means this '(' is not an
                // outermost parenthesis
                if (balance > 0) {
                    result += s[i]; // Add the character to the result
                }
                balance++; // Increase the balance for '('
            } else {
                balance--; // Decrease the balance for ')'
                // If balance is greater than 0, it means this ')' is not an
                // outermost parenthesis
                if (balance > 0) {
                    result += s[i]; // Add the character to the result
                }
            }
        }

        return result; // Return the final result after removing outermost
                       // parentheses
    }
};