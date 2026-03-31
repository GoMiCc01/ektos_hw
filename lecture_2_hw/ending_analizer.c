#include <stdio.h>
#include <stdint.h>

int main()
{
	printf("Enter some hexademical number:\n");
	unsigned int user_input;
	scanf("%x", &user_input);
	uint8_t *p = (uint8_t *)&user_input;
	printf("number in decimal - %d, address -  %p\n", user_input, p);
	printf("next byte? - %p", p + 1);
	unsigned int *b = &user_input;
	b++;
	printf("   4 bytes next? - %p\n", b);
	for (int i = 0; i < 4; i++)
	{
		printf("first byte - %x ", *(p + i));
		printf("adress of byte - %p\n", p + i);
	}
	if ((*p) == (user_input & 0xFF))
	{
		printf("This is a little endian system\n");
	}
	else
	{
		printf("This is not a little endian system\n");
	}
	return 0;
}
