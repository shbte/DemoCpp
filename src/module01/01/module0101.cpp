#include <stdio.h>

/*
==>
C++语言中，引用的概念，相当于别名
<==
*/
void swap1(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// c++语言新特征：引用
void swap2(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

/*
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/src/module01/01$ g++ ./module0101.cpp
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/src/module01/01$ ./a.out
a = 2, b = 1
a = 1, b = 2
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/src/module01/01$
*/
int main()
{
    int a = 1;
    int b = 2;

    swap1(&a, &b);

    printf("a = %d, b = %d\n", a, b);

    swap2(a, b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}