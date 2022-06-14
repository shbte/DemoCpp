#include <iostream>
#include <memory>

using namespace std;

/*
==>
智能指针的意义
    现代C++开发库中最重要的类模板之一
    C++中自动内存管理的主要手段
    能够在很大程度上避开内存相关的问题

STL中的智能指针auto_ptr
    生命周期结束时，销毁指向的内存空间
    不能指向堆数组，只能指向堆对象(变量)
    一片堆空间只属于一个智能指针对象
    多个智能指针对象不能指向同一片堆空间

小结：
    智能指针C++中自动内存管理的主要手段
    智能指针在各种平台上都有不同的表现形式
    智能指针能够尽可能的避开内存相关的问题
    STL和QT中都提供了对智能指针的支持
<==
*/
class Basic
{
private:
    string ms;

public:
    Basic(string s)
    {
        cout << "Basic::Basic(string s)::s = " << s << ", this = " << this << endl;
        ms = s;
    }

    Basic(const Basic &b)
    {
        cout << "Basic::Basic(const Basic &b)::this = " << this << ", b = " << &b << endl;
        ms = b.ms;
    }

    void Print()
    {
        cout << "Basic::Basic()::ms = " << ms << ", this = " << this << endl;
    }

    ~Basic()
    {
        cout << "Basic::~Basic()::this = " << this << endl;
    }
};

int main()
{
    auto_ptr<Basic> pt0(new Basic("D.T.Software."));
    pt0->Print();

    cout << endl;
    cout << "pt0 = " << pt0.get() << endl;
    cout << endl;

    // 指针重定向
    auto_ptr<Basic> pt1(pt0);
    pt1->Print();

    cout << endl;
    cout << "pt0 = " << pt0.get() << endl; // pt0 = 0
    cout << "pt1 = " << pt1.get() << endl; // pt1 = 0x55bef7faaeb0

    return 0;
}