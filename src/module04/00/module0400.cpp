#include <iostream>

/*
==>
概念：
    友元时C++的一种关系
    友元关系发生在函数与类之间、类与类之间
    友元关系是单项的，不能传递

用法：
    在类中以关键字friend声明友元
    类的友元可以是其它类或者具体函数
    友元不是类的一部分
    友元不受类中访问级别的限制
    友元可以直接访问具体类的所有成员

友元的尴尬：
    友元是为了兼顾C语言的高效而诞生的
    友元直接破坏了面向对象的封装性
    友元在实际产品中的高效时得不偿失的
    友元在现代软件工程中已经逐渐遗弃了

注意事项：
    友元关系不具备传递性
    类的友元可以是其它类的成员函数
    类的友元可以是某个完整的类
        所有的成员函数都是友元

小结：
    友元是为了兼顾C语言的高效而诞生的
    友元直接破坏了面向对象的封装性
    友元关系不具备传递性
    类的友元可以是其它类的成员函数
    类的友元可以是某个完整的类
<==
*/
class A
{
    int i = 0;
public:
    A(int i)
    {
        this->i = i;
    }

    int getClassAI(A& a)
    {
        int ret = a.i;
        return ret;
    }

    ~A(){};

    friend class B;
};

class B
{
    int i = 0;
public:
    B(int i)
    {
        this->i = i;
    }

    int getClassAI(A& a)
    {
        int ret = a.i;
        return ret;
    }

    ~B(){};

    friend class C;
};

class C
{
    int i = 0;
public:
    C(int i)
    {
        this->i = i;
    }

    // C不是A的友元，所以C不能直接访问A的静态成员变量
    // int getCLassAI(A& a)
    // {
    //     int ret = a.i;
    //     return ret;
    // }

    int getClassBI(B& b)
    {
        int ret = b.i;
        return ret;
    }

    int getClassCI(C& c)
    {
        int ret = c.i;
        return ret;
    }

    ~C(){};
};

int main()
{
    A a(1);
    B b(2);
    C c(3);

    printf("b.getClassAI()=%d\n", b.getClassAI(a));
    printf("c.getClassBI()=%d\n", c.getClassBI(b));
    printf("c.getClassCI()=%d\n", c.getClassCI(c));

    return 0;
}