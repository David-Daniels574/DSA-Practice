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
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char, vector<char>> mp = {
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'}},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'t','u','v'}},
            {'9', {'w','x','y','z'}}
        };

        vector<string> ans = {""};

        for(char digit : digits){
            vector<string> temp;

            for(string s : ans){
                for(char c : mp[digit]){
                    temp.push_back(s + c);
                }
            }

            ans = temp; // move to next level
        }

        return ans;
    }
};


class Solution {
public:

    vector<string>ans;

    void recur(int curr , int n , unordered_map<char, vector<char>>& mp, string& temp,string& digits){
        if(curr==n){
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < mp[digits[curr]].size(); i++){
            temp+=mp[digits[curr]][i];
            recur(curr+1,n,mp,temp,digits);
            temp.pop_back();
        }
        
    }


    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char, vector<char>> mp = {
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'}},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'t','u','v'}},
            {'9', {'w','x','y','z'}}
        };

        string temp;
        recur(0,digits.size(), mp ,temp,digits);
        return ans;
    }
};



