/*
Dijkstra算法+堆优化,复杂度为 O(ElogE)
注意初始化
权值必须是非负
*/
const int N=100010,M=1000010;
int head[N],ver[M],edge[M],Next[M],d[N];
bool v[N];
int n,m,tot;
//大根堆(优先队列),pair的第二维为节点编号
//pair的第一维为dist的相反数(利用相反数变成小根堆)
priority_queue<pair<int,int> > q;
void add(int x,int y,int z){
    ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}
void dijkstra(){
    memset(d,0x3f,sizeof(d));//dist数组
    memset(v,0,sizeof(v));//节点标记
    //起始点为1,若更改要改两处
    d[1]=0;
    q.push(make_pair(0,1));
    while(q.size()){
        int x=q.top().second;q.pop();
        if(v[x]) continue;
        v[x]=1;
        for(int i=head[x];i;i=Next[i]){
            int y=ver[i],z=edge[i];
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        //如果是无向图还要 add(y,x,z)
        add(x,y,z);
    }
    dijkstra();
    //求单源最短路
    for(int i=1;i<=n;++i)
        printf("%d\n",d[i]);
    return 0;
}
