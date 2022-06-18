#### mutable : 00

```
mutable是为了突破const函数的限制而设计的
mutable成员变量将永远处于可改变的状态
mutable在实际的项目开发中被严禁滥用
```

#### new/delete : 01

```
new/delete的本质时C++预定义的操作符
C++对这两个操作符做了严格的行为定义
    new
        1、获取足够的内存空间(默认为堆空间)
        2、在获取的空间中调用构造函数创建对象
    delete
        1、调用析构函数销毁对象
        2、归还对象所占用的空间(默认为堆空间)

在C++中能够重载new/delete操作符
    全局重载(不推荐)
    局部重载(针对具体类进行重载)
重载new/delete的意义在于改变动态对象创建时的内存分配方式

new/delete的重载方式
// static member function
void *operator new (unsigned int size)
{
    void *ret = NULL;

    // ret point to allocated memory

    return ret;
}
// static member function
void operator delete (void *p)
{
    // free the memory which is pointed by p
}

如何在指定的地址上创建C++对象
    在类中重载new/delete操作符
    在new的操作符重载函数中返回指定的地址
    在delete操作符重载中标记对应的地址可用
```

#### new[]/delete[] : 02

```
new[]/delete[]与new/delete完全不同
    动态对象数组创建通过new[]完成
    动态对象数组的销毁通过delete[]完成
    new[]/delete[]也能够被重载，进而改变内存管理方式

new[]/delete[]的重载方式
// static member function
void *operator new[](unsigned long size)
{
    return malloc(size);
}
//static member function
void operator delete[](void *p)
{
    free(p);
}

注意事项
    new[]实际需要返回的内存空间可能比期望的要多
    对象数组占用的内存中需要保存数组信息
    数组信息用于确定构造函数和析构函数的调用次数

小结：
    new/delete的本质为操作符
    可以通过全局函数重载new/delete(不推荐)
    可以针对具体的类重载new/delete
    new[]/delete[]与new/delete完全不同
    new[]/delete[]也是可以被重载的操作符
    new[]返回的内存空间可能比期望的要多
```

#### 异常 : 03

```
如果异常无法被处理，termainate()结束函数会被自动调用
默认情况下，terminate()调用库函数abort()终止程序
abort()函数使得程序执行异常而立即退出
C++支持替换默认的terminate()函数实现

terminate()函数的替换
    自定义一个无返回值无参数的函数
        不能抛出任何异常
        必须以某种方式结束当前程序
    调用set_terminate()设置自定义的结束函数
        参数类型为void(*)()
        返回值为默认的terminate()函数入口地址

小结：
    如果异常没有被处理，最后terminate()结束整个程序
    terminate()是整个程序释放系统资源的最后机会
    结束函数可以自定义，当不能继续抛出异常
    析构函数中不能抛出异常，可能导致terminate()多次调用

函数抛出的异常不在规格说明中，全局函数unexpected()被调用
默认的unexpected()函数会调用全局terminate()函数
可以自定义函数替换默认的unexpected()函数实现
注意：不是所有的C++编译器都支持这个标准行为

unexpected()函数的替换
    自定义一个无返回值无参数的函数
        能够再次抛出异常
            当异常符合触发函数的异常规格说明时，恢复程序执行
            否则，调用全局terminate()函数结束程序
    调用ser_unexpected()设置自定义的异常函数
        参数类型为void(*)()
        返回值为默认的unexpected()函数入口地址

小结：
    C++中的函数可以声明异常规格说明
    异常规格说明可以看作接口的一部分
    函数抛出的异常不在规格说明中，unexpected()被调用
    unexpected()中能够再次抛出异常
        异常能够匹配，会需程序的执行
        否则，调用terminate()结束程序
```

#### new : 04

```
动态内存申请
    malloc函数申请失败时返回NULL值
    new关键字申请失败时(根据编译器的不同)
        返回NULL值
        抛出std::bad_alloc异常

new关键字在C++规范中的标准行为
    在堆空间申请足够大的内存
        成功：
            在获取的空间中调用构造函数创建对象
            返回对象的地址
        失败：
            抛出std::bad_alloc异常
    new在分配内存时
        如果空间不足，会调用全局的new_handler()函数
        new_handler()函数中抛出std::bad_alloc异常
    可以自定义new_handler()函数
        处理默认的new内存分配失败的情况

解决方案：
    全局范围(不推荐)
        重新定义new/delete的实现，不抛出任何异常
        自定义new_handler()函数，不抛出任何异常
    类层次范围
        重载new/delete，不抛出任何异常
    单次动态内存分配
        使用nothrow参数，指明new不抛出异常
结论：
    不是所有的编译器都遵循C++的标准规范
    编译器可能重定义new的实现，并在实现中抛出bad_alloc异常
    编译器的默认实现中，可能没有设置全局的new_handler()函数
    对于移植性要求较高的代码，需要考虑new的具体细节

小结：
    不同的编译器在动态内存分配上的实现细节不同
    malloc函数在内存申请失败时返回NULL值
    new关键字在内存申请失败时
        可能返回NULL值
        可能抛出bad_alloc异常
```