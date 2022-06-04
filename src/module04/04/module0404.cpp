#include <iostream>
#include <sstream>

// 使用宏定义完成字符串和数字之间的相互转化
#define TO_NUMBER(s, n) (istringstream(s) >> n)
#define TO_STRING(n) ((ostringstream() << n).str())

using namespace std;

// 字符串排序
void string_sort(string s[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (s[j] > s[j + 1])
            {
                swap(s[j], s[j + 1]);
            }
        }
    }
}

// 字符串数组拼接后输出
string string_add(string s[], int len)
{
    string ret = "";

    for (int i = 0; i < len; i++)
    {
        ret += s[i] + "、";
    }

    int tmpLen = ((string)("、")).length();   // 3: 三个字符
    ret = ret.substr(0, ret.size() - tmpLen); // size()和length()作用相同

    return ret;
}

// 字符串输出
void string_out(string s[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << s[i] << endl;
    }
}

// 重写string类的右移操作符，字符串右移
string operator>>(const string s, int n)
{
    string ret = "";
    unsigned int pos = 0;

    unsigned int sLen = s.length();
    n = n % sLen;
    pos = sLen - n;

    ret = s.substr(pos);
    ret += s.substr(0, pos);

    return ret;
}

int main()
{
    string s[] = {
        "Hello world",
        "D.T.Software",
        "C#",
        "Java",
        "C/C++",
        "Python",
        "TypeScript",
        "typeName"};

    // 该方式得不到string类型数组的长度，得到的是第一个元素的长度
    s->size();   // ==> s[0].size() ==> 11
    s->length(); // 同上

    /*
    typedef basic_string<char> string;

    template <typename T>
    struct basic_string {
        char* begin_;
        size_t size_;
        union {
            size_t capacity_;
            char sso_buffer[16];
        };
    };
    32 = 8 + 8 + 16;
    */
    // string对象存储的内容大小与其所占的空间（栈空间）是没有关系的，利用这点获取string类型数组的长度
    cout << "sizeof(s[0])=" << sizeof(s[0]) << endl;
    cout << "sizeof(s[1])=" << sizeof(s[1]) << endl;
    cout << "sizeof(s[2])=" << sizeof(s[2]) << endl;
    cout << "sizeof(s[3])=" << sizeof(s[3]) << endl;
    cout << "sizeof(s[4])=" << sizeof(s[4]) << endl;
    cout << "sizeof(s[5])=" << sizeof(s[5]) << endl;
    cout << "sizeof(s[6])=" << sizeof(s[6]) << endl;
    cout << "sizeof(s[7])=" << sizeof(s[7]) << endl;
    cout << "sizeof(s)=" << sizeof(s) << endl;
    cout << endl;

    int len = sizeof(s) / sizeof(s[0]);

    // 字符串数组拼接后输出
    cout << string_add(s, len) << endl;

    // 字符串数组排序
    string_sort(s, len);
    cout << endl;
    string_out(s, len);

    // 字符串数组拼接后输出
    cout << endl;
    cout << string_add(s, len) << endl;

    // 字符串转化为数字
    cout << endl;
    double n = 0;
    if (TO_NUMBER("409b00", n))
    {
        cout << "n=" << n << endl;
    }

    n = 59486;
    cout << TO_STRING(n) << endl;

    string s1 = "458456245";
    unsigned m = 2;
    cout << s1 << ">>" << m << "=" << (s1 >> m) << endl;

    return 0;
}