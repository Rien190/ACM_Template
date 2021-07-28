/*
Next[]的含义:x[i-Next[i]...i-1]=x[0...Next[i]-1]
Next[i]为满足:x[i-z...i-1]=x[0...z-1]的最大值
*/
void kmp_pre(char x[],int m,int next[]){
    int i,j;
    j=next[0]=-1;
    i=0;
    while(i<m){
        while(-1!=j && x[i]!=x[j])
            j=next[j];
        next[++i]=++j;
    }
}
const int N=1000005;
int Next[N];
/*
  返回x在y中出现的次数,可以重叠
  y是主串,x是模式串
*/
int KMP_Count(char x[],int m,char y[], int n){
    int i,j;
    int ans=0;
    kmp_pre(x,m,Next);
    i=j=0;
    while(i<n){
        while(-1!=j && y[i]!=x[j])
            j=Next[j];
        i++;j++;
        if(j>=m){
            ans++;
            j=Next[j];
        }
    }
    return ans;
}