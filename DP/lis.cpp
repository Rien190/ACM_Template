/*
动态规划求最长上升子序列,复杂度为 O(nlogn)
*/
int DP(int n){
    int i,len,pos;
    b[1]=a[1];
    len=1;
    for(i=2;i<=n;++i){
        //a[i]大则可直接插到后面
        if(a[i]>=b[len]){
            len=len+1;
            b[len]=a[i];
        }
        //二分法在b数组中找出第一个比a[i]大的位置并让a[i]代替
        else {
            pos=lower_bound(b+1,b+1+len,a[i])-b;
            b[pos]=a[i];
        }
    }
    return len;
}