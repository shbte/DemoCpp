#include <iostream>

using namespace std;

/*
==>
C++多态的实现原理
    当类中声明虚函数时，编译器会在类中生成一个虚函数表
    虚函数表是一个存储成员函数地址的数据结构
    虚函数表是由编译器自动生成与维护的
    irtual成员函数会被编译器放入虚函数表中
    存在虚函数时，每个对象中都有一个指向虚函数表的指针

调用效率: 虚函数 < 普通成员函数
    p => (具体对象 | VPTR) => (VTABLE | void (*pADD)(int value)) => (0xFF010203)

小结：
    继承的本质就是父子间成员变量的叠加
    C++中的多态是通过虚函数表实现的
    虚函数表时是由编译器自动生成与维护的
    虚函数的调用效率低于普通成员函数
<==
*/
class Parent
{
protected:
    int mi; // 声明虚函数后，最初位置存在指向虚函数表的指针
    int mj;

public:
    virtual void print() // 声明虚函数
    {
        cout << "mi=" << mi << ", "
             << "mj=" << mj << endl;
    }
};

class Child : public Parent
{
protected:
    int mk; // 声明虚函数后，最初位置存在指向虚函数表的指针

public:
    Child(int i, int j, int k)
    {
        mi = i;
        mj = j;
        mk = k;
    }

    void print()
    {
        cout << "mi=" << mi << ", "
             << "mj=" << mj << ", "
             << "mk=" << mk << endl;
    }
};

void how_to_print(Parent *p)
{
    p->print(); // 展现多态的行为，动态联编
}

int main()
{
    Parent p0;
    Child c0(1, 2, 3);

    // sizeof(Parent)=16, sizeof(p0)=16(没有virtual时：sizeof(Parent)=8, sizeof(p0)=8)，指针8字节
    cout << "sizeof(Parent)=" << sizeof(Parent) << ", sizeof(p0)=" << sizeof(p0) << endl;
    // sizeof(Child)=24, sizeof(c0)=24(没有virtual时：sizeof(Child)=12, sizeof(c0)=12)，指针8字节
    cout << "sizeof(Child)=" << sizeof(Child) << ", sizeof(c0)=" << sizeof(c0) << endl;

    return 0;
}