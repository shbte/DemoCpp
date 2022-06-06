#include <iostream>

/*
==>
C++的类中可以定义一个特殊的清理函数
    这个特殊的清理函数叫做析构函数
    析构函数的功能与构造函数相反

定义：~ClassName()
    析构函数没有参数也没有返回值类型声明
    析构函数在对象销毁时自动被调用

析构函数的定义准则
    当类中自定义了构造函数，并且构造函数中使用了系统资源(如:内存申请，文件打开等)，则需要自定义析构函数

析构函数的执行顺序和构造函数的顺序相反
    有delete，优先delete
<==
*/
class A
{
private:
    int m_i = 0;

public:
    A()
    {
        std::cout << "A()::m_i=" << m_i << std::endl;
    }

    A(int i)
    {
        m_i = i;
        std::cout << "A(int i)::m_i=" << m_i << std::endl;
    }

    ~A()
    {
        std::cout << "~A() : m_i=" << m_i << std::endl;
    }

    void printMI()
    {
        std::cout << "printMI::m_i=" << m_i << std::endl;
    }
};

A getA()
{
    return A(5);
}

int main()
{
    A a1(2);

    A().printMI(); // 直接调用构造函数时会产生一个临时对象，该临时对象的有效范围只有这行，下行执行析构函数进行销毁
    A(10).printMI(); // 直接调用构造函数时会产生一个临时对象，该临时对象的有效范围只有这行，下行执行析构函数进行销毁

    A *p = new A(3);

    A a3;

    delete p;

    A(6);

    A a5 = getA(); // ==> A a5 = A(5); ==> A a5(5);当代的g++编译器在不影响最终结果的前提下，尽量的避免临时对象的产生

    A a4 = A(4); // ==> A a4(4); 这里并没有产生临时对象，因为编译器对其进行了效率优化

    return 0;
}