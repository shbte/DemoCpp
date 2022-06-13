#include <iostream>
#include <memory>

using namespace std;

/*
==>

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