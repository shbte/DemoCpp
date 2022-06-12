#include <iostream>

using namespace std;

/*
==>
函数模板可以像普通函数一样被重载
    C++编译器优先考虑普通函数
    如果函数模板可以产生一个更好的匹配，那么选择模板
    可以通过空模板是参列表限定编译器匹配模板
<==
*/
template <typename T>
T Max(T a, T b)
{
    cout << "Max(T a, T b)" << endl;

    return a > b ? a : b;
}

int Max(int a, int b)
{
    cout << "Max(int a, int b)" << endl;

    return a > b ? a : b;
}

template <typename T>
T Max(T a, T b, T c)
{
    cout << "Max(T a, T b, T c)" << endl;

    return Max(Max(a, b), c);
}

int main()
{

    int a = 1;
    int b = 2;

    // 普通函数 Max(int a, int b) 编译器优先匹配普通函数
    cout << Max(a, b) << endl
         << endl;

    // 函数模板 Max(T a, T b)
    cout << Max<>(a, b) << endl
         << endl;

    // 函数模板 Max(T a, T b)
    cout << Max(3.0, 4.0) << endl
         << endl;

    // 函数模板 + 普通函数 + 普通函数 Max(T a, T b, T c);Max(int a, int b);Max(int a, int b)
    cout << Max(5, 6, 7) << endl
         << endl;

    // 普通函数 Max(int a, int b) 因为函数模板不会进行隐式参数转换，普通函数会，所以会匹配到普通函数
    cout << Max('a', 100) << endl
         << endl;

    return 0;
}