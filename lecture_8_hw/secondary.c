#include <stdio.h>

static void some_static_function(void)
{
    puts("This is a static function in secondary.c");
}

void (*fptr)(void) = some_static_function; // Function pointer to the static function