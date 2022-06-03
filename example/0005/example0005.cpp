#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "A()" << std::endl;
    }

    A(int i)
    {
        std::cout << "A(int i)::i=" << i << std::endl;
    }

    ~A()
    {
        std::cout << "~A()" << std::endl;
    };
};

int main()
{
    A a0(); // 函数的声明，不是调用，所以不执行
    A a1(1);
    A a2;
    A a3(3);

    return 0;
}