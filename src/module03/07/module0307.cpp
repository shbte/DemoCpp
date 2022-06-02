#include <iostream>

#include "IntArray.h"

/*
二次构造
    定义私有的第一阶段构造函数：
        与资源无关的初始化操作，不可能出现异常情况的操作
    定义私有的第二阶段构造函数：
        需要使用资源的操作，可能出现异常的情况，如：内存申请、访问文件
    定义实例公有函数：
        构造函数正常时，返回正常对象。不正常时，删除半成品对象返回NULL
*/
int main()
{
    IntArray *intAObj = IntArray::NewInstance(5);

    intAObj->setVaule(2, 6);

    for (int i = 0; i < intAObj->getLength(); i++)
    {
        int v = 0;
        intAObj->getValue(i, v);
        std::cout << "intAObj[" << i << "]=" << v << std::endl;
    }

    return 0;
}