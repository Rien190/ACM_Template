/*
BIT 一维树状数组
*/
const int N=1000005;
ll tree[N],a[N],b[N];
int n,m,op,l,r,v;
//单点修改区间查询
void add(int p,int x){
    for(int i=p;i<=n;i+=i&-i)
        tree[i]+=x;
}
ll query(int p){
    ll ret=0;
    for(int i=p;i;i-=i&-i)
        ret+=tree[i];
    return ret;
}
int main(){
    //读入数据
    for(int i=1;i<=n;++i){
        cin>>v;
        add(i,v);
    }
    add(l,v);//将第l个数加上v
    cout<<query(r)-query(l-1)<<endl;//询问[l-r]区间的和
    return 0;
}

//区间修改单点查询
void add(int p,int x){
    for(int i=p;i<=n;i+=i&-i)
        tree[i]+=x;
}
ll query(int p){
    ll ret=0;
    for(int i=p;i;i-=i&-i)
        ret+=tree[i];
    return ret;
}
int main(){
    //读入数据,维护差分数组
    for(int i=1;i<=n;++i){
        cin>>a[i];
        add(i,a[i]-a[i-1]);
    }
    add(l,v),add(r+1,-v);//将[l-r]加上v
    cout<<query(l)<<endl//询问第l个数的值
    return 0;
}

//区间修改区间查询
void add(int p,int x){
    for(int i=p;i<=n;i+=i&-i){
        b[i]+=(ll)x;
        tree[i]+=(ll)p*x;
    }
}
ll query(int p){
    ll ret=0;
    for(int i=p;i;i-=i&-i)
        ret+=1ll*(p+1)*b[i]-tree[i];
    return ret;
}
int main(){
    //读入数据,维护差分数组
    for(int i=1;i<=n;++i){
        cin>>a[i];
        add(i,a[i]-a[i-1]);
    }
    add(l,v),add(r+1,-v);//将[l-r]加上v
    cout<<query(r)-query(l-1)<<endl;//询问[l-r]区间的和
    return 0;
}