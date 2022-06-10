#include "virtual.h"

#include <stdio.h>
#include <malloc.h>

// 虚函数表结构，保存虚函数地址
struct VTable
{
    int (*fun)(void *, int);
};

// 函数声明，需提前声明，虚函数表中需要使用
static int Virtual_Demo_Add(void *ptr_demo, int value);
static int Virtual_Device_Add(void *ptr_device, int value);
// 父类虚函数表
static struct VTable g_Virtual_Demo_Add = {Virtual_Demo_Add}; // 第二步：虚函数表中取出函数指针
// 子类虚函数表
static struct VTable g_Virtual_Device_Add = {Virtual_Device_Add};

// 父类结构体对象
struct DemoClass
{
    struct VTable *pVir; // 虚函数表指针，指向具体(父类、子类)函数地址
    int mi;
    int mj;
};

// 子类结构体对象
struct DeviceClass
{
    struct DemoClass demo; // 继承(子类拥有父类的成员)
    int mk;
};

/* 父类方法 */
// 创建父类结构体对象(DemoClass)
Demo *Demo_Create(int i, int j)
{
    // 开辟结构体对象(Democlass)的空间
    struct DemoClass *result = (struct DemoClass *)malloc(sizeof(struct DemoClass));

    // 开辟成功时，结构体成员赋值
    if (result)
    {
        // result->pVir = &Virtual_Demo_Add; // 要体现出从虚函数表中返回地址，该方式没体现出虚函数表作用
        result->pVir = &g_Virtual_Demo_Add; // 第一步：虚函数指针指向虚函数表
        result->mi = i;
        result->mj = j;
    }

    // printf("Demo_Create::mi=%d, mj=%d, this=%p\n", result->mi, result->mj, result);
    // printf("Demo_Create::sizeof(DemoClass)=%d\n", (int)sizeof(struct DemoClass));

    return result;
}

// 获取结构体对象(DemoClass)成员mi的值
int Demo_GetI(Demo *pThis)
{
    // 获取结构体对象指针(Demo*=>DemoClass*)
    struct DemoClass *ptr_demo = (struct DemoClass *)pThis;

    int ret = ptr_demo->mi;

    return ret;
}

// 获取结构体对象(DemoClass)成员mj的值
int Demo_GetJ(Demo *pThis)
{
    // 获取结构体对象指针(Demo*=>DemoClass*)
    struct DemoClass *ptr_demo = (struct DemoClass *)pThis;

    int ret = ptr_demo->mj;

    return ret;
}

// 外界调用函数和虚函数接口，父类和子类的父类对象通过该函数调用虚函数
int Demo_Add(Demo *pThis, int value)
{
    puts("\nDemo_Add(Demo *pThis, int value)");

    // 获取结构体对象指针(Demo*=>DemoClass*)
    struct DemoClass *ptr_demo = (struct DemoClass *)pThis;

    // 父类对象从虚函数表中获取父类虚函数方法地址，然后调用
    int ret = ptr_demo->pVir->fun(pThis, value);

    return ret;
}

// 父类虚函数方法
int Virtual_Demo_Add(Demo *pThis, int value)
{
    puts("Virtual_Demo_Add(Demo *pThis, int value)");

    // 获取结构体对象指针(Demo*=>DemoClass*)
    struct DemoClass *ptr_demo = (struct DemoClass *)pThis;

    int ret = ptr_demo->mi + ptr_demo->mj + value;

    return ret;
}

/* 子类方法 */
// 创建子类结构体对象(DeviceClass)
Device *Device_Create(int i, int j, int k)
{
    // 开辟结构体对象(DeviceClass)的空间
    struct DeviceClass *result = (struct DeviceClass *)malloc(sizeof(struct DeviceClass));

    if (result)
    {
        result->demo.pVir = &g_Virtual_Device_Add;
        result->demo.mi = i;
        result->demo.mj = j;
        result->mk = k;
    }

    // printf("Device_Create::demo=%p, mk=%d, this=%p\n", &(result->demo), result->mk, result);
    // printf("Device_Create::sizeof(DeviceClass)=%d\n", (int)sizeof(struct DeviceClass));

    return result;
}

// 获取结构体对象(DeviceClass)成员DemoClass指针
Demo *Device_GetDemo(Demo *pThis)
{
    // 获取结构体对象(DeviceClass)指针
    struct DeviceClass *ptr_device = (struct DeviceClass *)pThis;
    // 获取结构体对象(DeviceClass)成员demo指针
    struct DemoClass *ret = &(ptr_device->demo);

    return ret;
}

// 获取结构体对象(DeviceClass)成员mk的值
int Device_GetK(Device *pThis)
{
    // 获取结构体对象(DeviceClass)指针
    struct DeviceClass *ptr_device = (struct DeviceClass *)pThis;

    int ret = ptr_device->mk;

    return ret;
}

// 外界调用函数，当使用虚函数表时，不使用该函数
int Device_Add(Device *pThis, int value)
{
    puts("\nDevice_Add(Device *pThis, int value)");

    // 获取结构体对象(DeviceClass)指针
    struct DeviceClass *ptr_device = (struct DeviceClass *)pThis;

    // 子类对象从虚函数表中获取子类虚函数方法地址，然后调用
    int ret = ptr_device->demo.pVir->fun(pThis, value);

    return ret;
}

// 子类虚函数方法
int Virtual_Device_Add(Device *pThis, int value)
{
    puts("Virtual_Device_Add(Device *pThis, int value)");

    // 获取结构体对象(DeviceClass)指针
    struct DeviceClass *ptr_device = (struct DeviceClass *)pThis;
    // 获取结构体对象(DeviceClass)成员demo指针
    struct DemoClass *ptr_demo = &(ptr_device->demo);

    int mi = Demo_GetI(ptr_demo);
    int mj = Demo_GetJ(ptr_demo);

    int ret = mi + mj + ptr_device->mk + value;

    return ret;
}

void Free(void *pThis)
{
    printf("free::this=%p\n", pThis);

    // 释放开辟的结构体对象空间
    free(pThis);

    pThis = NULL;
}
