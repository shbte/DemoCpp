#include <iostream>

using namespace std;

/*
==>
利用继承间的多态性，实现类型函数以判定并正确的进行类型对象转换

在面向对象中可能出现下面的情况
    基类指针指向子类对象
    基类引用成为子类对象的别名

Base* p = new Derived();
Base& r = *p;
静态类型    动态类型

静态类型 - 变量(对象)自身的类型
动态类型 - 指针(引用)所指向的对象的实际类型

基类指针是否可以强制类型转换为子类指针，取决于动态类型

解决方案 - 利用多态(动态类型识别)
    1、在基类中定义虚函数返回具体的类型信息
    2、所有的派生类都必须实现类型相关的虚函数
    3、每个类中的类型虚函数都需要不同的实现

多态解决方案的缺陷
    必须从基类开始提供类型虚函数
    所有的派生类都必须重写类型虚函数
    每个派生类的类型名必须唯一
<==
*/
class Base
{
public:
    virtual string type() // 利用多态的特性，执行指针指向类型的函数，以返回类型
    {
        return "Base";
    }
};

class Derived : public Base
{
public:
    string type() // 子类重写父类虚函数，用于判定对象类型
    {
        return "Derived";
    }

    void Print()
    {
        cout << "I'm a Derived" << endl;
    }
};

class Child : public Base
{
public:
    string type() // 子类重写父类虚函数，用于判定对象类型
    {
        return "Child";
    }
};

void typeChange(Base *b)
{
    if (b->type() == "Derived")
    {
        Derived *pd = static_cast<Derived *>(b);
        pd->Print();
    }

    // 能转换时，返回为正确指针地址；不能转换时，返回0
    cout << dynamic_cast<Derived *>(b) << endl;
}

int main()
{
    Base b;
    Derived d;
    Child c;

    typeChange(&b);
    typeChange(&d);
    typeChange(&c);

    return 0;
}