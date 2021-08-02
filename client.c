#include "minitalk.h"

void ft_crypt(int byte, char *argv)
{
	int number = ft_atoi(argv);
	int count = 0;
	while(count <= 7)
	{
		if (byte >> count & 1)
			kill(number, SIGUSR1);
		else
			kill(number, SIGUSR2);
		usleep(100);
		count++;
	}
}

void	ft_talkback(int sig)
{
	write(1, "Signal received", 15);
}

int main(int argc, char **argv)
{
	int ind;
	struct sigaction ack;
	ind = 0;
	ack.sa_flags = SA_RESTART;

	ack.sa_handler = ft_talkback;
	sigaddset(&ack.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &ack, 0);
	sigemptyset(&ack.sa_mask);

	if (argc != 3)
	{
		write(1, "Wrong input", 11);
		return 1;
	}
	while (argv[2][ind] != '\0')
	{
		ft_crypt(argv[2][ind], argv[1]);
		ind++;
	}
	ft_crypt(0, argv[1]);
	return 0;
}
