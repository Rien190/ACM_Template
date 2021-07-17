//a的b次方对p取余
long long ksm(long long a,long long b,long long p)
{
	long long ret=1;
	while(b){
		if(b&1) ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret%p;
}