#include <iostream>

using namespace std;

/*
==>
抽象类和村纯虚函数
    C++语言中没有抽象类的概念
    C++中通过纯虚函数实现抽象类
    纯虚函数是指只定义原型的成员函数
    一个C++类中存在纯虚函数就成为了抽象类

语法规则
    class Shape
    {
        public:
            virtual double area() = 0;
    }
"=0"用于告诉编译器当前是声明纯虚函数，因此不需要定义函数体。

注意事项：
    抽象类只能定义为父类，只能用作父类被继承
    子类必须实现纯虚函数的具体功能
    纯虚函数被实现后成为虚函数
    如果子类没有实现纯虚函数，则子类成为抽象类

接口(满足下面条件的C++类则称为接口)：
    类中没有定义任何的成员变量
    所有的成员函数都是公有的
    所有的成员函数都是纯虚函数
    接口是一种特殊的抽象类

小结：
    抽象类用于描述现实世界中的抽象概念
    抽象类只能被继承不能创建对象
    C++中没有抽象类的概念
    C++中通过纯虚函数实现抽象类
    类中只存在纯虚函数时成为接口
    接口是一种特殊的抽象类
<==
*/
// 定义接口类
class Area
{
public:
    virtual double area() = 0; // 所有成员只有纯虚函数的类为接口类
};

// 定义抽象类
class Shape : public Area
{
public:
    virtual double area() = 0; // 拥有纯虚函数的类称为抽象类
};

// 正方形类
class Square : public Shape
{
private:
    int mi;

public:
    Square(int i)
    {
        this->mi = i;
    }

    double area()
    {
        double ret = this->mi * this->mi;
        return ret;
    }
};

// 圆形类
class Circle : public Shape
{
private:
    int mi;

public:
    Circle(int r)
    {
        this->mi = r;
    }

    double area()
    {
        double ret = 3.14 * this->mi * this->mi;
        return ret;
    }
};

void compute(Shape *p)
{
    double area = p->area();

    cout << "area = " << area << endl;
}

int main()
{
    Square s(3);
    Circle c(4);

    compute(&s);
    compute(&c);

    return 0;
}