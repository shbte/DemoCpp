#include <iostream>

using namespace std;

/*
==>
函数重写只可能发生在父类与子类之间
根据实际对象的类型确定调用的具体函数
virtual关键字时C++中支持多态的唯一方式
被重写的虚函数可表现出多态的特征

理论中的概念
    静态联编
        在程序的编译期间就能确定具体的函数调用
        如：函数重载
    动态联编
        在程序实际运行后才能确定具体的函数调用
        如：函数重写
<==
*/
class Parent
{
public:
    virtual void print() // 关键字virtual使编译器不再按照指针类型调用同名同参函数，会按照指向的类型来匹配父类或者子类方法
    {
        cout << "I'm Parent." << endl;
    }
};

class Child : public Parent
{
public:
    void print()
    {
        cout << "I'm Child." << endl;
    }
};

void how_to_print(Parent *p)
{
    p->print(); // 展现多态的行为，动态联编
}

int main()
{

    Parent p0;
    Child c0;
    cout << endl;

    how_to_print(&p0); // I'm Parent.
    how_to_print(&c0); // I'm Child.
    cout << endl;

    return 0;
}