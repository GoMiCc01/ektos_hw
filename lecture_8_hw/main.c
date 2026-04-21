#include <stdio.h>
#include <stdint.h>

extern void (*fptr)(void); // Declare the function pointer defined in secondary.c
static uint8_t is_little_endian(void)
{
    uint16_t num = 0x1;
    uint8_t *ptr = (uint8_t *)&num;
    return (*ptr == 0x1);
}

static void pointer_convert_demo(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr; // Pointer to the first element of the array
    uint64_t var = (uint64_t)ptr;
    printf("Pointer value(address): %p\n", ptr);
    printf("Pointer value as uint64_t: %lu\n", var);
    printf("Pointer value as uint64_t (hex): 0x%llx\n", var);

    int *ptr2 = (int *)var; // Convert back to pointer
    printf("Pointer value after conversion back: %d\n", ptr2[0]);
}

static void pointert_math_demo(void) // Demonstates pointer arithmetic and address manipulation
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    printf("Pointer value: %d\n", *ptr);
    ptr++; // Move to the next element
    printf("Pointer value after increment: %d\n", *ptr);
    ptr--; // Move back to the previous element
    printf("Pointer value after decrement: %d\n", *ptr);
    ptr += 3; // Move forward by 3 elements
    printf("Pointer value after adding 3: %d\n", *ptr);
    int *ptr2 = arr;
    printf("Element difference ptr and ptr2: %ld\n", ptr - ptr2);

    uint64_t var = (uint64_t)ptr;
    printf("Pointer address: %p\n", ptr);
    printf("Pointer address if incremented: %p\n", ++ptr);
    var++;
    ptr = (int *)var; // Convert back to pointer after incrementing the address
    printf("Pointer address after incrementing variable and converting back: %p\n", ptr);
    printf("Pointer value after incrementing address: %d\n", *ptr); // Will output trash value since the address is not valid for the array anymore
}

int main(void)
{

    pointer_convert_demo();
    puts("==================================");
    pointert_math_demo();
    puts("==================================");
    if (is_little_endian())
    {
        printf("This system is little endian.\n");
    }
    else
    {
        printf("This system is big endian.\n");
    }
    fptr(); // Call the function through the function pointer
    return 0;
}