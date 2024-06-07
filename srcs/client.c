#include <stdio.h>

static unsigned char bit = 0b00000000; // Initialize bit to 0

void ft_send_bits(int i, int b)
{
	// Set or clear the bit at position i
	if (b == 1)
		bit |= (1 << i); // mete a 1
	else
		bit &= ~(1 << i); // nao mete a 1
	if (i == 0)
		printf("c = %c\n", bit);
}

void ft_print_bits(unsigned char bitter)
{
	int i = 8;
	while (i--)
	{
		if (bitter >> i & 1)
			ft_send_bits(i, 1);
		else
			ft_send_bits(i, 0);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s <character>\n", argv[0]);
		return 1;
	}

	printf("\n");
	ft_print_bits(argv[1][0]);
	return 0;
}
