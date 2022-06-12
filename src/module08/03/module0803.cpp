#include <iostream>

#include "operator.h"

using namespace std;

/*
==>
类模板
    一些类主要用于存储和组织数据元素
    类中数据组织的方式和数据元素的具体类型无关
    如：数组类，链表类，Stack类，Queue类等

C++中将模板的思想应用于类，使得类的实现不关注数据元素的具体类型，而只关注类所需要实现的功能

C++中的类模板
    以相同的方式处理不同的类型
    在类声明前使用template进行标识
    <template T>用于说明类总使用的泛指类型T
    template <typename T>
    class Operator
    {
    public:
        T op(T a, T b);
    };

类模板的工程应用
    类模板必须在头文件中定义
    类模板不能分开实现在不同的文件中
    类模板外部定义的成员函数需要加上模板<>声明

小结：
    泛型编程的思想可以应用于类
    类模板以相同的方式处理不同类型的数据
    类模板非常适用于编写数据结构相关的代码
    类模板在使用时只能显式指定类型
<==
*/
// 实现string类的减法操作符，类只会默认实现赋值操作符(operator=)，其它操作符需要自己手动实现
string operator-(string &l, string &r)
{
    return "Minus";
}

// 实现string类的乘法操作符，类只会默认实现赋值操作符(operator=)，其它操作符需要自己手动实现
string operator*(string &l, string &r)
{
    return "Multiply";
}

int main()
{
    int a = 10;
    int b = 5;
    Operator<int> op1; // 类模板需要显式指定类型，例：<int>

    cout << "a + b = " << op1.add(a, b) << endl;      // a + b = 15
    cout << "a - b = " << op1.minus(a, b) << endl;    // a - b = 5
    cout << "a * b = " << op1.multiply(a, b) << endl; // a * b = 50
    cout << "a / b = " << op1.divide(a, b) << endl;   // a / b = 2

    string c = "D.T.";
    string d = "Software";
    Operator<string> op2;
    // 编译器自动实现类的加法操作符
    cout << "D.T. + Software = " << op2.add(c, d) << endl; // D.T. + Software = D.T.Software
    // 手动实现了string类的减法操作符
    cout << "D.T. - Software = " << op2.minus(c, d) << endl; // D.T. - Software = Minus
    // 手动实现了string类的乘法操作符
    cout << "D.T. * Software = " << op2.multiply(c, d) << endl; // D.T. * Software = Multiply
    // 报错，因为没定义string类的除法操作符
    // cout << "D.T. * Software = " << op2.divide(c, d) << endl;

    return 0;
}