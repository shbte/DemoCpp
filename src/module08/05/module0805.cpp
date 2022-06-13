#include <iostream>

using namespace std;

/*
==>
模板参数可以是数值型参数(非类型参数)
    template <typename T, int N>
    void func()
    {
        T a[N]; // 使用模板参数定义局部数组
    }

注意事项：模板参数是在编译阶段被处理的单元，因此，在编译阶段必须准确无误的唯一确定
    变量不能作为模板参数
    浮点数不能作为模板参数
    类对象不能作为模板参数
<==
*/
template <int N>
class Basic;
// 定义数组函数模板
template <typename T, int N>
// template <typename T, double N> // 浮点数不能作为模板参数
// template <typename T, Basic<100> N> // 类对象不能作为模板参数
void func()
{
    T a[N];

    // 数组赋值
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
    }

    // 数组值输出
    for (int i = 0; i < N; i++)
    {
        cout << "a[" << i << "] = " << a[i] << ", ";
    }

    cout << endl;
}

// 定义递归模板类
template <int N>
class Basic
{
public:
    // 定义为静态是为了可以直接进行类名+变量名访问
    // 定义为常量是为了可以初始化赋值
    static const int value = Basic<N - 1>::value + N;
};

// 定义递归开始模板类
template <>
class Basic<1>
{
public:
    // 定义为静态是为了可以直接进行类名+变量名访问
    // 定义为常量是为了可以初始化赋值
    static const int value = 1;
};

int main()
{

    func<int, 10>();

    int a = 10;

    // 变量不能作为模板参数
    // func<int, a>();

    // 浮点数不能作为模板参数
    // func<int, 10.0>();

    // 使用递归模板类计算数列和
    cout << "1 + 2 + 3 + ... + 10 = " << Basic<10>::value << endl;
    cout << "1 + 2 + 3 + ... + 100 = " << Basic<100>::value << endl;

    return 0;
}