#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define ull unsigned long long
#define ld long double
#define rep(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
template <typename T> T &read(T &r) {
    r = 0; bool w = 0; char ch = getchar();
    while(ch < '0' || ch > '9') w = ch == '-' ? 1 : 0, ch = getchar();
    while(ch >= '0' && ch <= '9') r = (r << 3) + (r <<1) + (ch ^ 48), ch = getchar();
    return r = w ? -r : r;
}
ll mod=1e9+7;
ll INF=1e15;
ll Inf=0x3f3f3f3f;
double pi=acos(-1.0);


int  main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}