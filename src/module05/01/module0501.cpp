#include <iostream>

using namespace std;

/*
==>
逻辑操作符
    C++从语法上支持逻辑操作符重载
    重载后的逻辑操作符不满足短路法则
    工程开发中不要重载逻辑操作符
    通过重载比较操作符替换逻辑操作符重载
    通过专用成员函数替换逻辑操作符重载

逗号操作符
    在C++中重载逗号操作符是合法的
    使用全局函数对逗号操作符进行重载
    重载函数的参数必须有一个是类类型
    重载函数的返回值类型必须是引用

逻辑操作符(逗号操作符)重载后无法完全实现原生的语义
    1、短路法则完全失效。
    2、进入函数体前必须完成所有参数的计算。
    3、函数参数的计算次序时不定的。
<==
*/

class A
{
private:
    int m_i;

public:
    A(int i)
    {
        cout << "A(int i)::i=" << i << ", this = " << this << endl;

        this->m_i = i;
    }

    A(const A &a)
    {
        this->m_i = a.m_i;
        cout << "A::A(const A &a)::this = " << this << ", &a = " << &a << endl;
    }

    int value() const // const对象只能调用const成员函数
    {
        // cout << "A::value()" << endl;
        return this->m_i;
    }

    ~A()
    {
        cout << "~A()::m_i=" << this->m_i << ", this = " << this << endl;
    }
};

// 重载逻辑操作符&&
bool operator&&(const A &a1, const A &a2)
{
    cout << "operator&&::&a1 = " << &a1 << ", &a2 = " << &a2 << endl;
    return a1.value() && a2.value();
}

// 重载逻辑操作符||
bool operator||(const A &a1, const A &a2)
{
    cout << " operator||::&a1 = " << &a1 << ", &a2 = " << &a2 << endl;
    return a1.value() || a2.value();
}

// 重载逗号操作符
A &operator,(const A &a1, const A &a2)
{
    cout << "&operator,::&a1 = " << &a1 << ", &a2 = " << &a2 << endl;
    return const_cast<A &>(a2);
}

A fun(A a)
{
    cout << "func(A a)::a.m_i=" << a.value() << ", &a = " << &a << endl;

    return a;
}

int main()
{
    A a0(2);
    A a1(3);
    cout << endl;

    // 逻辑操作符重载后无法完全实现原生的语义
    // 1、短路法则完全失效。2、进入函数体前必须完成所有参数的计算。3、函数参数的计算次序时不定的。
    if (fun(a0) && fun(a1))
    {
        cout << "Result is true." << endl;
    }
    else
    {
        cout << "Result is false." << endl;
    }
    cout << endl;

    A a2 = (fun(a0), fun(a1));
    cout << "a2.value=" << a2.value() << endl;

    return 0;
}