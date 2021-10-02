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
const ll p = (ll)1e9 + 7;
ll pow(ll a, ll b, ll m){
    ll ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)ans = (ans % m) * (a % m) % m;
        b /= 2;
        a = (a % m) * (a % m) % m;
    }
    ans %= m;
    return ans;
}
ll inv(ll x, ll p)//x关于p的逆元，p为素数
{
    return pow(x, p - 2, p);
}
ll C(ll n, ll m, ll p)//组合数C(n, m) % p
{
    if(m > n)return 0;
    ll up = 1, down = 1;//分子分母;
    for(int i = n - m + 1; i <= n; i++)up = up * i % p;
    for(int i = 1; i <= m; i++)down = down * i % p;
    return up * inv(down, p) % p;
}
ll Lucas(ll n, ll m, ll p)
{
    if(m == 0)return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}
int main()
{
	long long n,m;
	while(~scanf("%lld%lld",&n,&m))
	{
		printf("%lld\n",Lucas(n,m,p));
	}
	return 0;
}
