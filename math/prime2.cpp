/*
Eratosthenes筛法
*/
const int N=1e5+5;
bool v[N];//值为false表示质数,为true为合数
int prime[N];//存储素数
int cnt;
void primes(int n){//筛选小于n的素数
    memset(v,0,sizeof(v));
    for(int i=2;i<=n;++i){
        if(v[i]==0){
            prime[++cnt]=i;
            for(int j=i; i*j<=n; j++)
                v[i*j] = true;
        }
    }
}

/*
线性筛
*/
const int N=1e8+5;
bool v[N];//值为false表示质数,为true为合数
int prime[N/10];//存储素数
int cnt;
void primes(int n){//筛选小于n的素数
    memset(v,0,sizeof(v));
    for(int i=2; i<=n; i++){
		if(v[i]==false)
			prime[++cnt] = i ;
		for(int j=1; j<=cnt&&i*prime[j]<=n; j++){
			v[i*prime[j]] = true ;
			if(i%prime[j]==0)
				break;
		}
	}
}