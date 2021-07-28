int nValue,nKind;
const int N=100005;
int dp[N],cost[N],value[N],num[N];
//0-1背包,代价为cost,价值为value
void ZeroOnePack(int cost,int value){
    for(int i=nValue;i>=cost;i--)
        dp[i]=max(dp[i],dp[i-cost]+value);
}
//完全背包,代价为cost,价值为value
void CompletePack(int cost,int value){
    for(int i=cost;i<=nValue;++i)
        dp[i]=max(dp[i],dp[i-cost]+value);
}
//多重背包,代价为cost,价值为value,数量为amount
void MultiplePack(int cost,int weight,int amount){
    if(cost*amount>=nValue)
        CompletePack(cost,weight);
    else {
        int k=1;
        while(k<amount){
            ZeroOnePack(k*cost,k*weight);
            amount-=k;
            k<<=1;
        }
        ZeroOnePack(amount*cost,amount*weight);
    }
}
int main(){
    //记得清空数组
    memset(dp,0,sizeof dp);
    //0-1背包
    rep(i,1,nKind)
        ZeroOnePack(cost[i],value[i]);
    printf("%d\n",dp[nValue]);
    //完全背包
    rep(i,1,nKind)
        CompletePack(cost[i],value[i]);
    printf("%d\n",dp[nValue]);
    //多重背包
    rep(i,1,nKind)
        MultiplePack(cost[i],value[i],num[i]);
    printf("%d\n",dp[nValue]);
    //分组背包
    rep(k,1,ts)//循环每一组
        for(int i=nValue;i>=0;--i)//循环背包容量
            rep(j,1,cnt[k])//循环该组的每一个物品
                if (i >= cost[t[k][j]])
                dp[i]=max(dp[i],dp[i-cost[t[k][j]]]+value[t[k][j]]);
                //像0-1背包一样状态转移
    return 0;
}