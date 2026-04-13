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

class NumArray {
public:
    vector<int> tree;
    vector<int> arr;
    int n;

    void build(int node ,int start , int end){
        if (start==end){
            tree[node]=arr[start];
            return;
        }

        int mid=start+(end-start)/2;
        int left=2*node+1;
        int right=2*node+2;

        build(left,start,mid);
        build(right,mid+1,end);
        
        tree[node]=tree[left]+tree[right];
    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        arr=nums;
        tree.resize(n*4);
        build(0,0,n-1);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
        tree[node] = val;
        arr[idx] = val;
        return;
        }
        
        int mid=start+(end-start)/2;
        int left=2*node+1;
        int right=2*node+2;

        if (idx <= mid) {
            update(left, start, mid, idx, val);
        } else {
            update(right, mid + 1, end, idx, val);
        }

        tree[node] = tree[left] + tree[right];
    }

    void update(int index, int val) {
        update(0,0,n-1,index,val);
    }

    int query(int node, int start, int end, int L, int R) {
        if (start > R || end < L) {
            return 0;
        }

        if (L <= start && end <= R) {
            return tree[node];
        }

        int mid=start+(end-start)/2;
        int left=2*node+1;
        int right=2*node+2;

        int l=query(left,start,mid,L,R);
        int r=query(right,mid+1,end,L,R);
            return l+r;
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */