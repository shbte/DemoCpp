#include <iostream>

template <class T>
int getArrayLength(T& arr)
{
    int length = 0;

    length = sizeof(arr) / sizeof(arr[0]);

    return length;
}

void intArray()
{
    //静态数组

    // int iArray00[]; // 不允许使用不完整的类型
    int iArray01[3];
    int length = getArrayLength(iArray01);
    std::cout << "length: " << length << std::endl;

    int iArray04[]{1, 2};
    length = getArrayLength(iArray04);
    std::cout << "length: " << length << std::endl;
    int iArray05[3]{1, 2};
    length = getArrayLength(iArray05);
    std::cout << "length: " << length << std::endl;

    int iArray08[] = {1, 2};
    length = getArrayLength(iArray08);
    std::cout << "length: " << length << std::endl;
    int iArray09[3] = {1, 2};
    length = getArrayLength(iArray09);
    std::cout << "length: " << length << std::endl;

    // 动态数组

    int *iArray10 = new int[5];
    length = getArrayLength(iArray10);
    std::cout << "length: " << length << std::endl;
    int *iArray11 = new int[5]{1, 2, 3};
    length = getArrayLength(iArray11);
    std::cout << "length: " << length << std::endl;
}

int main()
{

    intArray();

    return 0;
}