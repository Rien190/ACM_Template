/*
Floyd算法 计算任意两点间的距离 复杂度为 O(N^3)
*/
#define inf 0x3f3f3f3f
int dist[1000][1000];
int main()
{
    int k,i,j,n,m;///n表示顶点个数，m表示边的条数
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++){//初始化
        for(j=1; j<=n; j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=inf;
        }
    }
    int a,b,c;
    for(i=1; i<=m; i++){//有向图
        scanf("%d %d %d",&a,&b,&c);
        dist[a][b]=min(dist[a][b],c);
    }
    for(k=1; k<=n; k++){    //Floyd-Warshall算法核心语句
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    for(i=1; i<=n; i++){//输出最终的结果,最终二维数组中存的即使两点之间的最短距离
        for(j=1; j<=n; j++)
            printf("%10d",dist[i][j]);
        printf("\n");
    }
    return 0;
}