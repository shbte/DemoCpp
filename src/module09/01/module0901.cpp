#include <iostream>

using namespace std;

/*
==>
C++内置了异常处理的语法元素try...catch...
    try语句处理正常代码逻辑
    catch语句处理异常情况
    try语句中的异常由对应的catch语句处理

C++异常处理分析
    throw抛出的异常必须被catch处理
        当前函数能够处理异常，程序继续往下执行
        当前函数无法处理异常，则函数停止执行，并返回

未被处理的的异常会顺着函数调用栈向上传播，直到被处理为止，否则程序将停止执行
<==
*/
double divide(double a, double b)
{
    const double delta = 0.00000000001;
    double ret = 0;

    if (!((-delta < b) && (b < delta)))
    {
        ret = a / b;
    }
    else
    {
        throw 0;
    }

    return ret;
}

int main()
{
    double ret = 0;
    try
    {
        ret = divide(1, 1);
        cout << "1 / 1 = " << ret << endl;

        ret = divide(0, 1);
        cout << "0 / 1 = " << ret << endl;

        ret = divide(1, 0);
        cout << "1 / 0 = " << ret << endl;
    }
    catch (...)
    {
        cout << "Error..." << endl;
    }

    return 0;
}