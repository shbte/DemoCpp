#include <iostream>

/*
==>
i++: 返回的是一个临时对象(不是i)，然后i+1
++i: 返回的是+1之后的i，不是临时对象
<==
*/
int main()
{
    int i = 1;
    printf("%d,%d\n", ++i, ++i); // 3,3
    printf("%d,%d\n", ++i, i++); // 5,3
    printf("%d,%d\n", i++, i++); // 6,5
    printf("%d,%d\n", i++, ++i); // 8,9
    return 0;
}