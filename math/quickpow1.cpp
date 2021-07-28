//a的b次方对p取余
//可能a,b都比较大,所以需要自己另写乘法
ll Mul(ll x,ll y,ll P){
    ll tmp=(x*y-(ll)((long double)x/P*y+1.0e-8)*P);
    return (tmp+P)%P;
}
ll ksm(ll a, ll b, ll p){
    ll ret=1;
    while(b){
        if(b&1) ret=Mul(ret,a,p);
        a=Mul(a,a,p);
        b>>=1;
    }
    return ret;
}