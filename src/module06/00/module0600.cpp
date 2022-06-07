#include <iostream>

using namespace std;

/*
==>
继承是面向对象中类之间的一种关系
子类拥有父类的所有属性和行为
子类对象可以当作父类对象使用
子类中可以添加父类没有的方法和属性
继承是面向对象中代码复用的重要手段
<==
*/
class Parent
{
private:
    int mv;

public:
    Parent()
    {
        this->mv = 5;
        cout << "Parent()::this->mv=" << this->mv << ", this=" << this << endl;
    }

    int getMV()
    {
        cout << "Parent()::getMV()" << endl;
        return this->mv;
    }

    ~Parent()
    {
        cout << "~Parent()::this=" << this << endl;
    }
};

class Child : public Parent
{
private:
    int mv;

public:
    Child()
    {
        this->mv = 7;
        cout << "Child()::mv=" << this->mv << ", this=" << this << endl;
    }

    void hello()
    {
        cout << "Child::hello()" << endl;
    }

    int getMV()
    {
        cout << "Child()::getMV()" << endl;
        return this->mv;
    }

    ~Child()
    {
        cout << "~Child()::this=" << this << endl;
    }
};

int main()
{
    // 父类构造函数 => 子类构造函数：同一个对象
    Child c0; // Parent()::this->mv=5, this=0x7ffc2f59f1c0; Child()::mv=7, this=0x7ffc2f59f1c0

    // 子类对象调用的是子类中的方法
    c0.hello();
    cout << "c0.mv=" << c0.getMV() << endl;

    // 子类对象初始化父类对象
    Parent p0 = c0;
    // 父类对象无法调用子类方法
    // p0.hello();
    // 父类对象调用的是父类中的方法
    cout << "p0.mv=" << p0.getMV() << endl;

    // ~Parent()::this=0x7ffc2f59f1bc // 子类对象初始化父类对象时，新生成了父类对象。(通过拷贝构造函数赋值并生成新对象p0)
    // ~Child()::this=0x7ffc2f59f1c0
    // ~Parent()::this=0x7ffc2f59f1c0

    return 0;
}