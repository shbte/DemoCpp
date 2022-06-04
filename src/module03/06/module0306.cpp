#include <iostream>

/*
==>
                    静态成员函数    普通成员函数
所有对象共享            Yes             Yes
隐含this指针            No             Yes
访问普通成员变量(函数)    No             Yes
访问静态成员变量(函数)   Yes             Yes
通过类名直接调用         Yes             No
通过对象名直接调用       Yes             Yes
<==
*/
void fun();

class A
{
private:
    int m_i = 0;
    long m_l = 10;
    static int s_i; // 静态成员变量不可以在类内进行初始化
    A(int a, int b)
    {
        std::cout << "A(int a, int b)" << std::endl;
    };
    void test(){};

public:
    A(int i);
    static int s_pi;
    void setMI(int i);
    int getMI();
    static void setML(A &a, long l);
    int getML();
    void setSI(int i);
    int getSI();
    ~A();
};

int A::s_i = 2; // 静态成员变量赋值
int A::s_pi = 3;

A::A(int i)
{
    m_i = i;
    std::cout << "A(int i):m_i=" << m_i << std::endl;
}

void A::setMI(int i)
{
    m_i = i;
}

int A::getMI()
{
    return m_i;
}

void A::setML(A &a, long l)
{
    // m_i; // 静态成员函数不能访问普通成员变量
    a.m_i; // 通过对象，静态成员函数可以访问普通成员变量

    A *tmpA1 = new A(1); // 静态成员函数可以直接访问私有构造函数
    A *tmpA2 = new A(1, 2); // 静态成员函数可以直接访问私有构造函数
    delete tmpA1;
    delete tmpA2;

    fun(); // 静态成员函数能直接访问全局函数，之前访问不到是因为所调用的全局函数写在了该函数后面，又没有提前声明，违背了从上而下的执行的特性

    // test(); // 静态成员函数不可以直接访问私有普通成员函数

    a.m_l = l;
}

int A::getML()
{
    return m_l;
}

void A::setSI(int i)
{
    s_i = i;
}

int A::getSI()
{
    return s_i;
}

A::~A()
{
    std::cout << "~A()" << std::endl;
}

void fun()
{
    std::cout << "G::fun()" << std::endl;
}

int main()
{
    fun();

    A a(3);
    std::cout << "m_i=" << a.getMI() << std::endl;
    a.setMI(5);
    std::cout << "m_i=" << a.getMI() << std::endl;

    std::cout << "m_l=" << a.getML() << std::endl;
    a.setML(a, 15);
    std::cout << "m_l=" << a.getML() << std::endl;
    // 静态成员函数可直接通过类名进行访问
    A::setML(a, 20);
    std::cout << "m_l=" << a.getML() << std::endl;

    std::cout << "s_i=" << a.getSI() << std::endl;
    a.setSI(30);
    std::cout << "s_i=" << a.getSI() << std::endl;

    // 静态成员变量可直接通过类名进行访问
    std::cout << "s_pi=" << A::s_pi << std::endl;

    return 0;
}