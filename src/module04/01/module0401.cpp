#include <iostream>

/*
==>
函数的重载需要判定作用域，不同作用域构不成函数重载
<==
*/
class A
{
public:
    A()
    {
        std::cout << "A()" << std::endl;
    }

    void func()
    {
        std::cout << "A::func()" << std::endl;
    }

    // 报错：函数重载，void A::func(int i)
    // void func(int i)
    // {
    //     std::cout << "A::func(int i)::i=" << i << std::endl;
    // }

    void func(int i);

    void func(int a, int b);
};

void A::func(int i)
{
    std::cout << "A::func(int i)::i=" << i << std::endl;
}

void A::func(int a, int b)
{
    std::cout << "A::func(int a, int b)::a=" << a << std::endl;
}

void func()
{
    std::cout << "G::func()" << std::endl;
}

void func(int i)
{
    std::cout << "G::func(int i)::i=" << i << std::endl;
}

int main()
{
    A *a = new A();

    a->func();
    a->func(1);
    a->func(1, 2);

    func();
    func(1);

    return 0;
}