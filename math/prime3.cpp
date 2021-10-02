/*
POJ 2689
给出区间[L,U],找出区间中距离最近和最远的质数
1<=L,U<=2147483647 , 区间长度<=1000000
不能直接筛质数,先求出sqrt(2147483647)约5W内的质数,因为给定区间长度少于1e6,所以直接用5w内质数筛出来区间内质数就可以。
*/
const int MAXN=100010;
int prime[MAXN+5];
void getpPrime(){
    memset(prime,0,sizeof(prime));
    for(int i=2;i<MAXN;++i){
        if(!prime[i])
            prime[++prime[0]]=i;
        for(int j=1;j<=prime[0] && prime[j]<=MAXN/i;++j){
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
bool notprime[1000005];
int prime2[1000005];
void getPrime2(int L,int R){
    memset(notprime,0,sizeof(notprime));
    if(L<2) L=2;
    for(int i=1;i<=prime[0] && (ll)prime[i]*prime[i]<=R;++i){
        int s=L/prime[i]+(L%prime[i]>0);
        if(s==1) s=2;
        for(int j=s;(ll)j*prime[i]<=R;++j){
            if((ll)j*prime[i]>=L)
                notprime[j*prime[i]-L]=1;
        }
    }
    prime2[0]=0;
    for(int i=0;i<=R-L;++i){
        if(!notprime[i])
            prime2[++prime2[0]]=i+L;
    }
}
int main(){
    getpPrime();
    int L,U;
    while(scanf("%d%d",&L,&U)==2){
        getPrime2(L,U);
        if(prime2[0]<2)
            printf("There are no adjacent primes.\n");
        else {
            int x1=0,x2=1000005,y1=0,y2=0;
            for(int i=1;i<prime2[0];++i){
                if(prime2[i+1]-prime2[i]<x2-x1){
                    x1=prime2[i];
                    x2=prime2[i+1];
                }
                if(prime2[i+1]-prime2[i]>y2-y1){
                    y1=prime2[i];
                    y2=prime2[i+1];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",x1,x2,y1,y2);
        }
    }
}
