#include <iostream>

using namespace std;

class A
{
private:
    int mValue;

public:
    A(int i) // 定义有参构造函数，被编译器用于隐式类型转换
    {
        this->mValue = i;
        cout << "A(int i)::this->mValue=" << this->mValue << ", this=" << this << endl;
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

int fun1()
{
    int i = 10;
    cout << "fun1()::i=" << i << ", i(address)=" << &i << endl;

    return i;
}

A fun2()
{
    A ret = A(13); // A ret(13)
    cout << "fun2()::A.mValue=" << ret.value() << ", ret=" << &ret << endl;

    return ret;
}

int fun3()
{
    int i = int(35);
    cout << "fun3()::i=" << i << ", i(address)=" << &i << endl;

    return i;
}

int main()
{
    // fun1和main的int对象不是同一个地址，说明基本类型作用域限于定义方法
    int i0 = fun1();
    cout << "main::i=" << i0 << ", i(address)=" << &i0 << endl;
    cout << endl;

    // fun2和main的A类型对象是同一个地址，说明对象作用域不局限于定义方法
    A tmp = fun2();
    cout << "main()::A.mValue=" << tmp.value() << ", tmp=" << &tmp << endl;
    cout << endl;

    // fun1和main的int对象不是同一个地址，说明基本类型对象作用域限于定义方法
    int i1 = fun3();
    cout << "main::i=" << i1 << ", i(address)=" << &i1 << endl;
    cout << endl;

    return 0;
}