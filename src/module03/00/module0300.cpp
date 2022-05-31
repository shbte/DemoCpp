#include <iostream>

/*
==>
struct的默认访问级别为public
class的默认访问级别为private
<==
*/
struct A
{
    int i = 1;

    int getI()
    {
        return i;
    }
};

class B
{
    int i = 2;

    int getI()
    {
        return i;
    }
};

class C
{
public:
    int i = 3;

    int getI()
    {
        return i;
    }
};

int main()
{
    // struct的默认访问级别为public
    A a;
    std::cout << "A(struct).i= " << a.i << std::endl;
    std::cout << "A(struct).getI()= " << a.getI() << std::endl;

    // class的默认访问级别为private
    B b;
    // std::cout << "B(class).i= " << b.i << std::endl;  // 已声明，但不可访问
    // std::cout << "B(class).getI()=" << b.getI() << std::endl; // 已声明，但不可访问

    // 修改class的访问级别为public，即可访问class
    C c;
    std::cout << "C(class).i= " << c.i << std::endl;
    std::cout << "C(class).getI()=" << c.getI() << std::endl;

    return 0;
}