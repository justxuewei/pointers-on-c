#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // 一个指向 int 的指针
    int *pi;
    // 一个指向 int const 的指针: int 的值不能改变，可以修改指向的 int
    int const *icp;
    // 一个指向 int 的指针: int 的值可以修改，不能修改指向的 int
    int * const ipc;
    // 一个指向 int 的指针: 不能修改 int 的值，不能修改指向的 int
    int const * const icpc;

    return EXIT_SUCCESS;
}
