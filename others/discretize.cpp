/*
对于包含重复元素，并且相同元素离散化后也要相同
例:
a:7 4 7 3 4 10
b:3 2 3 1 2 4
m=4
*/
const int maxn=1e5+10;
int a[maxn], t[maxn], b[maxn];
int main(){
	int n;scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]),t[i]=a[i];
	sort(t+1,t+n+1);
	int m=unique(t+1,t+1+n)-t-1;//求出的m为不重复的元素的个数
	for(int i=1; i<=n; i++)
		b[i]=lower_bound(t+1,t+1+m,a[i])-t;
	return 0;
}

/*
较上一种复杂度低
对于:
1.包含重复元素，并且相同元素离散化后不相同
2.不包含重复元素，并且不同元素离散化后不同
例:
a:7 4 7 3 4 10
b:4 2 5 1 3 6
*/
struct A
{
    int x, idx;
    bool operator < (const A &rhs) const
    {
        return x < rhs.x;
    }
};
A a[N];
int b[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i].x);
		a[i].idx = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
    	b[a[i].idx] = i;
	return 0;
}