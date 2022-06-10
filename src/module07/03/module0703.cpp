#include <iostream>

using namespace std;

/*
==>
工程开发中的“多重继承”方式：
    单继承某个类 + 实现(多个)接口

一些有用的工程建议
    先继承自一个父类，然后实现多个接口
    父类中提供equal()成员函数，用于判断当前指针是否指向当前对象(所定义的类对象)
    与多重继承相关的强制类型转换用dynamic_cast完成

小结：
多继承中可能出现多个虚函数表指针
与多重继承相关的强制类型转换用dynamic_cast完成
工程开发中采用“单继承多接口”的方式使用多继承
父类提供成员函数用于判断指针是否指向当前对象
<==
*/
class Interface1
{
public:
    virtual void add(int value) = 0;
    virtual void minus(int value) = 0;
};

class Interface2
{
public:
    virtual void multiply(int value) = 0;
    virtual void divide(int value) = 0;
};

class Base
{
private:
    int mi;

public:
    Base(int value)
    {
        this->mi = value;
        cout << "Base(int value)::this = " << this << endl;
    }

    Base(const Base &base)
    {
        this->mi = base.mi;
        cout << "Base(const Base &base)::this = " << this << endl;
    }

    virtual int getMI()
    {
        return this->mi;
    }
};

class Derived : public Base, public Interface1, public Interface2
{
private:
    int mi;

public:
    Derived(int value) : Base(value)
    {
        this->mi = value;

        cout << "Derived(int value)::this = " << this << endl;
    }

    int getMI()
    {
        return this->mi;
    }

    void add(int value)
    {
        this->mi += value;
    }

    void minus(int value)
    {
        this->mi -= value;
    }

    void multiply(int value)
    {
        this->mi *= value;
    }

    void divide(int value)
    {
        if (value)
        {
            this->mi /= value;
        }
    }
};

int main()
{
    // sizeof(Base) = 4, sizeof(Derived) = 32   => 32 = 4[8] + 8 + 8 + (4[8])   => 40 = (4[8] + 8) +8 + 8 + (4[8])
    cout << "sizeof(Base) = " << sizeof(Base) << ", "
         << "sizeof(Interface1) = " << sizeof(Interface1) << ", "
         << "sizeof(Interface2) = " << sizeof(Interface2) << ", "
         << "sizeof(Derived) = " << sizeof(Derived) << endl
         << endl;

    Derived d(100);
    cout << "derived::mi = " << d.getMI() << ", this = " << &d << endl // derived::mi = 100, this = 0x7fff0fb7d7e0  => 子类在父类前，是因为子类比父类多了虚函数表指针(8位)(子类并没有自己的虚函数表指针，子类和父类使用同一个)
         << endl;
    Base *p = &d;
    cout << "Base *::mi = " << p->getMI() << ", this = " << p << endl // Base *::mi = 100, this = 0x7fff0fb7d7e8
         << endl;

    d.add(10);     // 110
    d.minus(5);    // 105
    d.multiply(2); // 210
    d.divide(10);  // 21

    cout << "derived::mi = " << d.getMI() << ", this = " << &d << endl; // derived::mi = 21, this = 0x7fff0fb7d7e0
    cout << "Base::mi = " << p->getMI() << ", this = " << p << endl;    // Base::mi = 100, this = 0x7fff0fb7d7e8

    return 0;
}