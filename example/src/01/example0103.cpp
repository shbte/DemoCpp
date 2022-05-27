#include <stdio.h>

/*
==>
C++语言中，const把变量和常量值变为只读变量，但是可以使用指针法还改变const的值
tip:
    const不止可以修饰变量，也可以修饰常量值
<==
*/
void test1()
{
    int a = 4;
    const int &b = a;
    int *p = (int *)&b;

    printf("int a = %d, const int& b = %d, int *p = %d\n", a, b, *p);

    a = 5;

    printf("int a = %d, const int& b = %d, int *p = %d\n", a, b, *p);

    // 报错信息：表达式必须是可修改的左值
    // 变量b被const修饰，不能被再被修改
    // b = 6;

    *p = 7;

    printf("int a = %d, const int& b = %d, int *p = %d\n", a, b, *p);
}

void test2()
{
    const int &b = 1;
    int *p = (int *)&b;

    printf("const int& b = %d, int *p = %d\n", b, *p);

    // 报错信息：表达式必须是可修改的左值
    // 变量b被const修饰，不能被再被修改
    // b = 6;

    *p = 7;

    printf("const int& b = %d, int *p = %d\n", b, *p);
}

/*
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/01$ g++ ./example0103.cpp
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/01$ ./a.out
int a = 4, const int& b = 4, int *p = 4
int a = 5, const int& b = 5, int *p = 5
int a = 7, const int& b = 7, int *p = 7
const int& b = 1, int *p = 1
const int& b = 7, int *p = 7
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/01$
*/
int main()
{
    test1();
    test2();

    return 0;
}