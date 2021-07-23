/*
悬线法求最大全1子矩阵
*/
const int MAXN=2005;
char x[MAXN][MAXN];
int y[MAXN][MAXN],l[MAXN][MAXN],r[MAXN][MAXN],up[MAXN][MAXN];
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>x[i][j];
            //将输入处理成01矩阵
            if(x[i][j]=='F'){
                //此处赋值需注意,只有1处才赋值,否则全0矩阵也会输出面积为1
                y[i][j]=1;
                l[i][j]=j;
                r[i][j]=j;
                up[i][j]=1;
            }
            else
                y[i][j]=0;
        }
    }
    //按行处理
    for(int i=1;i<=n;++i){
        for(int j=2;j<=m;++j){
            if(y[i][j-1] && y[i][j])
                l[i][j]=l[i][j-1];
        }
        for(int j=m-1;j>=1;--j){
            if(y[i][j+1] && y[i][j])
                r[i][j]=r[i][j+1];
        }
    }
    int len,ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            //i>1很关键,用于处理只有1行的情况
            if(i>1 && y[i-1][j] && y[i][j]){
                up[i][j]=up[i-1][j]+1;
                l[i][j]=max(l[i][j],l[i-1][j]);
                r[i][j]=min(r[i][j],r[i-1][j]);
            }
            len=r[i][j]-l[i][j]+1;
            ans=max(ans,len*up[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}