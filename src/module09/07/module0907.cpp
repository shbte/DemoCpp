#include <iostream>

using namespace std;

/*
==>
检查a.out执行是否有内存泄漏命令
    valgrind --tool=memcheck --leak-check=full ./a.out

构造函数中抛出异常
    构造过程立即停止
    当前对象无法生成
    析构函数不会被调用
    对象所占用的空间立即收回

小结：
    C++中依然支持可变参函数
    可变参函数无法很好的处理对象参数
    利用函数模板和可变参函数能够判断指针变量
    构造函数和析构函数中不要抛出异常
<==
*/
class Base
{
public:
    Base()
    {
        cout << "Base::Base()" << endl;
        // throw 0;
    }

    ~Base()
    {
        cout << "Base::~Base()" << endl;
    }
};
int main()
{
    // 将内存1解释为Base
    Base* pb = reinterpret_cast<Base *>(1);

    try
    {
        pb = new Base();
    }
    catch(int i)
    {
        cout << "Exception..." << endl;
    }
    // 异常时：p : 0x1
    // 正常时：p : 0x559fcbbb2eb0
    cout << "p : " << pb << endl;

    delete pb;

    return 0;
}