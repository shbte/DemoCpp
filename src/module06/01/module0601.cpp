#include <iostream>

using namespace std;

/*
==>
C++中支持三种不同的继承方式,默认继承方式为private
    public继承
        父类成员在子类中保持原有访问级别
    private继承
        父类成员在子类中变为私有成员
    protected继承
        父类中的公有成员变为保护成员,其它成员保持不变

面向对象中的访问级别不只是public和private
protected修饰的成员不能被外界所访问
protected使得子类能够访问父类的成员
protected关键字是为了继承而专门设计的
没有protected就无法完成真正意义上的代码复用
<==
*/
class Parent
{
private:
    int m_a;

protected:
    int m_b;

public:
    int m_c;

    void set(int a, int b, int c)
    {
        this->m_a = a;
        this->m_b = b;
        this->m_c = c;
    }
};

// public表示从父类继承来的成员访问级别不超过public，超过则变为public
class Child_A : public Parent
{
public:
    void print()
    {
        cout << "Child_A::print()" << endl;

        // m_a为私有成员(private),子类不继承
        // cout << "m_a=" << m_a << endl;

        cout << "m_b=" << m_b << endl;
        cout << "m_c=" << m_c << endl;
    }
};

// protected表示从父类继承来的成员访问级别不超过protected，超过则变为protected
class Child_B : protected Parent
{
public:
    void print()
    {
        cout << "Child_A::print()" << endl;

        // m_a为私有成员(private),子类不继承
        // cout << "m_a=" << m_a << endl;

        cout << "m_b=" << m_b << endl;
        cout << "m_c=" << m_c << endl;
    }
};

// private表示从父类继承来的成员访问级别不超过private，超过则变为private
class Child_C : private Parent
{
public:
    void print()
    {
        cout << "Child_A::print()" << endl;

        this->set(3, 3, 3);

        // m_a为私有成员(private),子类不继承
        // cout << "m_a=" << m_a << endl;

        cout << "m_b=" << m_b << endl;
        cout << "m_c=" << m_c << endl;
    }
};

int main()
{
    Parent p;
    
    Child_A a;
    Child_B b;
    Child_C c;

    p.set(10, 10, 10);

    a.set(1, 1, 1);
    // 不可访问，因为b类是保护继承方式，b.set为protected，不能在外界调用
    // b.set(2, 2, 2);
    // 不可访问，因为b类是私有继承方式，c.set为private，不能在外界调用
    // c.set(3, 3, 3);

    a.print();
    b.print();
    c.print();

    return 0;
}