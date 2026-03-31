#include <stdio.h>
#include <stdint.h>
#include <stdio.h>

static inline void separator(void)
{
    printf("==================================================================\n");
}

// task 2 ............................................................................

int8_t add_age(const int8_t arg)
{
    const int8_t MY_AGE = 21;
    return arg + MY_AGE;
}

void print_8bit_binary(int8_t n)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);
    }
}

void add_age_demo(void)
{
    int8_t testcases[] = {127, -1, 10, -128};
    for (int i = 0; i < 4; i++)
    {
        printf("Adding to %d my age(21) gives %d\n", testcases[i], add_age(testcases[i]));
        printf("Adding to ");
        print_8bit_binary(testcases[i]);
        printf(" my age(");
        print_8bit_binary((int8_t)21);
        printf(") gives ");
        print_8bit_binary(add_age(testcases[i]));
        printf("\n");
    }
}

// task 3 ............................................................................

uint8_t add_age_unsigned(const uint8_t arg)
{
    const uint8_t MY_AGE = 21;
    return arg + MY_AGE;
}

void add_age_demo_unsigned(void)
{
    uint8_t testcases[] = {127, 255, 10, 240};
    for (int i = 0; i < 4; i++)
    {
        printf("Adding to %d my age(21) gives %d\n", testcases[i], add_age_unsigned(testcases[i]));
        printf("Adding to ");
        print_8bit_binary(testcases[i]);
        printf(" my age(");
        print_8bit_binary((int8_t)21);
        printf(") gives ");
        print_8bit_binary(add_age_unsigned(testcases[i]));
        printf("\n");
    }
}

// task 1 ............................................................................
void print_binary_my_age(void)
{
    const int MY_AGE = 21;
    const int YEAR_OF_BIRTH = 2005;
    printf("MY AGE: %d , ", MY_AGE);
    print_8bit_binary(MY_AGE);
    printf("\n");
    printf("MY AGE NEGATIVE:  %d , ", -MY_AGE);
    print_8bit_binary(-MY_AGE);
    printf("\n");
    printf("YEAR OF BIRTH: %b, %d\n", YEAR_OF_BIRTH, YEAR_OF_BIRTH);
    printf("YEAR OF BIRTH NEGATIVE: %b, %d\n", -YEAR_OF_BIRTH, -YEAR_OF_BIRTH);
}

// task 4 ............................................................................
uint32_t setBit(uint32_t num, uint8_t bit_position)
{
    return num | (1U << bit_position);
}

uint32_t resetBit(uint32_t num, uint8_t bit_position)
{
    return num & ~(1U << bit_position);
}

void task4_demo(void)
{
    uint32_t num = 45;
    printf("Original number: %d\n", num);
    printf("Original number in binary: %b\n", num);
    num = setBit(num, 3);
    printf("After setting bit 3: %d\n", num);
    printf("After setting bit 3 in binary: %b\n", num);
    num = resetBit(num, 3);
    printf("After resetting bit 3: %d\n", num);
    printf("After resetting bit 3 in binary: %b\n", num);
}

// task 5 ............................................................................
void blinking_xor(void)
{
    uint8_t led_state = 0;
    uint8_t mask = 1U;
    printf("Led state: %d\n", led_state);
    for (int i = 0; i < 5; i++)
    {
        led_state ^= mask;
        printf("After XOR iteration %d: %d\n", i + 1, led_state);
        printf("Led state in binary: ");
        print_8bit_binary(led_state);
        printf("\n");
    }
}

// task 6 ............................................................................

void shift_demo(void)
{
    int8_t num = 1;
    printf("Original number(signed): %d\n", num);
    printf("Original number in binary: ");
    print_8bit_binary(num);
    printf("\n");

    for (int i = 0; i < 7; i++)
    {
        num <<= 1;
        printf("After left shift by %d: %d , ", i + 1, num);
        print_8bit_binary(num);
        printf("\n");
    }
    for (int i = 0; i < 7; i++)
    {
        num >>= 1;
        printf("After right shift by %d: %d , ", i + 1, num);
        print_8bit_binary(num);
        printf("\n");
    }
    separator();

    uint8_t unum = 1;
    printf("Original number(unsigned): %u\n", unum);
    printf("Original number in binary: ");
    print_8bit_binary(unum);
    printf("\n");

    for (int i = 0; i < 7; i++)
    {
        unum <<= 1;
        printf("After left shift by %d: %u , ", i + 1, unum);
        print_8bit_binary(unum);
        printf("\n");
    }
    for (int i = 0; i < 7; i++)
    {
        unum >>= 1;
        printf("After right shift by %d: %u , ", i + 1, unum);
        print_8bit_binary(unum);
        printf("\n");
    }
}

int main(void)
{
    // Це завдання нам демонструє як формуються від'ємні числа а саме інверсія + 1
    print_binary_my_age();
    separator();
    // Це завдання нам демонструє як відбувається переповнення знакових чисел та як формуються від'ємні числа при цьому переповненні
    add_age_demo();
    separator();
    // Це завдання нам демонструє як відбувається переповнення беззнакових чисел
    add_age_demo_unsigned();
    separator();
    // Це завдання нам демонструє як встановити та скинути певний біт у числі за допомогою маски
    task4_demo();
    separator();
    // Це завдання нам демонструє як за допомогою операції XOR можна змінювати стан певного біта наприклад для керування світлодіодом
    blinking_xor();
    separator();
    // Це завдання нам демонструє як працюють операції зсуву вліво та вправо для знакових та беззнакових чисел
    shift_demo();
    return 0;
}