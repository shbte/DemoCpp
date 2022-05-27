#include <stdio.h>

/*
引用在C++中的内部实现是一个指针常量，因此引用所占用的空间大小与指针相同。
    可以避免由于指针操作不当而带来的内存错误问题
*/
struct TRef
{
    char &r;
};

/*
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/01$ ./a.out
sizeof(char&) = 1
sizeof(rc) = 1
sizeof(TRef) = 8
sizeof(ref.r) = 1
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/example/src/01$
*/
int main()
{
    char c = 'c';
    char &rc = c;
    TRef ref = {c};

    printf("sizeof(char&) = %d\n", sizeof(char &));
    printf("sizeof(rc) = %d\n", sizeof(rc));

    printf("sizeof(TRef) = %d\n", sizeof(TRef)); // 8
    printf("sizeof(ref.r) = %d\n", sizeof(ref.r));
    return 0;
}