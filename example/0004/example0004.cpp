#include <iostream>

/*
==>
1 一般类静态成员函数不能调用非静态成员函数

答案是肯定的，由于static成员函数没有this指针，所以一般static成员函数是不能访问non-static成员的，包括成员函数和成员变量。

2 static成员函数可以调用构造函数吗？

由于构造函数特殊性，它从无到有构造一个对象，因此调用它不需要一个instance，也就是不需要this指针来调用，所以在static 函数中能调用构造函数。
o 构造函数分成两个阶段：
    1. 分配内存：这是从无到有阶段，该阶段结束，产生一个instance，也即this。
    2. 初始化内存：真正调用构造函数的部分。此时已经是对该instance调用构造函数，因此，可以调用任何非静态函数。
o 在静态函数中，只要是通过instance.Func()或者pointer->Func()的方式就可以调用非静态函数，因为显式指定了this。
因此提倡在所有非静态成员函数中显示使用this来使用成员。
-----------------------------------
static成员函数不能调用non-static成员函数
https://blog.51cto.com/u_15127513/3783216
<==
*/
class A
{
    int m_i;

public:
    static void callFun()
    {
        std::cout << "A:callFun()" << std::endl;

        // 静态成员函数调用全局函数func()
        func();
    }
};

void func()
{
    std::cout << "func()" << std::endl;
}

int main()
{

    A::callFun();

    return 0;
}