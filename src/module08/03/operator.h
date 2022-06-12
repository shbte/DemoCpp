#ifndef __MODULE_OPERATOR__
#define __MODULE_OPERATOR__

template <typename T>
class Operator
{
public:
    T add(T a, T b);
    T minus(T a, T b);
    T multiply(T a, T b);
    T divide(T a, T b);
};

template <typename T>
T Operator<T>::add(T a, T b)
{
    return a + b;
}

template <typename T>
T Operator<T>::minus(T a, T b)
{
    return a - b;
}

template <typename T>
T Operator<T>::multiply(T a, T b)
{
    return a * b;
}

template <typename T>
T Operator<T>::divide(T a, T b)
{
    return a / b;
}

#endif