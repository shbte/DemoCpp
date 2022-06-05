#include <iostream>

using namespace std;

/*
==>
编译器为每个类默认重载了赋值操作符，但仅完成了浅拷贝
    浅拷贝会导致两个对象内的指针指向统一地址，释放时会释放同一地址两次，从而发生错误
当需要进行深拷贝时必须重载赋值操作符
赋值操作符与拷贝构造函数有相同的存在意义

编译器为类默认提供的函数
    构造函数
        无参构造函数(存在其它构造函数时，编译器将不再默认提供无参构造函数)
        拷贝构造函数(存在其它拷贝构造函数时，编译器将不再默认提供拷贝构造函数)
    赋值操作符
    析构函数

当对象内指针指向了外部资源(使用了外部资源)时，必须要进行重载赋值操作符达到深拷贝的目的
<==
*/
// 自定义类A，不改变默认赋值操作符和拷贝构造函数，完成拷贝(浅拷贝)
class A
{
private:
    int *m_p;

public:
    A() {}

    A(int i)
    {
        m_p = new int(i);
    }

    void print() const
    {
        cout << "value=" << *m_p << ", address=" << m_p << endl;
    }

    ~A()
    {
        // delete m_p; // 浅拷贝会导致多个对象多次释放同一地址(m_p)，先注释，让系统释放，保证后续程序运行
    }
};

// 自定义类B，重载默认操作符和拷贝构造函数，完成拷贝(深拷贝)
class B
{
private:
    int *m_p;

public:
    B();
    B(int i);
    B(const B &B);
    B &operator=(const B &b);
    void print();
    void test(const A &a, const B &b);
    ~B();
};

void B::test(const A &a, const B &b)
{
    a.print(); // const对象，只能调用const成员函数，A类中print加上const成为const函数
    b.m_p;     // m_p是私有成员变量，这里能直接访问是b对象属于B类(在自身类中)，没有访问限制
}

B::B() : m_p(NULL)
{
    cout << "B::B()" << endl;
}

B::B(int i)
{
    cout << "B::B(int i)" << endl;

    m_p = new int(i);
}

B::B(const B &a)
{
    cout << "B::B(const B& b)" << endl;

    this->m_p = new int(*a.m_p); // m_p是私有成员变量，这里能直接访问是b对象属于B类，没有访问限制
}

B &B::operator=(const B &b)
{
    cout << "B::operator=(const B& b)" << endl;

    delete m_p;
    this->m_p = new int(*b.m_p); // m_p是私有成员变量，这里能直接访问是b对象属于B类，没有访问限制

    return *this;
}

void B::print()
{
    cout << "B::m_p(value)=" << *m_p << ", B::m_p(address)=" << m_p << endl;
}

B::~B()
{
    cout << "B::~B()" << endl;

    delete m_p;
}

int main()
{
    A a0(3);
    A a1(a0);  // 这里使用拷贝构造函数
    A a2 = a0; // 这里使用拷贝构造函数

    A a3;
    a3 = a0; // 这里使用的是赋值操作符

    // 系统提供的拷贝是浅拷贝，对象内指针指向同一地址，会导致同一内存在析构函数释放内存时多次施放的错误
    // a0=> value=3, address=0x55968d2f3eb0
    cout << "a0=> ";
    a0.print();
    // a1=> value=3, address=0x55968d2f3eb0
    cout << "a1=> ";
    a1.print();
    // a2=> value=3, address=0x55968d2f3eb0
    cout << "a2=> ";
    a2.print();
    // a3=> value=3, address=0x55968d2f3eb0
    cout << "a3=> ";
    a3.print();

    B b0(6);
    B b1(b0);  // 拷贝构造函数
    B b2 = b0; // 拷贝构造函数

    B b3;
    b3 = b0; // 赋值操作符

    // 自定义了拷贝构造函数和赋值操作符，以实现了深拷贝(不同对象的同一指针指向不同的地址，保证不会发生释放内存错误)
    // b0=> B::m_p(value)=6, B::m_p(address)=0x55d8f53cb2e0
    cout << "b0=> ";
    b0.print();
    // b1=> B::m_p(value)=6, B::m_p(address)=0x55d8f53cb300
    cout << "b1=> ";
    b1.print();
    // b2=> B::m_p(value)=6, B::m_p(address)=0x55d8f53cb320
    cout << "b2=> ";
    b2.print();
    // b3=> B::m_p(value)=6, B::m_p(address)=0x55d8f53cb340
    cout << "b3=> ";
    b3.print();

    return 0;
}