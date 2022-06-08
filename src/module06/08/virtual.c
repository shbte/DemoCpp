#include "virtual.h"

#include <stdio.h>
#include <malloc.h>

struct DemoClass
{
    int mi;
    int mj;
};

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

int Demo_Add(Demo *pThis, int value)
{
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

int Device_Add(Device *pThis, int value)
{
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
