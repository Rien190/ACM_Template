const int MAXN = 100010;
const double eps = 1e-8;
const double INF = 1e20;
struct Point{
	double x,y;
	void input(){
		scanf("%lf%lf",&x,&y);
	}
};
double dist(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
Point p[MAXN];
Point tmpt[MAXN];
bool cmpx(Point a,Point b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cmpy(Point a,Point b){
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}
double Closest_Pair(int left,int right){
	double d = INF;
	if(left == right)return d;
	if(left+1 == right)return dist(p[left],p[right]);
	int mid = (left+right)/2;
	double d1 = Closest_Pair(left,mid);
	double d2 = Closest_Pair(mid+1,right);
	d = min(d1,d2);
	int cnt = 0;
	for(int i = left;i <= right;i++){
		if(fabs(p[mid].x - p[i].x) <= d)
			tmpt[cnt++] = p[i];
	}
	sort(tmpt,tmpt+cnt,cmpy);
	for(int i = 0;i < cnt;i++){
		for(int j = i+1;j < cnt && tmpt[j].y - tmpt[i].y < d;j++)
			d = min(d,dist(tmpt[i],tmpt[j]));
	}
	return d;
}
int main(){
	int n;
	while(scanf("%d",&n) == 1 && n){
		for(int i = 0;i < n;i++)p[i].input(); //输入点的坐标
		sort(p,p+n,cmpx);
		printf("%.2lf\n",Closest_Pair(0,n-1)); //返回平面最近点对之间的距离
	}
    return 0;
}