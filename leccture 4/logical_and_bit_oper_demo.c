#include <stdio.h>

void logical_shortcut_demo(void)
{
    // logical operator shortcut example

    //&& is the logical AND operator, it evaluates to true if both operands are true, and false otherwise
    if (0 && (1 / 0 == 0)) // the second part of the condition is not evaluated
    {
        printf("This will never be printed.\n");
    }
    // this happens because the first part of the condition is false, so the whole condition is false regardless of the second part

    //|| is the logical OR operator, it evaluates to true if at least one operand is true, and false otherwise
    if (1 || (1 / 0 == 0)) // the second part of the condition is not evaluated
    {
        printf("This will always be printed.\n");
    }
    // this happens because the first part of the condition is true, so the whole condition is true regardless of the second part
}

void bit_logical_diff_demo(void)
{
    int a = 1;
    int b = 2;
    if (a && b) // this evaluates to true because both a and b are non-zero
    {
        printf("Logical AND: a && b is true\n");
    }
    if (a & b) // this evaluates to false because the bitwise AND of 1 (0001) and 2 (0010) is 0 (0000)
    {
        printf("Bitwise AND: a & b is true\n");
    }

    a = 3;
    int c = a & b; // this evaluates to 2 because the bitwise AND of 3 (0011) and 2 (0010) is 2 (0010)
    printf("Bitwise AND: a & b = %d\n", c);
    c = a && b; // this evaluates to true (1) because both a and b are non-zero
    printf("Logical AND: a && b = %d\n", c);
}

int main(void)
{
    logical_shortcut_demo();
    bit_logical_diff_demo();
    return 0;
}