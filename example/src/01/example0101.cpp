#include <stdio.h>

/*
==>
C++语言中，三目运算符可直接返回变量本身
    可能返回的值存在常量值时，三目运算符不可作为左值使用

<==
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/01$ g++ ./example0101.cpp
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/01$ ./a.out
a = 3, b = 2
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/01$
*/
int main()
{
    int a = 1;
    int b = 2;

    // 三目运算符可直接返回变量本身
    (a < b ? a : b) = 3;

    // 报错信息：表达式必须是可修改的左值
    // 当返回值可能是常量值时，不能作为左值使用
    // (a < b ? 1 : b ) = 3;

    printf("a = %d, b = %d\n", a, b);
}