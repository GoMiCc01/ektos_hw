#include <stdio.h>

extern int x_global;       // This declaration allows us to access the global variable defined in secondary.c
static int x_static = 100; // This variable is in the file scope and cannot be accessed from other files

static void scope_demo(const int condition) // This function demonstrates variable scope within switch cases
{
    switch (condition)
    {
    case 1:
    {
        int x = 10;
        printf("x = %d\n", x);
        break;
    }
    case 2:
    {
        int x = 20;
        printf("x = %d\n", x);
        break;
    }
    default:
    {
        puts("Invalid condition\n");
        break;
    }
    }
}

static void local_static_demo(void) // This function demonstrates the use of a local static variable
{
    static int count = 0; // This variable retains its value between function calls
    count++;
    printf("Count = %d\n", count);
}

int main(void)
{
    scope_demo(1);

    int x = 30; // This variable is in the scope of main and does not interfere with the x variables in scope_demo
    printf("x in main = %d\n", x);

    {
        int x = 40; // This variable is in a new block scope and does not interfere with the x in main
        printf("x in block scope = %d\n", x);
    }

    printf("x_global = %d\n", x_global); // Accessing the global variable defined in secondary.c

    local_static_demo(); // First call, count should be 1
    local_static_demo(); // Second call, count should be 2

    printf("x_static = %d\n", x_static); // Accessing the static variable defined in this file

    return 0;
}