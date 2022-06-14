#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_

template <typename T>
class SmartPointer
{
private:
    T *mp;

public:
    SmartPointer(T *t = NULL)
    {
        mp = t;
    }

    SmartPointer(const SmartPointer<T> &obj)
    {
        mp = obj.mp;

        // const对象不可修改，进行类型转换后取消原对象指针指向
        const_cast<SmartPointer<T> &>(obj).mp = NULL;
    }

    SmartPointer<T> &operator=(const SmartPointer<T> &obj)
    {
        if (this != obj)
        {
            delete mp;
            mp = obj.mp;

            // const对象不可修改，进行类型转换后取消原对象指针指向
            const_cast<SmartPointer<T> &>(obj).mp = NULL;
        }

        return *this;
    }

    // get函数获取指针
    T *get()
    {
        return mp;
    }

    ~SmartPointer()
    {
        delete mp;
    }
};

#endif