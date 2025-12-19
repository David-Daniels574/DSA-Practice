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


//PURE BRUTE FORCE PAIN
class Solution {
public:

    bool check_cap(string a,string b){
        transform(a.begin(), a.end(), a.begin(),::tolower);
        transform(b.begin(), b.end(), b.begin(),::tolower);
        if(a==b){
            return true;
        }
        return false;
    }

    
    bool is_vov(char c) {
        if (c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }
        return false;
    }

    
    bool check_vov(string a,string b){
        transform(a.begin(), a.end(), a.begin(),::tolower);
        transform(b.begin(), b.end(), b.begin(),::tolower);
        for (int i = 0; i < a.size(); i++){
            if(!is_vov(a[i]) && !is_vov(b[i])){
                if (a[i]!=b[i]){
                    return false;
                }
            }
            else if(is_vov(a[i]) && is_vov(b[i])){
                continue;
            }
            else{
                return false;
            }
            
        }
        return true;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string>ans;
        for (int i = 0; i < queries.size(); i++){

            int change=0,cap=0,eq=0;
            for (int j = 0; j < wordlist.size(); j++){
                if (queries[i].size()==wordlist[j].size()){
                    if (queries[i]==wordlist[j]){
                        ans.push_back(wordlist[j]);
                        change=1;
                        eq=1;
                        break;
                    }                                     
                }
            }
            if(eq){
                continue;
            }
            for (int j = 0; j < wordlist.size(); j++){
                if (queries[i].size()==wordlist[j].size()){
                    if (check_cap(queries[i],wordlist[j])){
                        ans.push_back(wordlist[j]);
                        change=1;
                        cap=1;
                        break;
                    }                                     
                }
            }
            if(cap){
                continue;
            }
            for (int j = 0; j < wordlist.size(); j++){
                if (queries[i].size()==wordlist[j].size()){
                    if(check_vov(queries[i],wordlist[j])){
                        ans.push_back(wordlist[j]);
                        change=1;
                        break;
                    }              
                }  
            }
            if(change==0){
                ans.push_back("");
            }
            
        }
        return ans;
    }
};


class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
    }
};