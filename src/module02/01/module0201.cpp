#include <iostream>

/*
==>
C++中通过new关键字进行动态内存申请
C++中的动态内存申请是基于类型进行的
delete关键字用于内存释放(内存释放知识标记可以被复用，而不是一定破坏内存中的值)
    变量释放：delete
    数组释放：delete[]

new关键字与malloc函数的区别
    new关键字是c++的一部分，malloc是由c库提供的函数
    new以具体类型为单位进行内存分配，malloc以字节为单位进行内存分配
    new在申请单个类型变量时可进行初始化，malloc不具备内存初始化的特征
<==
*/

int *newArrayVariableBack()
{
    // 只分配空间，没有赋值初始化
    int *iV = new int[3];
    std::cout << "newArrayVariable=> int *iV = new int[3];" << std::endl;
    std::cout << "newArrayVariable=> *iV[0]=" << *iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    // std::cout << "newArrayVariable=> *iV[1]=" << *++iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    // std::cout << "newArrayVariable=> *iV[2]=" << *++iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;

    // 释放iV内存
    delete iV;
    std::cout << "newArrayVariable=> delete iV;" << std::endl;
    std::cout << "newArrayVariable=> *iV[0]=" << *iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    std::cout << "newArrayVariable=> *iV[1]=" << *++iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    std::cout << "newArrayVariable=> *iV[2]=" << *++iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    std::cout << std::endl;

    // 分配空间时同时初始化(赋值)
    iV = new int{1};
    std::cout << "newArrayVariable=> iV = new int{1};" << std::endl;
    std::cout << "newArrayVariable=> *iV[0]=" << *iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    std::cout << std::endl;

    // iV={2}; // "int" 类型的值不能用于初始化 "int *" 类型的实体
    // iV={1, 2}; // 初始值设定项值太多
    // iV=new int[]{2, 3}; // 不允许使用不完整的类型

    iV = new int[3]{2, 3, 4};
    std::cout << "newArrayVariable=> iV = new int[3]{2, 3, 4}" << std::endl;
    std::cout << "newArrayVariable=> *iV[0]=" << *iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    std::cout << "newArrayVariable=> *iV[1]=" << *++iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    std::cout << "newArrayVariable=> *iV[2]=" << *++iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;

    // 释放iV内存
    delete -- --iV;
    std::cout << "newArrayVariable=> delete iV" << std::endl;
    std::cout << "newArrayVariable=> *iV[0]=" << *iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    std::cout << "newArrayVariable=> *iV[1]=" << *++iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    std::cout << "newArrayVariable=> *iV[2]=" << *++iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    std::cout << std::endl;

    iV = new int(5);
    std::cout << "newArrayVariable=> iV = new int(5);" << std::endl;
    std::cout << "newArrayVariable=> *iV[0]=" << *iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    std::cout << std::endl;

    return iV;
}

int *newArrayVariable()
{

    int *p = new int(5);

    std::cout << "newArray=> *p= " << *p << ", p= " << p << std::endl;

    delete p;
    std::cout << "newArray=> *p= " << *p << ", p= " << p << std::endl;

    return p;
}

void out(int *p, int nSize)
{
    int tmp = nSize;
    while (nSize--)
    {
        std::cout << "p[" << tmp - nSize << "]= " << *p << ", address=" << p << std::endl;
        p++;
    }
    std::cout << std::endl;
}

int *newArray(int nSize)
{
    int *p = new int[nSize];

    for (int i = 0; i < nSize; i++)
    {
        p[i] = i + 1;
    }

    out(p, nSize);

    delete[] p;
    out(p, nSize);

    return p;
}

int main()
{

    // int *iV = newArrayVariableBack();

    // 多次打印出了newArrayVariable::iv，说明iV不是普通的局部变量(不再栈内)，这是通过new在堆区开辟了空间，需要手动释放
    // std::cout << "main=> *iV[0]=" << *iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    // std::cout << "main=> *iV[0]=" << *iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    // std::cout << "main=> *iV[1]=" << *++iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    // std::cout << "main=> *iV[2]=" << *++iV << ", iV=" << iV << ", &iV=" << &iV << std::endl;
    // std::cout << std::endl;

    int *p = newArrayVariable();
    std::cout << "main=> *p= " << *p << ", p= " << p << std::endl;
    std::cout << std::endl;

    int nSize = 10;
    p = newArray(nSize);

    out(p, nSize);

    return 0;
}