#include <iostream>

using namespace std;

/*
==>
函数模板深入了解
    -编译器从函数模板通过具体类型产生不同的函数
    -编译器会对函数模板进行两次编译
        对模板代码本身进行编译
        对参数替换后的代码进行编译

注意事项
    函数模板本身不允许隐式类型转换
        自动推导类型时，必须严格匹配
        显式类型指定时，能够进行隐式类型转换
    对于多参数函数模板
        无法自动推导返回值类型
        可以从左向右部分指定类型参数(工程中将返回值参数作为第一个类型参数)
<==
*/
class Base
{
private:
    Base(const Base &); // 私有化类拷贝构造函数
};

template <typename T>
void Swap(T &a, T &b)
{
    T t = a; // 对于Base类，因为私有化了拷贝构造函数而报错
    a = b;
    b = t;
}

typedef void(FuncI)(int &, int &);
typedef void(FuncD)(double &, double &);
typedef void(FuncB)(Base &, Base &);

int main()
{
    FuncI *pi = Swap; // pi = Swap;
    FuncD *pd = Swap;
    // FuncB *pb = Swap;

    cout << "Swap = " << (void *)(void (*)(int &, int &))Swap << endl;
    cout << "pi = " << reinterpret_cast<void *>(pi) << endl;
    cout << "pd = " << reinterpret_cast<void *>(pd) << endl;
    // cout << "pb = " << reinterpret_cast<void *>(pb) << endl;

    return 0;
}