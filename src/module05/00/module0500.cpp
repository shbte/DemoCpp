#include <iostream>

using namespace std;

/*
==>
智能指针(自定义类对象，利用对象超出作用域时析构函数会自动调用的特性)：尽可能解决内存泄漏问题
    重载指针特征操作符( -> 和 * )，能够使用对象代替指针
    只能通过类的成员函数重载
    重载函数不能使用参数
    只能定义一个重载函数

    只能用于指向堆空间中的内存
<==
*/
class A
{
    int i;

public:
    A()
    {
        cout << "A::A()" << endl;
        this->i = 0;
    }

    A(int i)
    {
        cout << "A::A(int i)::i=" << i << endl;
        this->i = i;
    }

    int value()
    {
        return this->i;
    }

    ~A()
    {
        cout << "A::~A()::i=" << i << ", this(address)=" << this << endl;
    }
};

class B
{
    A *b_a;

public:
    B(A *a = NULL)
    {
        cout << "B::B(A *a = NULL)" << endl;

        this->b_a = a;
    }

    A *operator->()
    {
        return b_a;
    }

    A &operator*()
    {
        return *b_a;
    }

    ~B()
    {
        cout << "~B()::b_a(address)=" << this->b_a << endl;

        delete this->b_a;

        // delete[] this->b_a;
    }
};

int main()
{

    A *a0 = new A(5); // new开辟了堆空间，最后需要手动释放内存(忘记释放时，将会产生野指针，造成内存泄漏)

    cout << a0->value() << ", a0(address)=" << a0 << endl;

    B b0 = a0; // 这里调用了构造函数创建对象b0(不是调用赋值操作符)，B类定义了参数是A类的有参构造函数

    cout << b0->value() << endl;   // -> 操作的是指针
    cout << (*b0).value() << endl; // * 操作的是对象

    // delete a0; // a0时指针，不是对象，对象才会自动调用析构函数，所以需要手动释放指向的内存空间

    /*log:

        A::A(int i)::i=5
        5, a0(address)=0x5556ad807eb0
        B::B(A *a = NULL)
        ~B()::b_a(address)=0x5556ad807eb0 // 因为是对象，所以超出对象作用域时，会自动调用析构函数
        A::~A()::this(address)=0x5556ad807eb0
    */

    A *a1 = new A[3];

    // delete[] a1;

    B b1 = a1;

    /*
        B类型的指针，b0指向的是A对象(应使用delete释放内存)，b1指向的是A对象数组(应使用delete[]释放内存)
        然B类中析构函数统一使用了delete[]，会导致释放A对象时按照释放对象数组的方式进行释放，会导致错误
            因为在A对象中没有找到数组长度，所以会一直释放
    */

    return 0;
}