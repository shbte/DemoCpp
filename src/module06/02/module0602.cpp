#include <iostream>

using namespace std;

/*
==>
子类对象在创建时需要调用父类构造函数进行初始化
先执行父类构造函数，然后执行成员的构造函数
父类构造函数显式调用需要在初始化列表中进行
子类对象在销毁时需要调用父类析构函数进行清理
析构顺序与构造函数对称相反
<==
*/
class Object
{
public:
    Object()
    {
        cout << "Object()::this=" << this << endl;
    }

    Object(string s)
    {
        cout << "Object(string s)::this=" << this << endl;
    }

    ~Object()
    {
        cout << "~Object()::this=" << this << endl;
    }
};

class Parent
{
public:
    Parent()
    {
        cout << "Parent()::this=" << this << endl;
    }

    Parent(string s)
    {
        cout << "Parent(string s)::this=" << this << endl;
    }

    ~Parent()
    {
        cout << "~Parent()::this=" << this << endl;
    }
};

class Child : public Parent
{
private:
    Object obj0;
    Object obj1;

public:
    Child() : Parent("int i"), obj1("ss") // 利用初始化列表的方式显式调用构造函数,没有显式调用时，默认隐式调用无参构造函数
    {
        cout << "Child()::this=" << this << endl;
    }

    Child(string s) // 没有显式调用，将会默认调用无参构造函数
    {
        cout << "Child(string s)::this=" << this << endl;
    }

    Child(int i) : Parent("int i") // 利用初始化列表的方式显式调用构造函数,没有显式调用时，默认隐式调用无参构造函数
    {
        cout << "Chile(int i) : Parent(\"int i\")::this=" << this << endl;
    }

    ~Child()
    {
        cout << "~Child()::this=" << this << endl;
    }
};

int main()
{

    /*
        Parent(string s)::this=0x7ffd094bb22a => 同一地址
        Object()::this=0x7ffd094bb22a => 同一地址
        Object(string s)::this=0x7ffd094bb22b
        Child()::this=0x7ffd094bb22a => 同一地址
    */
    // 父类构造函数(默认调用无参构造函数，指定时优先调用指定构造函数) => 成员构造函数 => 子类构造函数
    Child c0;
    cout << endl;

    /*
        Parent()::this=0x7ffd094bb22c => 同一地址
        Object()::this=0x7ffd094bb22c => 同一地址
        Object()::this=0x7ffd094bb22d
        Child(string s)::this=0x7ffd094bb22c => 同一地址
    */
    // 父类构造函数(默认调用无参构造函数，指定时优先调用指定构造函数) => 成员构造函数 => 子类构造函数
    Child c1("ss");
    cout << endl;

    /*
        Parent(string s)::this=0x7ffd094bb22e => 同一地址
        Object()::this=0x7ffd094bb22e => 同一地址
        Object()::this=0x7ffd094bb22f
        Chile(int i) : Parent("int i")::this=0x7ffd094bb22e => 同一地址
    */
    // 父类构造函数(默认调用无参构造函数，指定时优先调用指定构造函数) => 成员构造函数 => 子类构造函数
    Child c2(3);
    cout << endl;

    /*
        ~Child()::this=0x7ffd094bb22e
        ~Object()::this=0x7ffd094bb22f
        ~Object()::this=0x7ffd094bb22e
        ~Parent()::this=0x7ffd094bb22e
        ~Child()::this=0x7ffd094bb22c
        ~Object()::this=0x7ffd094bb22d
        ~Object()::this=0x7ffd094bb22c
        ~Parent()::this=0x7ffd094bb22c
        ~Child()::this=0x7ffd094bb22a
        ~Object()::this=0x7ffd094bb22b
        ~Object()::this=0x7ffd094bb22a
        ~Parent()::this=0x7ffd094bb22a
    */
    return 0;
}