#include <iostream>

#include "HeapArray.h"

using namespace std;

/*
==>
小结：
    模板参数可以是数值型参数
    数值型模板参数必须在编译器期间唯一确定
    数组类模板是基于数值型模板参数实现的
    数组类模板是简易的线性表数据结构
<==
*/
// 定义模板函数输出模板数组
template <typename T>
void func(HeapArray<T> *t, int len, T value)
{
    if (t)
    {
        HeapArray<T> &a = t->self();

        for (int i = 0; i < a.getLength(); i++)
        {
            a[i] = i + value;
        }

        for (int i = 0; i < a.getLength(); i++)
        {
            cout << "a[" << i << "] = " << a[i] << ", ";
        }
        cout << endl
             << endl;
    }
}

int main()
{
    int len = 8;
    HeapArray<int> *ph0 = HeapArray<int>::NewInstance(len);
    func(ph0, ph0->getLength(), 10);

    len = 10;
    HeapArray<double> *ph1 = HeapArray<double>::NewInstance(len);
    func(ph1, ph1->getLength(), 10.2);

    len = 26;
    HeapArray<char> *ph2 = HeapArray<char>::NewInstance(len);
    func(ph2, ph2->getLength(), 'a');

    return 0;
}