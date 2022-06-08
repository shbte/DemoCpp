#include <iostream>

using namespace std;

/*
==>
子类对象可以当作父类对象使用(兼容性)
    子类对象可以直接赋值给父类对象
    子类对象可以直接初始化父类对象
    父类指针可以直接指向子类对象
    父类引用可以直接引用子类对象

当使用父类指针(引用)指向子类对象时
    子类对象退化为父类对象
    只能访问父类中定义的成员
    可以直接访问被子类覆盖的同名成员
<==
*/
class Parent
{
public:
    int mv;

    Parent()
    {
        cout << "Parent()::this=" << this << endl;
    }

    void print() // 子类与父类同名同参函数
    {
        cout << "Parent::print()::this=" << this << endl;
    }

    ~Parent()
    {
        cout << "~Parent()::this=" << this << endl;
    }
};

class Child : public Parent
{
public:
    int mv;

    Child()
    {
        cout << "Child()::this=" << this << endl;
    }

    void print() // 子类与父类同名同参函数
    {
        cout << "Child::print()::this=" << this << endl;
    }

    ~Child()
    {
        cout << "~Child()::this=" << this << endl;
    }
};

// 编译器为了安全考虑，统一调用父类的方法(根据指针类型判断)
void how_to_print(Parent *p)
{
    p->print();
}

int main()
{

    Parent p00; // Parent()::this=0x7ffc72ad4a00
    Child c00; // Parent()::this=0x7ffc72ad4a30; Child()::this=0x7ffc72ad4a30
    how_to_print(&p00); // Parent::print()::this=0x7ffc72ad4a00
    how_to_print(&c00); // Parent::print()::this=0x7ffc72ad4a30
    cout << endl;

    Parent p01 = c00;
    // 不存在用户定义的从 "Parent" 到 "Child" 的适当转换
    // Child c01 = p00;
    how_to_print(&p01); // Parent::print()::this=0x7ffc72ad4a04
    cout << endl;

    Parent *p10;
    how_to_print(p10); // Parent::print()::this=0x7fd65185a1e0
    p10 = &p00;
    how_to_print(p10); // Parent::print()::this=0x7ffc72ad4a00
    p10 = &c00;
    how_to_print(p10); // Parent::print()::this=0x7ffc72ad4a30
    cout << endl;

    Child *p11;
    how_to_print(p11); // Parent::print()::this=0x7fd65185a0c0
    // 不能将 "Parent *" 类型的值分配到 "Child *" 类型的实体
    // p11 = &p00;
    p11 = &c00;
    how_to_print(p11); // Parent::print()::this=0x7ffc72ad4a30
    cout << endl;

    Parent &p20 = p00;
    how_to_print(&p20); // Parent::print()::this=0x7ffc72ad4a00
    Parent &p21 = c00;
    how_to_print(&p21); // Parent::print()::this=0x7ffc72ad4a30
    // 无法用 "Parent" 类型的值初始化 "Child &" 类型的引用(非常量限定)
    // Child &p22 = p00;
    Child &p23 = c00;
    how_to_print(&p23); // Parent::print()::this=0x7ffc72ad4a30
    cout << endl;

    /*
        ~Parent()::this=0x7ffc72ad4a04
        ~Child()::this=0x7ffc72ad4a30
        ~Parent()::this=0x7ffc72ad4a30
        ~Parent()::this=0x7ffc72ad4a00
    */
    return 0;
}