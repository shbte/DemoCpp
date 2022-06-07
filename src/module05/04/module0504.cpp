#include <iostream>

using namespace std;

/*
==>
类型转换
    转换构造函数(单参构造函数)
    类型转换函数

类型转换函数用于将类对象转换为其它类型(其它类类型、基本类型)

语法规则(explicit关键字说明不让编译器对该函数用于隐式类型转换，但可以显示调用),推荐使用Type toType()的共有成员函数代替类型转换函数
operator type()
{
    Type ret;
    ret = ...;
    return ret;
}
<==
*/
class A
{
private:
    int mv;

public:
    A()
    {
        this->mv = 0;
        cout << "A()::this->mv=" << this->mv << ", this=" << this << endl;
    }

    A(int i)
    {
        this->mv = i;
        cout << "A(int i)::this->mv=" << this->mv << ", this=" << this << endl;
    }

    // 类型转换函数：A类类型=>int类型。explicit关键字说明不让编译器对该函数用于隐式类型转换
    explicit operator int()
    {
        int ret;

        ret = this->mv;
        cout << "operator int()::ret=" << ret << ", &ret=" << &ret << ", this=" << this << endl;

        return ret;
    }

    // 推荐使用Type toType()的共有成员函数代替类型转换函数
    int toInt()
    {
        int ret;

        ret = this->mv;
        cout << "toInt()::ret=" << ret << ", &ret=" << &ret << ", this=" << this << endl;

        return ret;
    }

    /*
    该方式不是重写赋值操作符进行类型转换，因为赋值操作符重写有特定格式，这只是定义函数。
    int operator=(int)
    {
        int ret;

        ret = this->mv;
        cout << "operator=(const A &a)::ret=" << ret << ", &ret=" << &ret << ", this=" << this << endl;

        return ret;
    }
    */

    ~A()
    {
        cout << "~A()::this->mv=" << this->mv << ", this=" << this << endl;
    }
};

int main()
{

    A a0;    // A()::this->mv=0, this=0x7ffd0df69b08
    A a1(4); // A(int i)::this->mv=4, this=0x7ffd0df69b0c
    cout << endl;

    int i0;
    int i1;

    // 编译器隐式调用类型转换函数，可以使用explicit关键字避免进行隐式转换(但可以显示调用)
    i0 = a0.operator int();                         // toInt()::ret=0, &ret=0x7ffd0df69ae4, this=0x7ffd0df69b08
    cout << "i0=" << i0 << ", &i0=" << &i0 << endl; // i0=0, &i0=0x7ffd0df69b10
    cout << endl;

    // 编译器隐式调用类型转换函数，可以使用explicit关键字避免进行隐式转换
    i1 = a1.toInt();                                // toInt()::ret=4, &ret=0x7ffd0df69ae4, this=0x7ffd0df69b0c
    cout << "i1=" << i1 << ", &i1=" << &i1 << endl; // i1=4, &i1=0x7ffd0df69b14
    cout << endl;

    // ~A()::this->mv=4, this=0x7ffd0df69b0c
    // ~A()::this->mv=0, this=0x7ffd0df69b08

    return 0;
}