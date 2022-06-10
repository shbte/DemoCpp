#include <iostream>

using namespace std;

/*
==>
多重继承
    子类将拥有子类所有成员，利用sizeof(Child)来判断

tip：
方法返回值为对象时，方法外还可以使用n次，并不会离开作用域而被释放
方法返回值为对象指针时，方法外还可以使用1次，然后因离开作用域而被释放
<=
*/
class Parent_A
{
private:
    int ma;

public:
    Parent_A(int i)
    {
        this->ma = i;
    }
};

class Parent_B
{
private:
    int mb;

public:
    Parent_B(int i)
    {
        this->mb = i;
    }

    int getMB()
    {
        return this->mb;
    }
};

class Child : public Parent_A, public Parent_B // 多重继承，子类将拥有子类所有成员sizeof(Child)
{
private:
    int mi;

public:
    Child(int i) : Parent_A(1), Parent_B(2) // 父类没有默认构造函数，需要手动调用父类构造函数
    {
        this->mi = i;
    }

    Child(const Child &c) : Parent_A(3), Parent_B(4)
    {
        cout << "Child" << endl;
    }

    Child &operator=(const Child &c)
    {
        this->mi = c.mi;

        cout << "operator" << endl;

        return *this;
    }

    int getMI()
    {
        return this->mi;
    }
};

void fun1()
{
    int i = 0;
    Child c0(0);
    Child c1(1);
    Child c2(3);
    Child *c3 = new Child(3);
    Child *c4 = new Child(4);
    Child *c5 = new Child(5);

    // &i = 0x7ffc41778e64,
    // &c0 = 0x7ffc41778e84, &c1 = 0x7ffc41778e90, &c2 = 0x7ffc41778e9c,
    // c3 = 0x5599b28682c0, c4 = 0x5599b28682e0, c5 = 0x5599b2868300
    cout << "&i = " << &i << ", "
         << "&c0 = " << &c0 << ", "
         << "&c1 = " << &c1 << ", "
         << "&c2 = " << &c2 << ", "
         << "c3 = " << c3 << ", "
         << "c4 = " << c4 << ", "
         << "c5 = " << c5 << endl
         << endl;
}

int fun2()
{
    int ret(10);

    cout << "fun2()::ret = " << ret << ", this = " << &ret << endl;

    return ret;
}

Child fun3()
{
    Child ret(10);

    cout << "fun3()::ret = " << ret.getMI() << ", this = " << &ret << endl;

    return ret;
}

Child *fun4()
{
    Child c(3);
    Child *ret = &c;

    cout << "fun4()::c = " << &c << ", ret = " << ret << endl;

    return ret;
}

int main()
{

    Child c(0);
    cout << "sizeof(Parent_A) = " << sizeof(Parent_A) << endl;
    cout << "sizeof(Parent_B) = " << sizeof(Parent_B) << endl;
    cout << "sizeof(Child) = " << sizeof(Child) << endl
         << endl; // sizeof(Child) = 12

    Parent_A *pa = &c;
    Parent_B *pb = &c;

    // &c = 0x7ffc4348bb2c, pa = 0x7ffc4348bb2c, pb = 0x7ffc4348bb30
    // c和pa从ma开始，pb从mb开始
    cout << "&c = " << &c << ", "
         << "pa = " << pa << ", "
         << "pb = " << pb << endl
         << endl;

    // 返回值为对象时，结果不会被释放
    int retI = fun2();
    cout << "retI = " << retI << ", this = " << &retI << endl;
    cout << "retI = " << retI << ", this = " << &retI << endl;
    cout << "retI = " << retI << ", this = " << &retI << endl;
    // 返回值为类对象时，结果不会被释放
    Child retC = fun3();
    cout << "retC = " << retC.getMI() << ", this = " << &retC << endl;
    cout << "retC = " << retC.getMB() << ", this = " << &retC << endl;
    cout << "retC = " << retC.getMI() << ", this = " << &retC << endl;

    // 返回值为对象指针时，结果保留一次以后被释放
    Child *pRetC = fun4();
    cout << "retC = " << pRetC->getMB() << ", this = " << pRetC << endl;
    cout << "retC = " << pRetC->getMB() << ", this = " << pRetC << endl;
    cout << "retC = " << pRetC->getMI() << ", this = " << pRetC << endl;

    return 0;
}