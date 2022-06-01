#include <iostream>

/*
==>
C++中提供了初始化列表对成员变量进行初始化，初始化列表先于构造函数执行
语法规则
    ClassName::ClassName() : mv(v1), m2(v1, v2), m3(v3)
    {
        //some other initialize operation
    }

初始化与赋值不同
    初始化：对正在创建的对象进行初值设置
    赋值：对已经存在的对象进行值设置

全局对象的构造顺序是不确定的(不同编译平台不同)，所以在开发中要尽量避免全局对象间的相互依赖

注意事项：
    成员的初始化顺序与成员的声明顺序相同
    成员的初始化顺序与初始化列表中的位置无关
    初始化列表先于构造函数的函数体执行
<==
*/
class B
{
private:
    int m_i = 0;

public:
    B(int i)
    {
        std::cout << "B(int " << i << ")" << std::endl;
        m_i = i;
    }

    int getI()
    {
        return m_i;
    }
};

class A
{
private:
    const int ci1;
    const int ci2 = 2; // 第一种赋值方式

    int i1 = 4;

    B b1;
    B b2;
    B b3;

public:
    A() : ci1(10), b2(2), b1(1), b3(3) // 第二种赋值方式，赋值顺序：ci1、b1、b2、b3
    {
        std::cout << "i1=" << i1 << std::endl;
    }

    void setCi1(int i) // 第三种赋值方式
    {
        int *p = const_cast<int *>(&ci1);
        *p = i;
    }

    int getCi1()
    {
        return ci1;
    }

    int getCi2()
    {
        return ci2;
    }

    int getI()
    {
        return i1;
    }

    B getB1()
    {
        return b1;
    }

    B getB2()
    {
        return b2;
    }

    // B getB3()
    // {
    //     return b3;
    // }
};

int main()
{
    A a1;
    std::cout << "ci1=" << a1.getCi1() << std::endl;
    a1.setCi1(100);
    std::cout << "ci1=" << a1.getCi1() << std::endl;

    std::cout << "ci2=" << a1.getCi2() << std::endl;
    std::cout << "i1=" << a1.getI() << std::endl;

    std::cout << "b1::m_i=" << a1.getB1().getI() << std::endl;
    std::cout << "b2::m_i=" << a1.getB2().getI() << std::endl;
    // std::cout << "b3::m_i=" << a1.getB3().getI() << std::endl;

    B b4(4);

    return 0;
}