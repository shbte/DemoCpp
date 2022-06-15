#include <iostream>

using namespace std;

/*
==>
C++中仍然支持C语言中的可变参数函数
C++编译器的匹配优先级
    1、重载函数
    2、函数模板
    3、可变参函数
<==
*/
// 普通函数：匹配等级1(高)
void func(int i)
{
    cout << "func(int i)" << endl;
}
// 模板函数：匹配等级2(中)
template <typename T>
void func(T t)
{
    cout << "func(T t)" << endl;
}
// 可变参函数：匹配等级3(低)
void func(...)
{
    cout << "func(...)" << endl;
}

class Base
{
public:
    Base(){};
    virtual ~Base(){};
};

// 利用模板函数和可变参函数的匹配优先级来判断变量是否为指针变量
template <typename T>
bool IsPtr(T *t)
{
    cout << "<bool IsPtr(T *t)>";
    return true;
}
bool IsPtr(...)
{
    cout << "<bool IsPtr(...)>";
    return false;
}

// 利用宏定义的判断函数返回值进行判断变量是否为指针变量
template <typename T>
char Isptr(T *t)
{
    cout << "<char Isptr(T *t)>";
    return '1';
}
int Isptr(...)
{
    cout << "<int IsPtr(...)>";
    return '0';
}

#define ISPTR(p) (sizeof(Isptr(p)) == sizeof(char))

int main()
{
    int i = 1;
    int *pi = &i;
    Base b;
    Base *pb = &b;

    func(i);

    cout << "i is pointer : " << IsPtr(i) << endl;   // i is pointer : <bool IsPtr(...)>0
    cout << "pi is Pointer : " << IsPtr(pi) << endl; // pi is Pointer : <bool IsPtr(T *t)>1

    cout << "b is pointer : " << IsPtr(b) << endl;   // b is pointer : <bool IsPtr(...)>0
    cout << "pb is pointer : " << IsPtr(pb) << endl; // pb is pointer : <bool IsPtr(T *t)>1

    // 宏定义判断方式不会执行函数，匹配不执行
    cout << "b is pointer : " << ISPTR(b) << endl;   // b is pointer : 0
    cout << "pb is pointer : " << ISPTR(pb) << endl; // pb is pointer : 1

    return 0;
}