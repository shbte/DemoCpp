#include <iostream>

/*
==>
C方式强制类型转换存在的问题
    过于粗暴：任意类型之间都可以进行转换，编译器很难判断其正确性
    难于定位：在源码中无法快速定位所有使用强制类型转换的语句
C++是强类型语言
    强制类型转换：static_cast、const_cast、dynamic_cast、reinterpret_cast
    static_cast
        用于基本类型间的转换
        不能用于基于类型指针间的转换
        用于有继承关系类对象之间的转换和类指针之间的转换
    const_cast
        用于去除变量的只读属性
        强制转换的目标类型必须是指针或引用
    reinterpret_cast
        用于指针类型间的强制转换
        用于整数和指针类型间的强制转换
    dynamic_cast
        用于有继承关系的类指针间的转换
        用于有交叉关系的类指针间的转换
        具有类型检查的功能
        需要虚函数的支持
<==
*/
int main()
{
    return 0;
}