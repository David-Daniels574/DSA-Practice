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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int size(ListNode* root){
        int ans=0;
        ListNode* temp=root;
        while(temp!=NULL){
            ans++;
            temp=temp->next;
        }
        return ans;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s=size(head);
        if((s==1 && n==1) || (s==0)){
            return NULL;
        }

        int travel=s-n;
        if(travel==0){
            ListNode* temp=head;
            head=head->next;
            return head;
        }
        ListNode* curr=head;
        ListNode* prev;

        while(travel>0 && curr!=NULL){
            prev=curr;
            curr=curr->next;
            travel--;
        }
        ListNode* temp=curr;
        prev->next=curr->next;


        return head;
    }
};