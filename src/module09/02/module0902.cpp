#include <iostream>

using namespace std;

/*
==>
同一个try语句可以跟上多个catch语句
    catch语句可以定义具体处理的异常类型
    不同类型的异常由不同的catch语句负责处理
    try语句中可以抛出任何类型的异常
    catch(...)用于处理所有类型的异常
    任何异常都只能被捕获(catch)一次

异常处理的匹配规则
    异常抛出后，自上而下严格匹配每一个catch语句处理的类型
    异常处理匹配时，不进行任何的类型转换

小结：
    C++中直接支持异常处理的概念
    try...catch...是C++中异常处理的专用语句
    try语句处理正常代码逻辑，catch语句处理异常处理
    同一个try语句可以跟上多个catch语句
    异常处理必须严格匹配，不进行任何的类型转换
<==
*/
void func1()
{
    try
    {
        throw 1.0f;
    }
    catch(char c)
    {
        cout << "catch(char c)" << endl;
    }
    catch(short s)
    {
        cout << "catch(short s)" << endl;
    }
    catch(int i)
    {
        cout << "catch(int i)" << endl;
    }
    catch(float f)
    {
        cout << "catch(float f)" << endl;
    }
    catch(double d)
    {
        cout << "catch(double c)" << endl;
    }
    catch(...) // ...表示匹配所有类型，必须放在最后
    {
        cout << "catch(...)" << endl;
    }
}

void func2()
{
    try
    {
        throw "D.S.Software"; // char const*
        // throw string("D.S.Software");
    }
    catch(char *c)
    {
        cout << "catch(char *c)" << endl;
    }
    catch(string s)
    {
        cout << "catch(string s)" << endl;
    }
    catch(const char *cs)
    {
        cout << "catch(const char *cs)" << endl;
    }
}

int main()
{

    func1();
    func2();

    return 0;
}