/*
组合数学求法:
1.杨辉三角打表
所需空间:O(nm),时间:预处理O(nm),查询O(1)
*/
const int mod = 1e9+7;
int c[maxn][maxn];
void init(int n){
	c[0][0]=1;
	rep(i,1,n){
		c[i][0]=1;
		rep(j,1,n+1)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
}

/*
2.直接用公式
Cnm=n!/(m!(n-m)!)
不能取模,时间:预处理O(1),查询O(n)
*/
ll C(ll n, ll m)
{
    if (n < m) return 0;
    ll ret = 1;
    rep(i, n - m + 1, n)
        ret *= i;
    rep(i, 2, m)
        ret /= i;
    return ret;
}

/*
3.乘法逆元
可以取模,适用于P比较大的题目
所需空间O(n),时间:预处理O(n),查询O(1)
*/
//N的范围需要根据题目确定
int fac[N+5],inv[N+5];
ll qpow(ll bsc,ll y){
	ll ret = 1;
	while(y){
		if(y&1) ret = ret*bsc%mod;
		bsc = bsc*bsc%mod;
		y >>= 1;
	}
	return ret;
}
void init(){
	fac[0] = 1;
	for(int i=1;i<=N;i++)
		fac[i] = (ll)fac[i-1]*i%mod;
	inv[N] = qpow(fac[N],mod-2);
	for(int i=N-1;i>=0;i--)
		inv[i] = (ll)inv[i+1]*(i+1)%mod;
}
int C(int n,int m){
	if(m>n) return 0;
	return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;
}

/*
4.Lucas定理
模数必须是质数,n比较大,p比较小,不能通过预处理阶乘和逆元来计算
lucas(n,m,p)返回C(n,m)对p取模的结果
*/
ll f[N],rf[N];
ll mul(ll x,ll y,ll p){
    return (x*y-(ll)(x/(long double)p*y+1e-3)*p+p)%p;
}
ll pow(ll a,ll b,ll p){
    ll t=1;
    for(;b;b>>=1,a=mul(a,a,p))
        if(b & 1) t=mul(t,a,p );
    return t;
}
//使用时为 init(p)
void init(int p){
    f[0]=1;
    for(int i=1;i<p;++i) f[i]=f[i-1]*i%p;
    rf[p-1]=pow(f[p-1],p-2,p);
    for(int i=p-1;i;i--) rf[i-1]=rf[i]*i%p;
}
ll C(int n,int m,int mod){
    if(m>n||m<0||n<0) return 0;
    return f[n]*rf[m]%mod*rf[n-m]%mod;
}
ll lucas(ll n,ll m,ll p){
    if(n<m) return 0;
    if(!m || n==m)  return 1;
    return C(n%p,m%p,p) *lucas(n/p,m/p,p )%p;
}