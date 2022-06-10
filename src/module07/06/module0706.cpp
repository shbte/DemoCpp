#include <iostream>

using namespace std;

/*
==>
class和struct遵循内存对齐原则
子类没有自身的虚函数表指针
<==
*/
class Interface1 // 8 = 8
{
public:
    virtual void fun1() = 0; // 8
};

class Interface2 // 8 = 8
{
public:
    virtual void fun2() = 0; // 8
};

class Base // 16 = 4[8] + 8
{
private:
    int mi; // 4[8]

public:
    Base()
    {
        cout << "Base::Base()" << endl;
    }

    virtual ~Base() // 8
    {
        cout << "Base::~Base()" << endl;
    }
};

class Derived : public Base, public Interface1, public Interface2 // 40 = (4[8] + 8) + 8 + 8 + (4[8] + 8[0])
{
private:
    int mi; // 4[8]
    int mn; // 4[0 = 4 - 4]

public:
    Derived()
    {
        cout << "Derived::Derived()" << endl;
    }

    virtual ~Derived() // 8[0]  => 子类没有自身的虚函数表指针
    {
        cout << "Derived::~Derived()" << endl;
    }
};

int main()
{
    cout << "sizeof(Interface1) = " << sizeof(Interface1) << ", "
         << "sizeof(Interface2) = " << sizeof(Interface2) << ", "
         << "sizeof(Base) = " << sizeof(Base) << ", "
         << "sizeof(Derived) = " << sizeof(Derived) << endl
         << endl;

    return 0;
}