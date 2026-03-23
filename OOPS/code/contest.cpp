class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long ans = 0;
        if (need1 ==0 && need2 == 0) {
            return 0;
        }

        if ((cost1 + cost2) > costBoth) {
            int num=min(need1,need2);
            ans+=num*costBoth;
            need1-=num;
            need2-=num;
            if(need1>0){
                if(cost1>costBoth){
                    ans+=need1*costBoth;
                }
                else{
                   ans+=need1*cost1; 
                }
            }
            else if(need2>0){
                if(cost2>costBoth){
                    ans+=need2*costBoth;
                }
                else{
                   ans+=need2*cost2; 
                }   
            }
        }
        else{
            ans=1LL*cost1*need1+1LL*cost2*need2;
        }
    return ans;
    }
};