#include <iostream>

/*
==>
函数重载是C++中引入的概念
函数重载用于模拟自然语言中的词汇搭配
函数重载使得C++具有更丰富的词义表达能力
函数重载的本质为相互独立的不同函数
C++中通过函数名和函数参数确定函数调用，与函数返回值没有关系

函数重载通过函数列表区分不同的同名函数
函数重载必然发生在同一个作用域中，不在同一个作用域内的同名函数不会发生重载

编译器需要用参数列表或函数类型进行函数选择
无法直接通过函数名得到重载函数的入口地址

C++编译器不能以C的方式编译重载函数
编译方式决定函数名被编译后的最终目标名(nm xxx.o)
    C++编译方式将函数名和参数列表编译成目标名
    C编译方式只将函数名作为目标名进行编译
extern关键字能够实现C和C++的相互调用
<==
*/

#ifdef __cplusplus
extern "C"
{
#endif

// C编译器编译部分
#include "module0200.h"

#ifdef __cplusplus
}
#endif

int fun(int i)
{
    std::cout << "this is fun(int)" << std::endl;
    return i;
}
char func(int i)
{
    std::cout << "this is func(int)" << std::endl;
    return (char)i;
}
// 报错：无法重载仅按返回类型区分的函数
// double fun(int i)
// {
//     std::cout << "this is fun2(int)" << std::endl;
//     return i;
// }
int fun(int i, int j)
{
    std::cout << "this is fun(int, int)" << std::endl;
    return i + j;
}
int fun(int i, char c)
{
    std::cout << "this is fun(int, char)" << std::endl;
    return i;
}
int fun(char c, int i)
{
    std::cout << "this is fun(char, int)" << std::endl;
    return i;
}

/*
编译命令：先将c文件编译成二进制文件，然后再将c++和二进制文件一起编译，以达到C++和C的相互调用
    gcc -c ./module0200.c -o ./module0200.o
    g++ ./module0200.cpp ./module0200.o
    ./a.out 
*/
int main()
{

    // 重载函数只能通过同名函数的不同函数参数(个数、类型、顺序)来进行区分，与函数返回类型无关，与函数名有关

    // this is fun(int)
    fun(1);
    // this is func(int)
    func('2');
    // 个数区别
    // this is fun(int, int)
    fun(1, 2);
    // 类型区别
    // this is fun(int, char)
    fun(1, '2');
    // 顺序区别
    // this is fun(char, int)
    fun('2', 1);

    // 函数指针需要通过函数参数(个数、类型、顺序)和函数返回值来进行区分，与函数返回类型有关，与函数名无关
    // 重载函数是同名的不同的函数，重载函数之间的地址不一致

    // C++中的cout对象没有对函数指针作为输入参数的<<运算符重载，需要(void *)进行强转
    // int fun(int) address: 0x55f8a14ca2a7
    printf("int fun(int) address: %p\n", (int (*)(int, int))fun);

    // C++中的cout对象没有对函数指针作为输入参数的<<运算符重载，把输入参数fun当做了bool量处理
    // 解决办法：把函数指针进行强制类型转换为(void*)型
    // int fun(int) address: 1
    std::cout << "int fun(int) address: " << (int (*)(int))fun << std::endl;
    // int fun(int) address: 0x55f8a14ca229
    std::cout << "int fun(int) address: " << (void *)(int (*)(int))fun << std::endl;
    // 函数指针与函数参数、函数返回类型有关，与函数名无关
    // char func(int) address: 0x55f8a14ca268
    std::cout << "char func(int) address: " << (void *)(char (*)(int))func << std::endl;
    // int fun(int, int) address: 0x55f8a14ca2a7
    std::cout << "int fun(int, int) address: " << (void *)(int (*)(int, int))fun << std::endl;
    // int fun(int, char) address: 0x55f8a14ca2ee
    std::cout << "int fun(int, char) address: " << (void *)(int (*)(int, char))fun << std::endl;
    // int fun(char, int) address: 0x55f8a14ca332
    std::cout << "int fun(char, int) address: " << (void *)(int (*)(char, int))fun << std::endl;

    // c++调用c方法
    // RG_0 + ARG_1 + 3 + 4 = 14
    std::cout << "ARG_0 + ARG_1 + 3 + 4 = " << add(3, 4) << std::endl;

    return 0;
}