#include <stdio.h>

/*
==>
1、C++语言中，当碰见const声明时，将常量放入符号表(array[const int]：可行)
2、后续使用常量时，则直接在符号表中的寻找值(符号表中的值不变，但是空间的值却变了)
3、对const常量使用&( || 使用extern修饰在其它文件使用)时，才会分配空间

tip：
    C++语言中，const修饰的是真正意义的常量，存放在编译器的符号表中。
    const常量去符号表中取值，指针去常量空间找值。

    const常量和define(宏定义)不一样
        const常量由编译器处理，进行类型检查和作用域检查
        define由预处理器处理，单纯的文本替换
<==
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/00$ g++ ./example0001.cpp 
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/00$ ./a.out 
Begin...
c = 0
*p = 0
c = 0
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

    // c = 0 && *p = 5，说明c++语言虽然为const常量分配空间，但变量不会使用其存储空间内的值
    printf("c = %d\n", c);
    printf("*p = %d\n", *p);

    printf("End...\n");

    return 0;
}