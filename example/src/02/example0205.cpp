#include <stdio.h>

/*
==>
使用内联函数替换宏定义
    宏定义一行代码，多步执行，导致++a执行多次，结果与想象的不一致。
<==
*/
#define FUNC(a, b) ((a) < (b) ? (a) : (b))

inline int func(int a, int b)
{
    return a < b ? a : b;
}

/*
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/02$ g++ example0205.cpp
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/02$ ./a.out
a = 2
b = 3
c = 2

a = 3
b = 3
c = 3
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/02$
*/
int main()
{

    int a = 1;
    int b = 3;

    int c = func(++a, b);

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    // ((2) < (3) ? 3 : 3)
    c = FUNC(++a, b);

    printf("\na = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    return 0;
}