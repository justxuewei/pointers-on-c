#include <stdio.h>
#include <stdlib.h>

#define ptr_to_char_ char *

typedef char *ptr_to_char;

/**
 * 这个例子说明 typedef 和 #define 的区别，结论是“如果想要定义类型必须使用
 * typedef”。
 */
int main(void) {
    char *str = "hello, world";
    // a 和 b 都是一个指向 char 的指针
    ptr_to_char a, b;
    a = str;
    b = str;
    printf("a = \"%s\", b = \"%s\"\n", a, b);

    // c 是一个指向 char 的指针，而 d 是一个字符
    ptr_to_char_ c, d;
    c = str;
    // warning: 3.3-typedef/main.c:18:7: warning: assignment to ‘char’ from
    // ‘char *’ makes integer from pointer without a cast [-Wint-conversion]
    d = str;
    printf("c = \"%s\", d = \"%d\"\n", c, d);

    return EXIT_SUCCESS;
}
