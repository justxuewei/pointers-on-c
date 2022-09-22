#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ARR_LENGTH 10

int find_char(char **strings, char value);

int main(void) {
    // 1. 对于没有初始化的值编译器默认赋值 NULL
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

int find_char(char **strings, char value) {
    char *string;
    // 2. `*strings++` 先取值然后把 `char *` 值加一，即把数组的索引加一
    while((string = *strings++) != NULL) {
        while ( *string != '\0' ) {
            if (*string++ == value) {
                return TRUE;
            }
        }
    }
    return FALSE;
}
