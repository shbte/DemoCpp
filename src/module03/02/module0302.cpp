#include <iostream>

/*
==>
无参构造函数
    没有参数的构造函数
    当类中没有定义构造函数时，编译器默认提供一个无参构造函数，并且其函数体为空
拷贝构造函数
    参数为const class_name&的构造函数
    当类中没有定义拷贝构造函数时，编译器默认提供一个拷贝构造函数，简单的进行成员的值复制
    编译器提供的拷贝构造函数只进行浅拷贝
        浅拷贝：拷贝后对象的物理状态相同(两个对象的new指针指向同一个地址，可能会导致同一地址会被释放两次)
        深拷贝：拷贝后对象的逻辑状态相同
<==
*/
// 没有自定义无参构造函数和拷贝函数
class A
{
private:
    int m_i;
    int *m_p = new int(1);

public:
    int getI()
    {
        return m_i;
    }
    int *getP()
    {
        return m_p;
    }
};

// 自定义无参构造函数，没自定义拷贝函数
class B
{
private:
    int m_i;
    int *m_p = new int(1);

public:
    int getI()
    {
        return m_i;
    }
    int *getP()
    {
        return m_p;
    }
    B()
    {
        std::cout << "class B()" << std::endl;
    }
};

// 没自定义无参构造函数，自定义拷贝函数
class C
{
private:
    int m_i;
    int *m_p = new int;

public:
    int getI()
    {
        return m_i;
    }
    int *getP()
    {
        return m_p;
    }
    C(const C &t)
    {
        std::cout << "class C(const C& t)" << std::endl;
    }
};

int main()
{

    A a1;
    A a2;
    // a1.m_i=6, *a1.m_p=1, a1.m_p=0x55a58a781eb0
    std::cout << "a1.m_i=" << a1.getI() << ", *a1.m_p=" << *a1.getP() << ", a1.m_p=" << a1.getP() << std::endl;
    // a2.m_i=-2042446624, *a2.m_p=1, a2.m_p=0x55a58a781ed0
    std::cout << "a2.m_i=" << a2.getI() << ", *a2.m_p=" << *a2.getP() << ", a2.m_p=" << a2.getP() << std::endl;
    A a3(a1);
    // a3.m_i=6, *a3.m_p=1, a3.m_p=0x55a58a781eb0
    std::cout << "a3.m_i=" << a3.getI() << ", *a3.m_p=" << *a3.getP() << ", a3.m_p=" << a3.getP() << std::endl;

    B b1;
    B b2(b1);
    // class B()
    // b1.m_i=-2040123200, *b1.m_p=1, b1.m_p=0x55a58a782300
    std::cout << "b1.m_i=" << b1.getI() << ", *b1.m_p=" << *b1.getP() << ", b1.m_p=" << b1.getP() << std::endl;
    // b2.m_i=-2040123200, *b2.m_p=1, b2.m_p=0x55a58a782300
    std::cout << "b2.m_i=" << b2.getI() << ", *b2.m_p=" << *b2.getP() << ", b2.m_p=" << b2.getP() << std::endl;

    // 类 "C" 不存在默认构造函数
    // C c1;

    return 0;
}