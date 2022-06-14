#include <iostream>

using namespace std;

// 设置模板单例模式，解决静态变量、静态函数不使用而浪费的问题
template <typename T>
class Singleton
{
private:
    static T *mp;

public:
    static T *NewInstance();
};
// 静态变量赋值
template <typename T>
T *Singleton<T>::mp = NULL;

// 静态函数
template <typename T>
T *Singleton<T>::NewInstance()
{
    if (mp == NULL)
    {
        mp = new T();
    }

    return mp;
}

class Basic
{
private:
    Basic(){};
    Basic(const Basic &obj);
    Basic &operator=(const Basic &obj);

public:
    void Print()
    {
        cout << "Basic::Print()::this = " << this << endl;
    }

    // 将静态代码放进模板类中，可以让静态属性在使用时再生成
    friend class Singleton<Basic>;
};

int main()
{
    Basic *b0 = Singleton<Basic>::NewInstance();
    b0->Print();

    Basic *b1 = Singleton<Basic>::NewInstance();
    b1->Print();

    Basic *b2 = Singleton<Basic>::NewInstance();
    b2->Print();

    return 0;
}