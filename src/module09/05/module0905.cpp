#include <iostream>

using namespace std;

/*
==>
C++提供了typeid关键字用于获取类型信息
    typeid关键字返回对应参数的类型信息
    typeid返回一个type_info类对象
    当typeid的参数为NULL时将抛出异常

typeid的注意事项
    当参数为类型时：返回静态类型信息
    当参数为变量时：
        不存在虚函数表，返回静态类型信息
        存在虚函数表，返回动态类型信息
    typeid在不同的编译器下拥有不用的行为输出，所以不要使用typeid的返回结果进行判定

小结：
    C+++中有静态类型和动态类型的概念
    利用多态能够实现对象的动态类型识别
    typeid时专用于类型识别的关键字
    typeid能够返回对象的动态类型信息
<==
*/
// 父类拥有虚函数
class Base01
{
public:
    virtual ~Base01(){}; // 将析构函数定义为虚函数以产生虚函数表，实现多态
};
class Child01 : public Base01
{
};

// 父类没有虚函数
class Base02
{
};
class Child02 : public Base02
{
};

// 用以判断拥有虚函数表对象的类型函数
void type01(Base01 *pb)
{
    // 获取对象类型信息
    const type_info &ti = typeid(*pb);
    cout << ti.name() << endl;
}
// 用于判断没拥有虚函数表对象的类型函数
void type02(Base02 *pb)
{
    // 获取对象类型信息
    const type_info &ti = typeid(*pb);
    cout << ti.name() << endl;
}

int main()
{
    Base01 b0;
    Child01 c0;
    // 存在虚函数表，因此，返回的是动态类型信息
    type01(&b0); // 6Base01
    type01(&c0); // 7Child01
    cout << endl;

    Base02 b1;
    Child02 c1;
    // 不存在虚函数表，因此，返回的是静态类型信息
    type02(&b1); // 6Base02
    type02(&c1); // 6Base02

    return 0;
}