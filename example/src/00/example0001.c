#include <stdio.h>

/*
==>
1、C语言中，const使得变量具有只读属性(array[const int]：不可行)
2、const将具有全局生命周期的变量存储于只读存储区
3、const不能定义真正意义上的常量

tip：
    c语言真正意义上的常量只有枚举
<==
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/00$ gcc ./example0001.c
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/00$ ./a.out 
Begin...
c = 0
*p = 0
c = 5
*p = 5
End...
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/00$ 
*/
int main()
{
    const int c = 0;
    int *p = (int *)&c;

    printf("Begin...\n");

    printf("c = %d\n", c);
    printf("*p = %d\n", *p);

    *p = 5;

    // c = 5，说明在c语言中，const不能定义真正意义上的常量，可以被间接改变
    // 变量c不能直接改变，是由于变量c只具有只读属性，所以不能为左值
    printf("c = %d\n", c);
    printf("*p = %d\n", *p);

    p++;

    printf("End...\n");

    return 0;
}