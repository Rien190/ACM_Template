/*printf一些用法:
%d:输出int
%lld:输出long long
%lf:输出double
%.3lf:输出四舍五入保留3位小数
%3d:输出3位整型数, 不够3位右对齐
%-3d:输出3位整型数, 不够3位左对齐
%9.2f:输出场宽为9的浮点数, 其中小数位为2, 整数位为7,小数点占一位, 不够9位右对齐。
%8s:输出8个字符的字符串, 不够8个字符右对齐。
*/
/*
例题:题目的输入形式为
1
00:00:00,498 –> 00:00:02,827
- Here's what I love most
about food and diet.

2
00:00:02,827 –> 00:00:06,383
We all eat several times a day,

3
00:00:06,383 –> 00:00:09,427
of what goes on our plate
and what stays off.
*/

/*
要求1:是把每个输入的第二行加上一个数
对于第二行的输入和输入可以使用以下形式:
*/
scanf("%d:%d:%d,%d",&a,&b,&c,&d);
solve(a,b,c,d);//计算加上一个数
printf("%02d:%02d:%02d,%03d --> ",a,b,c,d);
scanf(" --> %d:%d:%d,%d",&a,&b,&c,&d);
solve(a,b,c,d);
printf("%02d:%02d:%02d,%03d",a,b,c,d);

/*
要求2:之后的输入可能有多行,按输入输出即可
用如下方式处理可能的输入
*/
while(getline(cin,s)){
    if(s==kk)//预先处理终止条件
        break;
    else
        cout<<s<<endl;
}