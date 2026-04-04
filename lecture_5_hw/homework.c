#include <string.h>
#include <stdio.h>

static void strncpy_demo(void)
{
    char model[5];
    strncpy(model, "Pixel", 5); // Not adding null terminator, as the source string is longer than the destination buffer
    puts("Strncpy test , correct output: Pixel");
    printf("The model: %s\n\n", model); // Will print symbols till the first null character, which is after Pixel
}

static void strncat_demo(void)
{
    char model[6] = "Pixel";
    char letter = 'T';
    printf("Letter value: %c\n", letter);
    strncat(model, "6a", 2); // Overwrites variable letter, as the destination buffer is not large enough to hold the string and the null terminator
    puts("Strncat test , correct output: Pixel6a");
    printf("The model: %s\n", model);
    printf("Overwritten letter value: %c\n", letter);
}

void log_message(const char *message); // Declaration of the weak function, which can be overridden by a strong definition

// void log_message(const char *message)
// {
//     printf("Custom Log: %s\n", message);
// }

/*If the weak function is not overridden, it will call the default implementation in weak_library.c.
If a strong definition is provided, it will call that instead.*/

int main(void)
{
    strncpy_demo();
    strncat_demo();
    log_message("This is a test message.");
    return 0;
}