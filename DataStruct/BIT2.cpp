//树状数组求逆序对
void modify(int x, int d){
	for(int i = x; i <= n; i += i&-i)c[i] += d;
}
int getsum(int x){
	int sum = 0;
	for(int i = x; i >= 1; i -= i&-i)sum += c[i];
	return sum;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d", &x);
		ans += getsum(n) - getsum(x);
		modify(x, 1);
	}
}