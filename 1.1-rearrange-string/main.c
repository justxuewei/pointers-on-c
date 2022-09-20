#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20     // 最大列号
#define MAX_INPUT 1000  // 最大行号

/** function prototype **/
int read_column_numbers(int columns[], int max);
// QUESTION(justxuewei): int const *columns 和 columns[] 有什么区别吗？
void rearrange(char *output, char const *input, int n_columns,
               int const columns[]);

int main(void) {
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    n_columns = read_column_numbers(columns, MAX_COLS);

    // gets 读一个字符串直到 '\n'，丢弃 '\n' 并在结尾添加一个 '\0'，当没有新行的
    // 时候会返回 NULL。
    while (gets(input) != NULL) {
        printf("Original input: %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line: %s\n", output);
    }

    return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max) {
    int num = 0;
    int ch;

    while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
        num += 1;

    if (num % 2 != 0) {
        // puts 是 gets 的反向操作
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }

    return num;
}

void rearrange(char *output, char const *input, int n_columns,
               int const columns[]) {
    int col;
    int output_col;
    int len;

    len = strlen(input);
    output_col = 0;

    for (col = 0; col < n_columns; col += 2) {
        int nchars = columns[col + 1] - columns[col] + 1;
        if (columns[col] >= len || output_col == MAX_INPUT - 1) {
            break;
        }
        if (output_col + nchars > MAX_INPUT - 1) {
            nchars = MAX_INPUT - output_col - 1;
        }
        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }

    output[output_col] = '\0';
}
