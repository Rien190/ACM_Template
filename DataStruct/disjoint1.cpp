/*
路径压缩并查集,
*/
const int N=1e5+5;
int fa[N];
void init(){
    for(int i=1;i<=N;++i)
        fa[i]=i;
}
int find(int x){
    int temp=x;
    while(temp!=fa[temp])
        temp=fa[temp];
    while(x!=fa[x]){
        x=fa[x];
        fa[x]=temp;
    }
    return temp;
}
void union(int x,int y){
    fa[find(x)]=find(y);
}
/*
按秩合并并查集,不破坏树形结构
连通块数量为block,大小为size
*/
int f[N],size[N],block;
void Init(){
    for(int i=1;i<=N;++i)
        f[i]=0;
    block=n;
}
int Find(int x){
    if(!f[x]) f[x]=x,size[x]=1;
    if(f[x]==x) return x;
    return f[x]=Find(f[x]);
}
void Union(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x=y) return ;
    if(size[x]>size[y]) swap(x,y);
    f[x]=y;
    size[y]+=size[x];
    block--;
}