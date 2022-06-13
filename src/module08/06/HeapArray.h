#ifndef _HEAPARRAY_H_
#define _HEAPARRAY_H_

template <typename T>
class HeapArray
{
private:
    int mLen;
    T *mPointer;
    HeapArray(int size);
    HeapArray(const HeapArray<T> &h);
    bool construct();

public:
    static HeapArray<T> *NewInstance(int size);
    void setValue(int index, T value);
    void getValue(int index, T &value);
    T &operator[](int index);
    HeapArray<T> &self();
    int getLength();
    ~HeapArray<T>();
};

template <typename T>
HeapArray<T>::HeapArray(int size)
{
    this->mLen = size;
}

template <typename T>
HeapArray<T>::HeapArray(const HeapArray<T> &h)
{
    this->mLen = h.mLen;
    this->mPointer = h.mPointer;
}

template <typename T>
bool HeapArray<T>::construct()
{
    bool ret = false;

    mPointer = new T[mLen];

    if (mPointer)
    {
        ret = true;
    }

    return ret;
}

template <typename T>
HeapArray<T> *HeapArray<T>::NewInstance(int size)
{
    HeapArray<T> *ret = new HeapArray<T>(size);

    if (!(ret && ret->construct()))
    {
        delete ret;
        ret = 0;
    }

    return ret;
}

template <typename T>
T &HeapArray<T>::operator[](int index)
{
    return mPointer[index];
}

template <typename T>
void HeapArray<T>::setValue(int index, T value)
{
    mPointer[index] = value;
}

template <typename T>
void HeapArray<T>::getValue(int index, T &value)
{
    value = mPointer[index];
}

template <typename T>
HeapArray<T> &HeapArray<T>::self()
{
    return *this;
}

template <typename T>
int HeapArray<T>::getLength()
{
    return this->mLen;
}

template <typename T>
HeapArray<T>::~HeapArray()
{
}

#endif