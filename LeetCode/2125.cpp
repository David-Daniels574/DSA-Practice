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


//ME
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;

        vector<int>nos;
        for(int i=0 ; i<bank.size(); i++){
            int temp=0;
            for(int j =0 ; j<bank[i].size(); j++){
                if(bank[i][j]=='1'){
                    temp++;
                }
            }
            if(temp!=0){
                nos.push_back(temp);
            }
            temp=0;
        }
        if(nos.size()==0){
            return 0;
        }

        for(int i=0 ; i<nos.size()-1; i++){
            ans+=nos[i]*nos[i+1];
        }
    return ans;
    }
};


//O(1) space
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0;
        
        for (string s : bank) {
            int count = 0;
            for (char c : s) {
                if (c == '1') {
                    count++;
                }
            }
            if (count != 0) {
                ans += (prev * count);
                prev = count;
            }
        }
        
        return ans;
    }
};

