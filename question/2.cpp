/*
example:
input:
5 2
1 2 3 4 5
ouput:
9
solution:
单调队列维护前缀和
*/
const int N=5e5+5;
int a[N],dequeue[N],s[N];
void ac(){
	int n,k;scanf("%d%d",&n,&k);
	int ans=-1;
	for(int i=1;i<=n;++i)
		read(a[i]),s[i]=s[i-1]+a[i],ans=max(ans,a[i]);
	int tail=0,head=1;
	dequeue[++tail]=0;//便于处理前缀和
	for(int i=1;i<=n;++i){
		while(head<=tail && dequeue[head]<i-k)
			head++;
        /*ans和队尾元素出队需要根据题意决定,因为之前已经算过
        只有一个元素的情况,所以不能让所有元素出队*/
		ans=max(ans,s[i]-s[dequeue[head]]);
		while(head<=tail && s[dequeue[tail]]>=s[i])
			tail--;
		dequeue[++tail]=i;
	}
	printf("%d",ans);
}
