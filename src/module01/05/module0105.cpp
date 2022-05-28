#include <iostream>

/*
==>
函数默认参数只能在函数声明中声明

    默认值从右向左提供

    函数调用是使用了默认值，则后续参数就必须使用默认值
<==
*/
int mul(int x = 0);

/*
void func() <==> void func(void)
在c语言中，左右不等价，左边可以放n个参数
在c++语言中，左右等价(因为c++是强类型语言的特性)

c++为了兼容c语言的这种情况，利用占位参数和参数默认值的结合体来兼容c语言中的不规范写法
*/
void func(int = 0, int = 0)
{
}

/*
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/src/module01/05$ g++ ./module0105.cpp
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/src/module01/05$ ./a.out
0
1
4
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/src/module01/05$
*/
int main()
{
    printf("%d\n", mul());
    printf("%d\n", mul(-1));
    printf("%d\n", mul(2));

    func();
    func(1, 2);

    return 0;
}

int mul(int x)
{
    return x * x;
}
