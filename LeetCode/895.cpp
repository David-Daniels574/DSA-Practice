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

class FreqStack {
public:
    unordered_map<int,int>mp1;
    int max_freq=0;
    unordered_map<int,stack<int>>mp2;
    FreqStack() {
        
    }
    
    void push(int val) {
        max_freq=max(max_freq,++mp1[val]);
        mp2[mp1[val]].push(val);
    }
    
    int pop() {
        int ans=mp2[max_freq].top();
        mp2[max_freq].pop();
        mp1[ans]--;
        if(mp2[max_freq].empty()){
            max_freq--;
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */