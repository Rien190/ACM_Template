/*
Prim求MST
耗费矩阵cost[][],标号从0开始,0~n-1注意注意!!!
返回最小生成树的权值,返回-1则表示原图不连通
*/
const int INF=0x3f3f3f3f;
const int MAXN=110;
bool vis[MAXN];
int lowc[MAXN];
//点从0到n-1
int Prim(int cost[][MAXN],int n){
    int ans=0;
    memset(vis,0,sizeof vis);
    vis[0]=true;
    for(int i=1;i<n;++i)   lowc[i]=cost[0][i];
    for(int i=1;i<n;++i){
        int minc=INF;
        int p=-1;
        for(int j=0;j<n;++j){
            if(!vis[j]&&minc>lowc[j]){
                minc=lowc[j];
                p=j;
            }
        }
        if(minc==INF) return -1;//原图不连通
        ans+=minc;
        vis[p]=true;
        for(int j=0;j<n;++j){
            if(!vis[j] && lowc[j]>cost[p][j])
                lowc[j]=cost[p][j];
        }
    }
    return ans;
}
int main()
{
    int cost[MAXN][MAXN];
    //注意对耗费矩阵赋初值,memset只能读1个字符,这样和都赋给INF结果一样
    memset(cost,0x3f,sizeof(cost));
    while (k--){
        int u,v,w;
        cin>>u>>v>>w;
        //读入数据,注意题目给出的节点是否从0开始且无向边要两次赋值
        u--;
        v--;
        cost[u][v]=w;
        cost[v][u]=w;
    }
    cout<<Prim(cost,n)<<endl;
    return 0;
}