#include <iostream>

#include "IntArray.h"

/*
==>
对象的定义和对象的声明是不同的
    对象的定义：申请对象的空间并调用构造函数
    对象的声明：告诉编译器存在这样一个对象
<==
*/
int main()
{

    IntArray a(6);

    a.outArray();

    a.setVaule(4, 9);

    int value = 0;
    bool ret = false;
    ret = a.getValue(4, value);
    if (ret)
    {
        std::cout << "a[4]=" << value << std::endl;
    }
    ret = a.getValue(10, value);
    if (ret)
    {
        std::cout << "a[10]=" << value << std::endl;
    }

    a.outArray();

    IntArray b(a);
    IntArray c = a; // 也是调用拷贝构造函数
    a.free();
    b.free();
    c.free();
    a.outArray();

    return 0;
}
