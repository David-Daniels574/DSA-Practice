#include <bits/stdc++.h>
using namespace std;

// 7 1 5 3 6 4
class temp
{
private:
    /* data */
public:
    temp(/* args */);
    ~temp();
};

temp::temp(/* args */)
{
}

temp::~temp()
{
}


int profit (vector<int>&arr){

    int buy=arr[0],profit=0;
    for(int i = 1; i < arr.size(); i++){
        profit=max(profit,arr[i]-buy);
        buy=min(buy,arr[i]);
    }
    return profit;
}

/*
 7 1 5 3 6 4
*/

int rob(vector<int>&arr){

    if(arr.size()==1){
        return arr[0];
    }
    vector<int>dp(arr.size(),0);
    dp[0]=arr[0];
    dp[1]=arr[1];
    for (int i = 2; i < arr.size(); i++){
        dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
    }
    return max(dp[dp.size()-1], dp[dp.size()-2]);
}



int main(int argc, char const *argv[]){
    int n;
    cin>>n;
    vector<int>arr;
    
    return 0;
}
//anagram
/*

class animal{
hello

generics,collections,jvm internals,final,immutable class
singleton,factory
string vs stringbuilder vs stringbuffer,immutability? , string common pool 

public animal make_copy(){
    
    }
}

class dog extends animal{
bark

public dog make_copy(){

    }

}

animal a = new dog()
a.sound()


*/