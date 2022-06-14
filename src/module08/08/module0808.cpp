#include <iostream>

#include "SmartPointer.h"

using namespace std;

/*
==>
手动实现auto_ptr智能指针
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
    }

    void Print()
    {
        cout << "Basic::Print()::this = " << this << endl;
    }

    ~Basic()
    {
        cout << "Basic::~Basic()::this = " << this << endl;
    }
};

int main()
{
    SmartPointer<Basic> ps0(new Basic("D.T.Software.")); // Basic::Basic(string s)::s = D.T.Software., this = 0x562709f64eb0
    ps0.get()->Print();                                  // Basic::Print()::this = 0x562709f64eb0
    cout << "ps0 = " << ps0.get() << endl                // ps0 = 0x562709f64eb0
         << endl;

    // 指针转移ps0=>ps1
    SmartPointer<Basic> ps1(ps0);
    ps0.get()->Print();                    // Basic::Print()::this = 0
    ps1.get()->Print();                    // Basic::Print()::this = 0x562709f64eb0
    cout << "ps0 = " << ps0.get() << endl; // ps0 = 0
    cout << "ps1 = " << ps1.get() << endl; // ps1 = 0x562709f64eb0

    // Basic::~Basic()::this = 0x562709f64eb0

    return 0;
}