#include <iostream>

using namespace std;

/*
==>
子类可以定义父类中的同名成员
子类中的成员将隐藏父类中的同名成员
父类中的同名成员依然存在于子类中
通过作用域分辨符(::)访问父类中的同名成员

子类中的函数将隐藏父类的同名函数
子类无法重载父类中的成员函数(因为作用与不同，不构成重载)
使用作用域分辨符访问父类中的同名函数
子类可以定义父类中完全相同的成员函数(因为作用与不同，不构成冲突)

子类可以重定义父类中已经存在的成员函数
这种重定义发生在继承中，叫做函数重写
函数重写时同名覆盖的一种特殊情况

子类分为子类的子类对象和子类的父类对象
Parent p0 = c0; // 这是将子类c0的父类对象调用父类的拷贝构造函数创建新父类对象p0
<==
*/
class Child_A;
class Parent
{
public:
    int mv;

    Parent()
    {
        this->mv = 0;
        cout << "Parent()::this->mv=" << this->mv << ", this=" << this << endl;
    }

    Parent(int i)
    {
        this->mv = i;
        cout << "Parent(int i)::this->mv=" << this->mv << ", this=" << this << endl;
    }

    Parent(const Parent &p) // 子类对象初始化父类时，调用父类拷贝构造函数
    {
        this->mv = p.mv;
        cout << "Parent(const Parent &p)::this->mv=" << this->mv << ", this=" << this << endl;
    }

    void add(int i) // 父类方法，子类不重写例
    {
        this->mv += i;
        cout << "Parent::add(int i)::this->mv=" << this->mv << ", this=" << this << endl;
    }

    void add(int a, int b) // 父类方法，子类重写例
    {
        this->mv += (a + b);
        cout << "Parent::add(int a, int b)::this->mv=" << this->mv << ", this=" << this << endl;
    }

    Parent &operator=(const Parent &p)
    {
        this->mv = p.mv;
        cout << "Parent::&operator=(const Parent &p)::this->mv" << this->mv << ", this=" << this << endl;
        return *this;
    }

    ~Parent()
    {
        cout << "~Parent()::this=" << this << endl;
    }
};

// 继承父类，重写父类方法
class Child_A : public Parent
{
public:
    int mv;

    Child_A()
    {
        this->mv = 0;
        cout << "Child_A()::this->mv=" << this->mv << ", this=" << this << endl;
    }

    Child_A(int i)
    {
        this->mv = i;
        cout << "Child_A(int i)::this->mv=" << this->mv << ", this=" << this << endl;
    }

    void add(int a, int b) // 重写父类方法
    {
        this->mv += (a + b);
        cout << "Child::add(int a, int b)::this->mv=" << this->mv << ", this=" << this << endl;
    }

    void add(int x, int y, int z) // 新加父类同名方法
    {
        this->mv += (x + y + z);
        cout << "Child::add(int x, int y, int z)::this-mv=" << this->mv << ", this=" << this << endl;
    }

    Child_A &operator=(const Child_A &p)
    {
        this->mv = p.mv;
        cout << "Child_A::&operator=(const Child_A &p)::this->mv" << this->mv << ", this=" << this << endl;
        return *this;
    }

    ~Child_A()
    {
        cout << "~Child_A()::this=" << this << endl;
    }
};

// 继承父类，但不重写父类方法
class Child_B : public Parent
{
public:
    int mv;

    Child_B()
    {
        this->mv = 0;
        cout << "Child_B()::this->mv=" << this->mv << ", this=" << this << endl;
    }

    Child_B(int i)
    {
        this->mv = i;
        cout << "Child_B(int i)::this->mv=" << this->mv << ", this=" << this << endl;
    }

    ~Child_B()
    {
        cout << "~Child_B()::this=" << this << endl;
    }
};

int main()
{

    Child_A c0; // Parent()::this->mv=0, this=0x7ffcbfa9bb68; Child_A()::this->mv=0, this=0x7ffcbfa9bb68
    Child_B c1; // Parent()::this->mv=0, this=0x7ffcbfa9bb70; Child_B()::this->mv=0, this=0x7ffcbfa9bb70
    cout << endl;

    // 报错，子类存在和父类同名的add函数时，子类匹配不到函数也不会去父类匹配
    // c0.add(1);
    // 子类不存在和父类同名的add函数时，子类匹配不到函数则会去父类匹配，所以这里调用的是父类的add函数
    c1.add(1); // Parent::add(int i)::this->mv=1, this=0x7ffcbfa9bb70

    c0.add(1, 2); // Child::add(int a, int b)::this->mv=3, this=0x7ffcbfa9bb68
    // 利用作用域分辨符来调用父类的add函数(指定作用域)
    c0.Parent::add(3, 4); // Parent::add(int a, int b)::this->mv=7, this=0x7ffcbfa9bb68
    c0.add(1, 2, 3);      // Child::add(int x, int y, int z)::this-mv=9, this=0x7ffcbfa9bb68
    cout << endl;

    // 子类的父类对象初始化父类，p0则为父类对象。调用的是父类的拷贝构造函数，而不是赋值操作符
    Parent p0 = c0; // Parent(const Parent &p)::this->mv=7, this=0x7ffcbfa9bb64
    // 拷贝构造函数
    Parent p1 = p0;
    // 无参构造函数
    Parent p2;
    // 赋值操作符
    p2 = p0;
    cout << endl;

    p0.add(1);    // Parent::add(int i)::this->mv=8, this=0x7ffcbfa9bb64
    p0.add(1, 2); // Parent::add(int a, int b)::this->mv=11, this=0x7ffcbfa9bb64
    // 父类对象在父类中匹配方法，但该方法在子类中，父类无法匹配，所以报错
    // p0.add(1, 2, 3);

    cout << endl;

    /*
    c0:parent	c0:child	c1:parent	c1:child
    0	    	0	    	0	    	0
    (+3+4)		(+1+2)(+1+2+3)			+1

        ~Parent()::this=0x7ffcbfa9bb64
        ~Child_B()::this=0x7ffcbfa9bb70
        ~Parent()::this=0x7ffcbfa9bb70
        ~Child_A()::this=0x7ffcbfa9bb68
        ~Parent()::this=0x7ffcbfa9bb68
    */

    return 0;
}