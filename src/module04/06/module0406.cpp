#include <iostream>

using namespace std;

class Fib
{
private:
    int a0;
    int a1;

public:
    Fib();
    Fib(int n);
    int operator()();
    ~Fib();
};

Fib::Fib()
{
    this->a0 = 0;
    this->a1 = 1;
}

Fib::Fib(int n)
{
    this->a0 = 0;
    this->a1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int tmp = a1;
        a1 = a0 + a1;
        a0 = tmp;
    }
}

// 重载函数调用操作符
int Fib::operator()()
{
    int ret = a1;

    a1 = a0 + a1;
    a0 = ret;

    return ret;
}

Fib::~Fib()
{
    // cout << "~Fib()" << endl;
}

int main()
{
    Fib fib1;
    int count = 0;

    // 输出前十斐波那契数列
    count = 10;
    for (int i = 0; i < count; i++)
    {
        cout << fib1() << " ";
    }

    // 继续上面，输出五位斐波那契数列
    count = 5;
    for (int i = 0; i < count; i++)
    {
        cout << fib1() << " ";
    }
    cout << endl;

    int begin = 11;
    // 从begin开始输出count位斐波那契数列
    Fib fib2(begin);
    for (int i = 0; i < count; i++)
    {
        cout << fib2() << " ";
    }
    cout << endl;

    return 0;
}