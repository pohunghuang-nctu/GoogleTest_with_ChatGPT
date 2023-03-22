/*
Treat yourself as a C language expert. please show me a simple C program, 
which contains 2 functions, one called "switch example", 
another called "while loop example". 
They are created only to demonstrate the usage of "switch" and "while". 
Later I would create test cases for these 2 functions, 
so, please return some integer values in these functions.
And also, I need this C program can be compiled by gcc.
*/

#include <stdio.h>
#include "example.h"

int switch_example(int value) {
    int result;
    switch (value) {
        case 1:
            result = 10;
            break;
        case 2:
            result = 20;
            break;
        case 3:
            result = 30;
            break;
        default:
            result = 0;
    }
    return result;
}

int while_loop_example(int count) {
    int i = 0;
    int sum = 0;
    while (i < count) {
        sum += i;
        i++;
    }
    return sum;
}

/*
int main() {
    int value = 2;
    int count = 5;
    int switch_result = switch_example(value);
    int while_result = while_loop_example(count);
    printf("The result of switch_example is %d\n", switch_result);
    printf("The result of while_loop_example is %d\n", while_result);
    return 0;
}
*/
// gcc example.c -o example
