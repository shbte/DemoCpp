#include <iostream>

using namespace std;

/*
==>
多重继承(子类有不止一个父类)，即子类中有不止一个虚函数表指针
强制类型转换，但是指针指向还是原来的，并没有进行修正
    BaseB *pba = (BaseB *)pa;
dynamic_case<type>类型转换，会对指针值进行修正，指针指向转换后类型
    BaseB *pbb = dynamic_cast<BaseB *>(pa);
<==
*/
class BaseA
{
public:
    virtual void funA()
    {
        cout << "BaseA::funA()" << endl;
    }
};

class BaseB
{
public:
    virtual void funB()
    {
        cout << "BaseB::funB()" << endl;
    }
};

class Derived : public BaseA, public BaseB
{
};

int main()
{

    // sizeof(BaseA) = 8, sizeof(BaseB) = 8, sizeof(Derived) = 16   => 两个父类虚函数表指针
    cout << "sizeof(BaseA) = " << sizeof(BaseA) << ", "
         << "sizeof(BaseB) = " << sizeof(BaseB) << ", "
         << "sizeof(Derived) = " << sizeof(Derived) << endl
         << endl;

    Derived derived;
    BaseA *pa = &derived;
    BaseB *pb = &derived;
    BaseB *pba = (BaseB *)pa;
    BaseB *pbb = dynamic_cast<BaseB *>(pa);

    pa->funA();  // BaseA::funA()
    pb->funB();  // BaseB::funB()
    pba->funB(); // BaseA::funA()   => 强制类型转换，但是指针指向还是原来的
    pbb->funB(); // BaseB::funB()   => dynamic_case<type>类型转换，会对指针值进行修正，指针指向转换后类型

    // pa = 0x7ffddef1b710, pb = 0x7ffddef1b718, pba = 0x7ffddef1b710, pbb = 0x7ffddef1b718
    cout << "pa = " << pa << ", "
         << "pb = " << pb << ", "
         << "pba = " << pba << ", "
         << "pbb = " << pbb << endl;

    return 0;
}