#include <iostream>

using namespace std;

/*
==>
定义宏代码块
    优点：代码复用，适合所有的类型
    缺点：编译器不知道宏的存在(宏定义由预处理器处理)，缺少类型检查
定义函数
    优点：真正的函数调用，编译器对类型进行检查
    缺点：根据类型重复定义函数，无法代码复用

泛型编程概念：
    不考虑具体数据类型的编程方式

函数模板
    一种特殊的函数可用不同类型进行调用
    看起来和普通函数很相似，区别是类型可被参数化

函数模板的语法规则
    -template关键字用于声明开始进行泛型编程
    -typename关键字用于声明泛型类型(1、自动推导；2、显式调用)
    template<typename T>
    void Swap(T &a, T &b)
    {
        T t = a;
        a = b;
        b = t;
    }

小结：
    函数模板是泛型编程在C++中的应用方式之一
    函数模板能够根据实参对参数类型进行推导
    函数模板支持显示的指定参数类型
    函数模板是C++中重要的代码复用方式
<==
*/
// 宏定义交换值
#define SWAP(t, a, b) \
    do                \
    {                 \
        t c = a;      \
        a = b;        \
        b = c;        \
    } while (0)

// 函数重载交换值
void Swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void Swap(double &a, double &b)
{
    double t = a;
    a = b;
    b = t;
}
void Swap(string &a, string &b)
{
    string t = a;
    a = b;
    b = t;
}

// 模板函数交换值
template <typename T>
void SWap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

// 模板函数排序
template <typename T>
void Sort(T a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                T tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

// 模板函数打印
template <typename T>
void Print(T a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "a[" << i << "]=" << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int i0 = 1;
    int i1 = 2;
    SWAP(int, i0, i1);
    cout << "SWAP::i0 = " << i0 << ", i1 = " << i1 << endl;
    Swap(i0, i1);
    cout << "Swap::i0 = " << i0 << ", i1 = " << i1 << endl;
    // 自动推导
    SWap(i0, i1);
    cout << "SWap::i0 = " << i0 << ", i1 = " << i1 << endl
         << endl;

    double d0 = 3;
    double d1 = 4;
    SWAP(double, d0, d1);
    cout << "SWAP::d0 = " << d0 << ", d1 = " << d1 << endl;
    Swap(d0, d1);
    cout << "Swap::d0 = " << d0 << ", d1 = " << d1 << endl;
    // 显式调用
    SWap<double>(d0, d1);
    cout << "SWap::d0 = " << d0 << ", d1 = " << d1 << endl
         << endl;

    string s0 = "Java";
    string s1 = "C/C++";
    SWAP(string, s0, s1);
    cout << "SWAP::s0 = " << s0 << ", s1 = " << s1 << endl;
    Swap(s0, s1);
    cout << "Swap::s0 = " << s0 << ", s1 = " << s1 << endl;
    // 显式调用
    SWap<string>(s0, s1);
    cout << "SWap::s0 = " << s0 << ", s1 = " << s1 << endl
         << endl;

    int a0[5] = {3, 4, 2, 1, 5};
    int len = sizeof(a0) / sizeof(a0[0]);
    Sort(a0, len);
    Print(a0, len);

    string s2[] = {"Java", "C", "C++", "Basic", "Ruby", "Python", "python"};
    len = sizeof(s2) / sizeof(s2[0]);
    Sort(s2, len);
    Print(s2, len);

    return 0;
}