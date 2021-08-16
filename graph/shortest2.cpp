/*
单源最短路 bellman_ford 算法,复杂度 O(VE)
可以处理负边权图
可以判断是否存在负环回路.
返回true:当且仅当图中不包含从源点可达的负权回路
vector<Edge> E;先 E.clear() 初始化,然后加入所有边
点的编号从1开始
*/
const int INF=0x3f3f3f3f;
const int N=2550;
int dist[N];
struct Edge
{
    int u,v;
    int cost;
    Edge(int _u=0,int _v=0,int _cost=0):u(_u),v(_v),cost(_cost){}
};
vector<Edge>E;
//点的编号从1开始
void addedge(int u,int v,int w){
    E.push_back(Edge(u,v,w));
}
bool bellman_ford(int start,int n){
    for(int i=1;i<=n;++i)   dist[i]=INF;
    dist[start]=0;
    for(int i=1;i<n;++i){
        bool flag=false;
        for(int j=0;j<E.size();j++){
            int u=E[j].u;
            int v=E[j].v;
            int cost=E[j].cost;
            if(dist[v]>dist[u]+cost){
                dist[v]=dist[u]+cost;
                flag=true;
            }
        }
        if(!flag) return true;//没有负环回路
    }
    for(int j=0;j<E.size();j++)
        if(dist[E[j].v]>dist[E[j].u]+E[j].cost)
            return false;//有负环回路
    return true;//没有负环回路
}
int main()
{
    int n,m;cin>>n>>m;
    E.clear();
    for(int i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
        addedge(y,x,z);
    }
    bellman_ford(s,n);
    for(int i=1;i<=n;++i)
        printf("%d\n",dist[i]);
    return 0;
}
