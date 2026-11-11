class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mincost =1e9;
        mincost= min((1LL*cost1*need1+ 1LL* cost2*need2), 1LL*costBoth*max(need1,need2));
        if(need1 > need2){
            long long cost=1e9;
            cost =1LL*costBoth*need2 +1LL*cost1*(need1-need2);
            mincost=min(mincost,cost);
        }else{
            long long cost=1e9;
            cost =1LL*costBoth*need1 +1LL*cost2*(need2-need1);
            mincost=min(mincost,cost);
        }
        return mincost;
    }
};