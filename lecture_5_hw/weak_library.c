#include <stdio.h>

__attribute__((weak)) void log_message(const char *message)
{
    printf("Default Log: %s\n", message);
}