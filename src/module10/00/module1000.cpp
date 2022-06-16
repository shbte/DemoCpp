#include <iostream>

using namespace std;

/*
==>
mutable是为了突破const函数的限制而设计的
mutable成员变量将永远处于可改变的状态
mutable在实际的项目开发中被严禁滥用
<==
*/
class Base
{
private:
    mutable int mValue; // mutable可以突破const的只读限制
    int *const mCount; // 指针只读变量，保护地址，不保护地址存储的值

public:
    Base(int i) : mCount(new int(0)) // 指针只读变量需要初始化时赋值
    {
        mValue = i;
        // mCount = new int(0); // 指针只读变量需要初始化时赋值
    }

    void setValue(int i) const
    {
        mValue = i;
        *mCount = *mCount + 1;
    }

    int getValue() const
    {
        *mCount = *mCount + 1;
        return mValue;
    }

    int getCount() const
    {
        return *mCount;
    }
};

void func1()
{
    Base b(0);
    b.setValue(5);

    cout << "b.getValue = " << b.getValue() << endl;
    cout << "b.getValue = " << b.getValue() << endl;
    cout << "b.getValue = " << b.getValue() << endl;
    cout << "b.getCount = " << b.getCount() << endl;

    const Base cb(0);
    cb.setValue(10);

    cout << "cb.getValue = " << cb.getValue() << endl;
    cout << "cb.getValue = " << cb.getValue() << endl;
    cout << "cb.getCount = " << cb.getCount() << endl;
}

int main()
{

    func1();

    return 0;
}