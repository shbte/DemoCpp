#include <iostream>

using namespace std;

/*
==>
类模板可以被特化
    指定类模板的特定特化
    部分类型参数必须显式指定
    根据类型参数分开实现类模板

类模板的特化类型
    部分特化：用特定规则约束类型参数
    完全特化：完全显式指定类型参数

注意事项：
    特化只是模板的分开实现，本质上是同一个类模板
    特化类模板的使用方式是统一的，必须显式指定每一个类型参数

重定义和特化的不同
    重定义
        一个类模板的一个新类(或者两个类模板)
        使用的时候需要考虑如何选择的问题
    特化
        以统一的方式使用类模板的特化类
        编译器自动优先选择特化类

小结：
    类模板可以定义任意多个不同的类型参数
    类模板可以被部分特化和完全特化
    特化的本质是模板的分开实现
    函数模板只支持完全特化
    工程中使用模板特化代替类(函数)重定义
<==
*/
template <typename T1, typename T2>
class Basic
{
public:
    void add(T1 a, T2 b)
    {
        cout << "Basic::add(T1 a, T2 b)::";
        cout << a + b << endl;
    }
};

template <typename T>
class Basic<T, T>
{
public:
    void add(T a)
    {
        cout << "Basic::add(T a)::";
        cout << a << endl;
    }
};

template <>
class Basic<void *, void *>
{
public:
    void add(void *a, void *b)
    {
        cout << "Base<void*, void*>::add(void* a, void* b)::";
        cout << "Error to add void* parm..." << endl;
    }
};

template <typename T1, typename T2>
class Basic<T1 *, T2 *>
{
public:
    void add(T1 *a, T2 *b)
    {
        cout << "Basic<int *, double *>::add(int *a, double *b)::";
        cout << *a + *b << endl;
    }
};

int main()
{

    Basic<int, double> b0;
    b0.add(1, 3.1);

    Basic<float, float> b1;
    b1.add(2.2);

    Basic<void *, void *> b2;
    b2.add(NULL, NULL);

    int a = 1;
    double b = 3.1;
    Basic<int *, double *> b3;
    b3.add(&a, &b);

    return 0;
}