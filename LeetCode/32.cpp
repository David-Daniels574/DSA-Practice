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

//BRUTE
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char>st;
        int ans=0;
        int temp=0;
        for(int i=0 ; i<s.size(); i++){
            if(s[i]==')'){
                continue;
            }
            temp=1;
            st.push('(');
            for(int j=i+1; j<s.size(); j++){
                if(s[j]=='('){
                    st.push('(');
                    temp++;
                    continue;
                }
                else if(!st.empty()){
                    st.pop();
                    temp++;
                }
                else{
                    break;
                }

                if(st.empty()){
                ans=max(ans,temp);
                }
            }
            
            st = stack<char>();
        }
    if(ans%2==1){
        return 0;
    }
    return ans;
    }
};

