/*
01trie树
在一组数中找跟某个数异或结果最大的数
*/
const int MAXN=100005;
//MAXN右移需根据题目判断,如数据范围为int则*32即右移5位
int val[MAXN<<5];       //val[i]=j表示编号为i的节点的值为j
int cnt;                //节点数量
int tree[MAXN<<5][2];   //tree[i][0]=j表示编号为i的节点的0子节点的编号为j
void init(){
    cnt=1;
    tree[0][0]=tree[0][1]=0;
}
void insert(int x){
    int v,u=0;
    for(int i=31;i>=0;--i){
        v=(x>>i)&1;
        if(!tree[u][v]){
            tree[cnt][0]=tree[cnt][1]=0;//初始化新节点的子节点
            val[cnt]=0;                 //节点值为0，表示到此不是一个数
            tree[u][v]=cnt++;           //指向该节点
        }
        u=tree[u][v];//到下一节点
    }
    val[u]=x;
}
int query(int x){
    int v,u=0;
    for(int i=31;i>=0;i--){
        v=(x>>i)&1;
        if(tree[u][v^1])//利用贪心策略，优先寻找和当前位不同的数
            u=tree[u][v^1];
        else
            u=tree[u][v];
    }
    return val[u];
}
int  main(){
    int n,m;scanf("%d%d",&n,&m);
    init();
    int tmp;
    for(int i=0;i<n;++i){
        scanf("%d",&tmp);
        insert(tmp);
    }
    for(int i=0;i<m;++i){
        scanf("%d",&tmp);
        printf("%d\n",query(tmp));
    }
    return 0;
}