#include <iostream>

#include <csetjmp>

using namespace std;

/*
==>
结构化程序设计的三大特性：顺序执行、分支执行、循环执行

异常的概念：
    程序在运行的过程中可能产生异常
    异常(Exception)与Bug的区别
        异常时程序运行时可预料的执行分支
        Bug是程序中的错误，是不被预期的运行方式

异常(Exception)和Bug的对比
    异常
        运行时产生除0的情况
        需要打开的外部文件不存在
        数组访问时越界
    Bug
        使用野指针
        堆数组使用结束后未释放
        选择排序无法处理长度为0的数组

小结：
    程序中不可避免的会发生异常
    异常是在开发阶段就可以预见的运行时问题
    C语言中通过经典的if...else...方式处理异常
    C++中存在更好的异常处理方式
<==
*/
static jmp_buf env;

double divide1(double a, double b, int *valid)
{
    const double delta = 0.000000000001;
    double ret = 0;

    // 约定if为正常，else为异常
    if (!((-delta < b) && (b < delta)))
    {
        ret = a / b;
        *valid = 1;
    }
    else
    {
        *valid = 0;
    }

    return ret;
}

void func1(int a, int b)
{
    int valid = 0;
    double ret = divide1(a, b, &valid);

    if (valid)
    {
        cout << a << " / " << b << " = " << ret << endl;
    }
    else
    {
        cout << a << " / " << b << " = "
             << "Error..." << endl;
    }
}

double divide2(double a, double b)
{
    const double delta = 0.000000000001;
    double ret = 0;

    // 约定if为正常，else为异常
    if (!((-delta < b) && (b < delta)))
    {
        ret = a / b;
    }
    else
    {
        longjmp(env, 1); // 跳转到71行进行判断，破坏了顺序执行的特性
    }

    return ret;
}

void func2(double a, double b)
{
    double ret = divide2(a, b);

    if (setjmp(env) == 0)
    {
        cout << a << " / " << b << " = " << ret << endl;
    }
    else
    {
        cout << a << " / " << b << " = "
             << "Error..." << endl;
    }
}

int main()
{
    func1(1, 1);
    func1(0, 1);
    func1(1, 0);
    cout << endl;

    func2(1, 1);
    func2(0, 1);
    func2(1, 0);

    return 0;
}