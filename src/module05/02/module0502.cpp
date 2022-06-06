#include <iostream>

using namespace std;

/*
==>
前置操作符和后置操作符
    对于基础类型的变量
        前置++的效率与后置++的效率基本相同
        根据项目组编码规范进行选择
    对于类类型的对象
        前置++的效率高于后置++
        尽量使用前置++操作符提高程序效率
<==
*/
class A
{
    int m_i;

public:
    A() : m_i(0)
    {
        cout << "A::A() this->m_i=" << this->m_i << ", adress=" << this << endl;
    }

    A(int i)
    {
        this->m_i = i;
        cout << "A::A(int i) this->m_i=" << this->m_i << ", adress=" << this << endl;
    }

    int value()
    {
        return this->m_i;
    }

    // 前置++重载
    A &operator++()
    {
        cout << "this->m_i=" << this->m_i << ", address=" << this << endl;
        this->m_i++;
        return *this;
    }

    // 后置++重载，新生成一个临时对象，效率上有所不如前置++
    A operator++(int)
    {
        A ret = *this;
        cout << "ret.m_i=" << ret.m_i << ", ret(address)=" << &ret << ", this(value)=" << this << endl;

        this->m_i++;
        return ret;
    }

    ~A()
    {
        cout << "~A() this->m_i=" << this->m_i << ", address=" << this << endl;
    }
};

int main()
{

    A a0(3);
    cout << "a0.m_i=" << a0.value() << ", a0(value)=" << &a0 << endl;

    // a0++的返回值为一个临时对象，后续的++ ++ ++操作this总为上一次返回对象(只有第一次为a0)
    a0++ ++ ++ ++; // 该语句会产生4个临时对象，该语句执行完后，下条语句之前，该4个临时对象将会被释放(调用析构函数)
    cout << "a0.m_i=" << a0.value() << ", a0(value)=" << &a0 << endl;

    ++ ++ ++ ++a0;
    cout << "a0.m_i=" << a0.value() << ", a0(value)=" << &a0 << endl;

    return 0;
}