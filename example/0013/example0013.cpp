#include <iostream>

using namespace std;

class Basic
{
public:
    int mi;

    Basic()
    {
        cout << "Basic::Basic()::this = " << this << endl;
    }

    Basic(const Basic &b)
    {
        this->mi = b.mi;
        cout << "Basic::Basic(const Basic &b)::this = " << this << ", b.address = " << &b << endl;
    }

    void fun1()
    {
        cout << "Basic::fun1()" << endl;
    }

    void fun2() const
    {
        cout << "Basic::fun2()" << endl;
    }
};

void fun1(Basic *b)
{
    cout << "fun1(Basic b)::" << &b << endl;
}

void fun2(const Basic *b)
{
    cout << "fun2(const Basic b)::" << &b << endl;
}

int main()
{
    Basic b0;
    Basic b1;
    const Basic b2 = b0;

    fun1(&b1);
    fun2(&b1);

    // 常量指针不能作为指针类型的参数，因为常量指针是保护值，指针类型可能会改变值，这俩冲突
    // fun1(&b2);
    fun2(&b2);

    return 0;
}