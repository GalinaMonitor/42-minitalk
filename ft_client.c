#include "ft_minitalk.h"






volatile int byte = 0;
volatile int count = 0;

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_decrypt(int i)
{

	if (i == SIGUSR1)
		byte |= 0b00000001 << count;
	count++;
}

int main()
{
	struct sigaction decrypt;
	struct sigaction old_decrypt;
	decrypt.sa_handler = ft_decrypt;

	sigemptyset(&decrypt.sa_mask);
	sigemptyset(&old_decrypt.sa_mask);

	decrypt.sa_flags = SA_RESTART;
	old_decrypt.sa_flags = SA_RESTART;


	printf("My pid is %i\n", getpid());
	printf("Waiting...\n");

	sigaddset(&decrypt.sa_mask, SIGUSR1);
	sigaddset(&decrypt.sa_mask, SIGUSR2);

	sigaddset(&old_decrypt.sa_mask, SIGUSR1);
	sigaddset(&old_decrypt.sa_mask, SIGUSR2);
	while(1)
	{
		// sigaction(SIGUSR1, &old_decrypt, &decrypt);
		// sigaction(SIGUSR2, &old_decrypt, &decrypt);
		if (count >= 8)
		{
			ft_putchar_fd(byte, 1);
			count = 0;
			byte = 0;
		}
		sigaction(SIGUSR1, &decrypt, &old_decrypt);
		sigaction(SIGUSR2, &decrypt, &old_decrypt);
	}
	return EXIT_FAILURE;
}
