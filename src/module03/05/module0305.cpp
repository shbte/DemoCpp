#include <iostream>

/*
==>
const关键字能够修饰对象
const修饰的对象为只读对象
只读对象的成员变量不允许被改变
只读对象是编译阶段的概念，运行时无效

C++中的const成员函数
    const对象只能调用const的成员函数
    const成员函数中只能调用const成员函数
    const成员函数中不能直接改写成员变量的值

所有的对象共享类的成员函数，隐藏的this指针用于表示当前对象
<==
*/
class A
{
private:
    int m_i = 0;
    long m_l = 100;

public:
    A();
    A(int i);
    A(const A &a);
    int getMI() const; // 函数的声明和定义要一起家const
    long getML();
    void setMI(int i) const;
    A *printThis();
    ~A();
};

A::A()
{
    printf("A()\n");
}

A::A(int i)
{
    m_i = i;
    printf("A(int i):i=%d\n", i);
}

A::A(const A &a)
{
    printf("A(const A& a)\n");
}

int A::getMI() const // 函数的声明和定义要一起家const
{
    return m_i;
}

long A::getML()
{
    return m_l;
}

void A::setMI(int i) const
{
    // const成员函数中不能直接改写成员变量的值
    // m_i = i; // 表达式必须是可修改的左值

    // 但可以间接改变
    int *p = const_cast<int *>(&m_i);
    *p = i;
}

A *A::printThis()
{
    return this;
}

A::~A()
{
    printf("~A():m_i=%d\n", m_i);
}

long fun()
{
    return 0;
}

int main()
{

    const A a(4);
    // const对象只能调用const的成员函数
    printf("a.getMI()=%d\n", a.getMI());
    // const成员函数中只能调用const成员函数
    // printf("a.getML()=%ld\n", a.getML()); // 对象含有与成员 函数 "A::getML" 不兼容的类型限定符,对象类型是: const A

    a.setMI(11);
    printf("a.setMI(11) => a.getMI()=%d\n", a.getMI());

    A a1(1);
    A a2(2);
    A();
    A a3(3);

    // 所有的对象共享类的成员函数，隐藏的this指针用于表示当前对象
    printf("a.getMI():m_i=%d, this=%p, &a1=%p, &A::printThis=%p\n", a1.getMI(), a1.printThis(), &a1, (void *)(A * (A::*)()) & A::printThis);
    printf("a.getMI():m_i=%d, this=%p, &a2=%p, &A::printThis=%p\n", a2.getMI(), a2.printThis(), &a2, (void *)&A::printThis);
    printf("a.getMI():m_i=%d, this=%p, &a3=%p, &A::printThis=%p\n", a3.getMI(), a3.printThis(), &a3, (void *)&A::printThis);

    printf("fun_addr=%p\n", &fun);

    return 0;
}