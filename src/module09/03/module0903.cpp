#include <iostream>

using namespace std;

/*
==>
catch中捕获的异常可以被重新解释后抛出

异常的类型可以是自定义类型
对于类类型异常的匹配以就是自上而下严格匹配
赋值兼容性原则在异常匹配中依然适用
一般而言
    匹配子类异常的catch放在上部
    匹配父类异常的catch放在下部

工程中会定义一系列的异常类
每个类代表工程中可能出现的一种异常类型
代码复用时可能需要重解释不同的异常类
在定义catch语句块时推荐使用引用(&)作为参数

C++标准库中提供了实用异常类族
标准库中的异常都是从exception类派生的
exception类有两个主要的分支
    logic_error
        常用于程序中的可避免逻辑错误
    runtime_error
        常用于程序中无法避免的恶性错误

小结：
    catch语句块中可以抛出异常
    异常的类型可以是自定义类类型
    赋值兼容性原则在异常匹配中依然适用
    标准库中的异常都是从exception类派生的
<==
*/
class Base
{
};

class Exception : public Base
{
private:
    int m_id;
    string m_description;

public:
    Exception(int i, string s)
    {
        m_id = i;
        m_description = s;
    }

    int id() const
    {
        return m_id;
    }

    string description() const
    {
        return m_description;
    }
};

/*
    假设当前函数为第三方库函数，因此，我们无法修改源代码

    函数名: func(int i)
    返回值: int
                -1 ==> 参数异常
                -2 ==> 运行异常
                -3 ==> 超时异常
*/
void func(int i)
{
    if (i < 0)
    {
        throw -1;
    }

    if (i > 100)
    {
        throw -2;
    }

    if (i == 10)
    {
        throw -3;
    }

    cout << "Run func()..." << endl;
}

void MyFunc(int i)
{
    try
    {
        func(i);
    }
    catch (int i)
    {
        switch (i)
        {
        case -1:
            throw Exception(-1, "Invalid Parmeter");
            break;
        case -2:
            throw Exception(-2, "Runtime Exception");
            break;
        case -3:
            throw Exception(-3, "Timeout Exception");
            break;
        }
    }
}

int main()
{
    try
    {
        // MyFunc(-2);
        MyFunc(10);
        // MyFunc(120);
        // MyFunc(5);
    }
    // catch(const Base &b) // 父类在前会判断进父类，所以父类不能在前面判断
    // {
    //     cout << "catch(const Base &b)" << endl;
    // }
    catch (const Exception &ex) // 推荐使用引用(&)作为参数，防止临时对象的拷贝产生
    {
        cout << "Exception info : " << endl;
        cout << "       " << ex.id() << endl;
        cout << "       " << ex.description() << endl;
    }
    catch (const Base &b)
    {
        cout << "catch(const Base &b)" << endl;
    }

    return 0;
}