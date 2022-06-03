#include <iostream>

/*
==>
重载操作符，可使用operator关键字
    Type operator sign(const Type& p1, const Type& p2)
    sign为操作符：+、-、*、/

操作符重载的本质是通过函数扩展操作符功能
operator关键字是实现操作符重载的关键
操作符重载遵循相同的函数重载规则
全局函数和成员函数都可以实现对操作符的重载

C++规定赋值操作符(=)只能重载为成员函数，因为编译器默认实现了赋值操作(=)，个人再实现会重载错误
操作符重载不能改变原操作符的优先级
操作符重载不能改变操作符的个数
操作符重载不应改变操作符的原有语义
<==
*/
class Complex
{
private:
    int a;
    int b;

public:
    Complex() {}

    Complex(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    void setA(int i)
    {
        this->a = i;
    }

    int getA() const
    {
        return this->a;
    }

    void setB(int i)
    {
        this->b = i;
    }

    int getB() const
    {
        return this->b;
    }

    // 成员函数重载操作符，优先使用成员操作符重载函数(全局操作符重载函数优先级低)
    Complex operator+(const Complex &p)
    {
        std::cout << "Complex operator+(const Complex &p)" << std::endl;

        Complex ret;

        ret.a = this->a + p.a;
        ret.b = this->b + p.b;

        return ret;
    }

    // 利用友元实现对象相加
    friend Complex add(const Complex &p1, const Complex &p2);
    // friend Complex operator+(const Complex &p1, const Complex &p2);
};

// 全局函数重载操作符
Complex operator+(const Complex &p1, const Complex &p2)
{
    std::cout << "Complex operator+(const Complex &p1, const Complex& p2)" << std::endl;

    Complex ret;

    // 友元可以直接访问私有成员变量
    // ret.a = p1.a + p2.a;
    // ret.b = p1.b + p2.b;

    // 不通过友元，使用公有方法
    ret.setA(p1.getA() + p2.getA());
    ret.setB(p1.getB() + p2.getB());

    return ret;
}

Complex add(const Complex &p1, const Complex &p2)
{
    std::cout << "Complex add(const Complex &p1, const Complex &p2)" << std::endl;

    Complex ret;

    // ret.a = p1.getA() + p2.getA();
    // ret.b = p1.getB() + p2.getB();

    // 友元可以直接访问私有成员变量
    ret.a = p1.a + p2.a;
    ret.b = p1.b + p2.b;

    return ret;
}

int main()
{
    Complex p1(1, 2);
    Complex p2(3, 4);

    Complex p3 = add(p1, p2);
    std::cout << "Comple::a=" << p3.getA() << ", Complex::b=" << p3.getB() << std::endl;

    p3 = p1.operator+(p2); // 使用方法相加，于下面操作符相加等价
    std::cout << "Comple::a=" << p3.getA() << ", Complex::b=" << p3.getB() << std::endl;
    p3 = p1 + p2; // 使用操作符相加，与上面方法相加等价
    std::cout << "Comple::a=" << p3.getA() << ", Complex::b=" << p3.getB() << std::endl;

    return 0;
}