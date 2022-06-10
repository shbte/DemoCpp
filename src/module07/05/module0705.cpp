#include <iostream>

using namespace std;

/*
==>
dynamic_cast是与继承相关的类型转换关键字
dynamic_cast要求相关的类中必须有虚函数(需要虚函数表确定对象之间是否有继承关系)
用于有直接或间接继承关系的指针(引用)之间
    指针
        转换成功：得到目标类型的指针
        转换失败：得到一个空指针
    引用
        转换成功：得到目标类型的引用
        转换失败：得到一个异常操作信息

小结：
    new/delete会触发构造函数或者析构函数的调用
    构造函数不能成为虚函数，析构函数可以成为虚函数
    构造函数和析构函数中都无法产生多态行为
    dynamic_cast是与继承相关的专用转换关键字
<==
*/
class BaseA
{
private:
    int ma;

public:
    BaseA()
    {
        cout << "BaseA::BaseA()::this = " << this << endl;
    }

    virtual ~BaseA() // 使用dynamic_cast进行类型转换时，父类必须有虚函数(虚函数表保存了父类与子类之间的继承关系，类型转换必须是父类与子类之间，所以需要虚函数表确定对象之间是否有继承关系)
    {
        cout << "BaseA::~BaseA()" << endl;
    }
};

class BaseB
{
private:
    int mb;

public:
    BaseB()
    {
        cout << "BaseB::BaseB()::this = " << this << endl;
    }

    ~BaseB()
    {
        cout << "BaseB::~BaseB()" << endl;
    }
};

class Derived : public BaseA, public BaseB
{
public:
    Derived()
    {
        cout << "Derived::Derived()::this = " << this << endl;
    }

    ~Derived()
    {
        cout << "Derived::~Derived()" << endl;
    }
};

int main()
{
    BaseA *d0 = new Derived; // BaseA::BaseA()::this = 0x5602a1e63eb0; BaseB::BaseB()::this = 0x5602a1e63ebc; Derived::Derived()::this = 0x5602a1e63eb0

    Derived *pdb0 = dynamic_cast<Derived *>(d0);
    BaseB *pbb = dynamic_cast<BaseB *>(d0);

    if (pdb0 && pbb) // 转换结果之可能在运行阶段才能得到，所以需要对结果进行判断
    {
        cout << "pdb0 = " << pdb0 << ", pbb = " << pbb << endl; // pdb0 = 0x5602a1e63eb0, pbb = 0x5602a1e63ebc
    }
    else
    {
        cout << "Cast error!" << endl;
    }

    BaseA *d1 = new BaseA; // BaseA::BaseA()::this = 0x5602a1e642e0

    Derived *pdb1 = dynamic_cast<Derived *>(d1);

    if (pdb1) // 转换结果之可能在运行阶段才能得到，所以需要对结果进行判断
    {
        cout << "pdb1 = " << pdb1 << endl;
    }
    else
    {
        cout << "Cast error!" << endl; // Cast error!
    }

    // 因为父类的析构函数为虚函数，所以会调用指针所指向的子类的析构函数
    delete d0; // Derived::~Derived(); BaseB::~BaseB(); BaseA::~BaseA()

    delete d1; // BaseA::~BaseA()

    return 0;
}