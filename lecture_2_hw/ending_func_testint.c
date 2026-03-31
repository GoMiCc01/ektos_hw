#include <arpa/inet.h>
#include <stdio.h>

int main()
{
    unsigned int num = 0x12345678;
    unsigned int converted_num = htonl(num);
    printf("Original number: 0x%x\n", num);
    printf("Converted number (network byte order): 0x%x\n", converted_num);
    return 0;
}
