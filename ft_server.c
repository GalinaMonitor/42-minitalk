#include "ft_minitalk.h"

void ft_crypt(int byte, char *argv)
{
	int number = atoi(argv);
	printf("qqq = %d\n", number);
	int count = 0;
	while(count <= 7)
	{

		if (byte >> count & 1)
		{
			kill(number, SIGUSR1);
			printf ("BIT = 1\n");
		}
		else
		{
			kill(number, SIGUSR2);
			printf ("BIT = 0\n");
		}
		usleep(200);
		count++;
	}
}

int main(int argc, char **argv)
{
	char *str = "LOVE KATYA <3 ";
	while (*str)
	{
		ft_crypt(*str, argv[1]);
		str++;
	}
	return 0;
}
