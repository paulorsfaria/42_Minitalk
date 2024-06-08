#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static unsigned char bit = 0b00000000; // Initialize bit to 0

void ft_print_bits(int i, int b)
{
	if (b == 1)
		bit |= (1 << i); // mete a 1
	else
		bit &= ~(1 << i); // nao mete a 1
	if (i == 0)
		printf("c = %c\n", bit);
}


void ft_send_bits(unsigned char bitter)
{
	int i = 8;
	while (i--)
	{
		if (bitter >> i & 1)
			ft_print_bits(i, 1);
		else
			ft_print_bits(i, 0);
	}
}


int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;

	printf("%d\n", getpid());
	ft_send_bits(argv[1][0]);
	ft_send_bits(argv[1][1]);
	ft_send_bits(argv[1][2]);

	return 0;
}
