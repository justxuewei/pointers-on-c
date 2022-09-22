#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ARR_LENGTH 10

int find_char(char **strings, char value);

int main(void) {
    char *string_arr[ARR_LENGTH];
    string_arr[0] = "hello, world";
    string_arr[1] = "hi, bupt";
    string_arr[2] = "my name is justxuewei";

    // 'z' not exists
    // char expected_ch = 'z';
    // 'j' exists
    char expected_ch = 'j';

    if (!find_char(string_arr, expected_ch)) {
        printf("We not found '%c' in the string array\n", expected_ch);
        return EXIT_FAILURE;
    }
    printf("We found '%c' in the string array\n", expected_ch);
    return EXIT_SUCCESS;
}

// 与 6.2-find-char 最大的不同是这里不再声明一个 `char *string`，而是直接操作
// strings 指针，这样的问题是 strings 的值将被永久性改动，不能重复使用。
int find_char(char **strings, char value) {
    while (*strings != NULL) {
        while (**strings != '\0') {
            // 1. 结论是这个括号是必须的，`*(*strings)++` 展开是说：
            // 1.1. **strings 这个是定位到 char 类型数据；
            // 1.2. (*strings)++ 是对 char * 加一，即定位到下一个 char 的地址。
            // 假设说如果不加的话，应该是：
            // 2.1. **strings 这个还是不变；
            // 2.2. strings++ 相当于是对数据索引 +1。
            if (*(*strings)++ == value) {
                return TRUE;
            }
        }
        // 2. 等效于 `strings += 1;`，这里 strings
        // 是左值，可以理解为数组中指向当前 string 的地址
        strings++;
    }
    return FALSE;
}
