#include <iostream>

using namespace std;

/*
==>
try...catch用于分隔正常功能代码与异常处理代码
try...catch可以直接将函数实现分隔为2部分
函数声明和定义时可以直接指定可能抛出的异常类型
异常声明成为函数的一部分可以提高代码可读性

注意事项
    函数异常声明是一种与编译器之间的契约
    函数声明异常后就只能抛出声明的异常
        抛出其它异常将导致程序运行终止
        可以直接通过异常声明定义无异常函数

小结：
    class可以用来在模板中定义泛指类型(不推荐)
    typename是可以消除模板中的二义性
    try...catch可以将函数体分为2部分
    异常声明能够提供程序的可读性
<==
*/
int func1(int i) // throw(char) throw(optional_type_list)规范在 C++11 中被弃用，在 C++17 中删除，但该throw()规范是别名noexcept(true)
{
    if ( i = 10)
    {
        throw 0;
    }
    if ( i = 20)
    {
        throw '0';
    }

    return i * i;
}
void func2(int i)
try
{
    func1(i);
}
catch(int i)
{
    cout << "Exception : " << i << endl;
}
catch(...)
{
    cout << "Exception..." << endl;
}

int main()
{

    return 0;
}