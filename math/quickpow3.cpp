/*
一种想法是用类似类似2进制加法的方法实现乘法,复杂度为O(log)
另一种就是用 long double 来进行优化取模运算。因为它其实很巧妙的运用了自动溢出这个操作，我们的代码中的z就表示 ⌊x×y/p⌋ ，所以我们要求的就变成了 x×y−⌊x×y/p⌋×p ，虽然这两个部分都是会溢出的，但（unsigned）保证了它们溢出后的差值基本不变，所以即使它会溢出也不会影响最终结果的！
*/
inline ll ksc(ll x,ll y,ll p){
	ll z=(ld)x/p*y;
	ll res=(ull)x*y-(ull)z*p;
	return (res+p)%p;
}
// ll 表示 long long
// ld 表示 long double
// ull 表示 unsigned long long
// 一种自动溢出的数据类型（存满了就会自动变为0）