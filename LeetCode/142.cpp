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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//SCAM
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>hold;
        ListNode* temp=head;
        while(temp && hold.count(temp)==0){
            hold.insert(temp);
            temp=temp->next;
        }
        return temp;
    }
};


