#include <iostream>

using namespace std;

/*
==>
构造函数可以定义不同类型的参数
参数满足下列条件时被称为转换构造函数
    有且仅有一个参数
    参数是基本类型
    参数是其他类类型
explicit关键字用于杜绝隐式类型转换
<==
*/

// 声明B类(A类中使用了B类)
class B;

class A
{
private:
    int mValue;

public:
    A(int i) // 定义有参构造函数，被编译器用于隐式类型转换。int类型=>A类类型
    {
        this->mValue = i;
        cout << "A(int i)::this->mValue=" << this->mValue << ", this=" << this << endl;
    }

    A(const B& b) // B类类型=>A类类型(优先级低)
    {
        // this->mValue = b.value();
        this->mValue = 2222;
        cout << "A(const A &b)::this->mValue=" << this->mValue << ", this=" << this << endl;
    }

    int value() const // 定义const方法
    {
        return this->mValue;
    }

    A operator+(const A &a) // 定义A类的运算操作符(+)
    {
        cout << "A operator+(const A &a)::this=" << this << endl;

        int tempValue = this->mValue + a.mValue;
        A ret = A(tempValue); // => A ret(tempValue);

        return ret;
    }

    ~A()
    {
        cout << "~A()::this=" << this << endl;
    }
};

class B
{
private:
    int mValue;

public:
    B(const A &a) // 定义有参构造函数，被编译器用于隐式类型转换。A类类型=>B类类型
    {
        this->mValue = a.value();
        cout << "B(const A &a)::this->mValue=" << this->mValue << ", this=" << this << endl;
    }

    int value() const
    {
        return this->mValue;
    }

    explicit operator A() // B类类型=>A类类型(优先级高)，explicit关键字不让编译器用于隐式类型转换
    {
        cout << "operator B()::this->mValue=" << this->mValue << ", this=" << this << endl;

        A tmp(7);
        cout << "operator B()::tmp->mValue=" << tmp.value() << ", this=" << &tmp << endl;

        return tmp;
    }

    ~B()
    {
        cout << "~B()::this=" << this << endl;
    }
};

int main()
{
    A a0 = 3; // => A a0(3) 调用了有参构造函数作隐式转换操作
    cout << endl;

    A a1 = a0 + 3; // => A a1(a0 + A(3)); 1、3隐式转换调用了A(3)生成临时对象。2、调用运算操作符(+)。3、在重载运算符函数中生成对象(6)
    cout << endl;

    A a2(a1); // 编译器默认提供了拷贝函数。(1、无参构造函数。2、拷贝构造函数。3、赋值操作符。4、析构函数)

    B b0 = a1; // B b0(a1); 调用拷贝函数，而不是赋值操作符
    cout << endl;

    // A(const A &b)::this->mValue=2222, this=0x7ffc42904cb4
    // a3.mValue2222, this=0x7ffc42904cb4
    A a3 = b0; // 调用了B类中的A类类型转换(B类中的A类类型转换 > A类中的构造转换函数)。a3并没有构建对象，因为并没有定义无参构造函数(无从调用)
    cout << "a3.mValue" << a3.value() << ", this=" << &a3 << endl;
    cout << endl;

    // 补充
    // B b1 = 1;
    B b2 = A(1);
    cout << endl;

    return 0;
}