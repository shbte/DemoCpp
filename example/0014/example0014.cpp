#include <iostream>

using namespace std;

class Basic
{
    static int ms; // 静态成员不占用类大小
    int mi0;
    char c0;
    int mi1;
    char c1;
    int mi2;
    double md0;
};

int main()
{
    cout << "sizeof(Basic) = " << sizeof(Basic) << endl;
    return 0;
}