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

//approach 1 , no sorting , but duplicates in final answer
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int,int>mp;
        for (int i = 0; i < nums.size(); i++){
            mp[nums[i]]=i;
        }

        for(int i=0 ; i<nums.size(); i++){
            int a=nums[i];
            for(int j=i+1 ; j<nums.size(); j++){
                int b =nums[j];

                int diff = -(a+b);
                if(mp.count(diff) && mp[diff]!=i && mp[diff]!=j){
                    ans.push_back({a,b,diff});
                }
            }
        }
    return ans;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size(); i++){
            int target=-nums[i];
            int j=i+1,k=nums.size()-1;
            while (j<k){
                int check=nums[j]+nums[k];

                if (check+target >0)
                {
                    k--;
                }
                else if (check+target <0)
                {
                    j++;
                }
                else{
                    
                }
                 
                
            }
            
        }
        
    }
};
