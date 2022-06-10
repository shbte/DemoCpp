#include <iostream>

using namespace std;

/*
==>
new关键字与malloc函数的区别
    new关键字是C++的一部分
    malloc是由C库提供的函数
    new以具体类型为单位进行内存分配
    malloc以字节为单位进行内存分配
    new在申请内存空间时可进行初始化
    malloc仅根据需要申请定量的内存空间

虚函数
    构造函数不可能成为虚函数
        在构造函数执行结束后，虚函数表指针才会被正确初始化
    构造函数中不可能发生多态行为
        在构造函数执行时，虚函数表指针未被正确初始化
    析构函数可以成为虚函数
        建议在设计类时将析构函数声明为虚构函数
    析构函数中不可能发生多态行为
        在析构函数执行时，虚函数表指针已经被销毁
<==
*/
class BaseA
{
public:
    BaseA()
    {
        cout << "BaseA()" << endl;
        fun(); // 构造函数中，不可能发生多态行为，虚函数表指针未被正确初始化，所以调用的是自身类的方法
    }

    virtual void fun()
    {
        cout << "BaseA::fun()" << endl;
    }

    ~BaseA()
    {
        cout << "~BaseA()" << endl;
        fun(); // 析构函数中，不可能发生多态行为，虚函数表指针已经被销毁，所以调用的是自身类的方法
    }
};

class BaseB
{
public:
    BaseB()
    {
        cout << "BaseB()" << endl;
        fun(); // 构造函数中，不可能发生多态行为，虚函数表指针未被正确初始化，所以调用的是自身类的方法
    }

    virtual void fun()
    {
        cout << "BaseB::fun()" << endl;
    }

    virtual ~BaseB() // 定义析构函数为虚函数，可以父类指针指向子类对象时，可以调用子类析构函数
    {
        cout << "~BaseB()" << endl;
        fun(); // 析构函数中，不可能发生多态行为，虚函数表指针已经被销毁，所以调用的是自身类的方法
    }
};

class DerivedA : public BaseA
{
public:
    DerivedA()
    {
        cout << "DerivedA()" << endl;
        fun(); // 构造函数中，不可能发生多态行为，虚函数表指针未被正确初始化，所以调用的是自身类的方法
    }

    virtual void fun()
    {
        cout << "DerivedA::fun()" << endl;
    }

    ~DerivedA()
    {
        cout << "~DerivedA()" << endl;
        fun(); // 析构函数中，不可能发生多态行为，虚函数表指针已经被销毁，所以调用的是自身类的方法
    }
};

class DerivedB : public BaseB
{
public:
    DerivedB()
    {
        cout << "DerivedB()" << endl;
        fun(); // 构造函数中，不可能发生多态行为，虚函数表指针未被正确初始化，所以调用的是自身类的方法
    }

    virtual void fun()
    {
        cout << "DerivedB::fun()" << endl;
    }

    ~DerivedB()
    {
        cout << "~DerivedB()" << endl;
        fun(); // 析构函数中，不可能发生多态行为，虚函数表指针已经被销毁，所以调用的是自身类的方法
    }
};

int main()
{
    BaseA *pa = new DerivedA();
    cout << endl;
    BaseB *pb = new DerivedB();
    cout << endl;

    delete pa; // ~DerivedB()   => 因为父类析构函数没有定义为虚函数，所以构函数调用的时指针类型(父类)
    cout << endl;
    delete pb; // ~DerivedB(); ~BaseB() => 因为父类析构函数定义为了虚函数，所以析构函数调用的是指向类型(子类)
    cout << endl;

    return 0;
}