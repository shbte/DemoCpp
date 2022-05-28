#include <stdio.h>

/*
==>
C语言中，三目运算符的返回为值(而非变量本身)，不能作为左值使用
<==
*/
int main()
{
    int a = 1;
    int b = 2;

    // 报错信息：表达式必须是可修改的左值
    // (a < b ? a : b ) = 3;

    printf("a = %d, b = %d\n", a, b);
}