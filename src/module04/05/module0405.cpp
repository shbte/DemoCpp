#include <iostream>

using namespace std;

// 记录字符串中出现数字的次数
int isDigitCount(const string s)
{
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            count++;
        }
    }

    return count;
}

// 实现下标法访问自定义对象成员(数组操作符重载)
class A
{
    int a[5];

public:
    int &operator[](int i) // 返回引用对象，用以赋值
    {
        return a[i];
    }

    int operator[](const string s) // 返回对象值，用以打印输出
    {
        if (s == "1th")
        {
            return a[0];
        }
        if (s == "2th")
        {
            return a[1];
        }
        if (s == "3th")
        {
            return a[2];
        }
        if (s == "4th")
        {
            return a[3];
        }
        if (s == "5th")
        {
            return a[4];
        }

        return 0;
    }

    int length()
    {
        return sizeof(a) / sizeof(int);
    }
};

int main()
{
    string s = "asdf1234000gt";

    cout << "\"" << s << "\"中的数字个数为：" << isDigitCount(s) << endl;

    A a;

    // 赋值
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = i + 10;
    }

    // 打印值
    for (int i = 0; i < a.length(); i++)
    {
        cout << "a[" << i << "]=" << a[i] << endl;
    }
    cout << "a[\"1th\"]=" << a["1th"] << endl;
    cout << "a[\"2th\"]=" << a["2th"] << endl;
    cout << "a[\"3th\"]=" << a["3th"] << endl;
    cout << "a[\"4th\"]=" << a["4th"] << endl;
    cout << "a[\"5th\"]=" << a["5th"] << endl;
    cout << "a[\"6th\"]=" << a["6th"] << endl;

    return 0;
}