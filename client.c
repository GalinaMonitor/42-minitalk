#include "minitalk.h"

void ft_crypt(int byte, int pid)
{
	int count = 0;
	while(count <= 7)
	{
		if (byte >> count & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		count++;
	}
}

void	ft_talkback(int sig)
{
	static int ack = 0;

	if (sig == SIGUSR1 && ack == 0)
	{
		write(1, "Connection started\n", 19);
		ack = 1;
	}
	else if (sig == SIGUSR1 && ack == 1)
	{
		write(1, "Connection closed\n", 18);
		ack = 0;
	}
	else if (sig == SIGUSR2 && ack == 1)
	{
		write(1, "Signal received\n", 16);
		ack = 1;
	}
}

int main(int argc, char **argv)
{
	int ind_letter;
	struct sigaction ack;
	int pid;

	ind_letter = 0;
	ack.sa_flags = SA_RESTART;

	ack.sa_handler = ft_talkback;
	sigemptyset(&ack.sa_mask);
	sigaddset(&ack.sa_mask, SIGUSR1);
	sigaddset(&ack.sa_mask, SIGUSR2);

	sigaction(SIGUSR1, &ack, 0);
	sigaction(SIGUSR2, &ack, 0);

	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		write(1, "Wrong input", 11);
		return 1;
	}
	ft_crypt(0, pid);
	while (argv[2][ind_letter] != '\0')
	{
		ft_crypt(argv[2][ind_letter], pid);
		ind_letter++;
	}
	ft_crypt(0, pid);
	return 0;
}
