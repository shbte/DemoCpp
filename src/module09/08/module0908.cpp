#include <iostream>

using namespace std;

/*
==>
class和typename都可以用来声明泛型变量
typename的作用：
    1、在模板定义中声明泛指类型
    2、明确告诉编译器其后的标识符为类型
<==
*/
class Base1
{
public:
    static const int TS = 1;  // 定义成员变量
};

class Base2
{
public:
    struct TS // 定义数据类型TS
    {
        int mi;
    };
};

int a = 1;

template <class T>
void func()
{
    // T::TS *a; // 通过泛指类型 T 内部的静态成员变量 TS 和全局变量 a 进行乘法操作
    typename T::TS *a; // 通过泛指类型 T 内部的数据类型 TS 定义指针变量a
}


int main()
{

    // func<Base1>();
    func<Base2>();

    return 0;
}